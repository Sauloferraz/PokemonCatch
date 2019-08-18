/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:		10 Out 2012
// Atualiza��o:	11 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "BasicAI.h"
#include "Hud.h"

// -------------------------------------------------------------------------------

Player::Player()
{
	// inicializa controle
	gamepad = new Controller();
	gamepadOn = gamepad->Initialize();

	// configura��o do objeto
	sprite = new Sprite("Resources/CharStopped.png");
	bbox = new Circle(18.0f);
	speed = { 90.0f, 0.0f };
	MoveTo(game->CenterX(), game->CenterY());
	type = PLAYER;

	// configura��o do emissor de part�culas
	Emitter emitter;
	emitter.imgFile = "Resources/Poeira.png";	// arquivo de imagem
	emitter.angle = 270.0f;						// �ngulo base do emissor
	emitter.spread = 40;						// espalhamento em graus
	emitter.lifeTime = 0.25f;					// tempo de vida em segundos
	emitter.genTime = 0.10f;					// tempo entre gera��o de novas part�culas
	emitter.percToDim = 0.6f;					// desaparece ap�s 60% da vida
	emitter.minSpeed = 50.0f;					// velocidade m�nima das part�culas
	emitter.maxSpeed = 100.0f;					// velocidade m�xima das part�culas
	emitter.r = 1.0f;							// componente Red da part�cula 
	emitter.g = 1.0f;							// componente Green da part�cula 
	emitter.b = 1.0f;							// componente Blue da part�cula 
	emitter.a = 1.0f;							// transpar�ncia da part�cula

	// cria sistema de part�culas
	tail = new Particles(emitter);
	tailCount = 0;


	// diparo habilitado
	firingAngle = 0.0f;
	keysPressed = false;
	axisCtrl = true;
	keysCtrl = true;
	start = 0;
	timer.Start();
}

// -------------------------------------------------------------------------------

Player::~Player()
{
	delete sprite;
	delete bbox;
	delete tail;
	delete gamepad;
	delete ra;
}

// -------------------------------------------------------------------------------

bool Player::KeysTimed(bool pressed, float time)
{
	// se j� passou o tempo para o pr�ximo disparo
	if (keysCtrl)
	{
		// se h� qualquer seta pressionada
		if (pressed)
		{
			keysCtrl = false;
			start = timer.Stamp();
			return true;
		}
	}
	// sen�o aguarda o momento certo
	else if (timer.Elapsed(start, time))
	{
		keysCtrl = true;
	}

	// teclas n�o pressionadas ou tempo n�o atingido
	return false;
}

// -------------------------------------------------------------------------------

bool Player::AxisTimed(int axisX, int axisY, float time)
{
	// se j� passou o tempo para o pr�ximo disparo
	if (axisCtrl)
	{
		// a magnitude � a dist�ncia do eixo para o seu centro
		float magnitude = Vector::Distance(0, 0, float(gamepad->Axis(axisX)), float(gamepad->Axis(axisY)));

		// se h� qualquer movimento no eixo
		if (magnitude > 0)
		{
			axisCtrl = false;
			start = timer.Stamp();
			return true;
		}
	}
	// sen�o aguarda o momento certo para testar
	else if (timer.Elapsed(start, time))
	{
		axisCtrl = true;
	}

	// eixo n�o acionado ou tempo n�o atingido
	return false;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector&& v)
{
	// soma vetor movimento (v) ao vetor velocidade
	speed.Add(v);

	// limita velocidade m�xima
	if (speed.magnitude > 10.0f)
		speed.magnitude = 10.0f;
}

// -------------------------------------------------------------------------------

void Player::Update()
{
	// magnitude do vetor acelera��o
	float accel = 60.0f * gameTime;

	// -----------------
	// Controle
	// -----------------
	if (gamepadOn)
	{
		// atualiza estado das teclas e eixos do controle
		gamepad->UpdateState();

		// constr�i vetor com base na posi��o do anal�gico esquerdo
		float ang = Vector::Angle(0, 0, float(gamepad->Axis(AxisX)), float(gamepad->Axis(AxisY)));
		float mag = Vector::Distance(0, 0, gamepad->Axis(AxisX) / 250.0f, gamepad->Axis(AxisY) / 250.0f);

		// nenhuma dire��o selecionada
		if (mag == 0)
		{
			// se a velocidade estiver muita baixa
			if (speed.magnitude < 0.1)
			{
				// pare de se movimentar imediatamente
				speed.magnitude = 0.0f;
			}
			else
			{
				// some um vetor no sentido contr�rio para frear
				speed.magnitude = 0.0f;
			}
		}
		else
		{
			// movimente-se para a nova dire��o
			Move(Vector(ang, mag * gameTime));
		}

		// dispara m�ssil com o anal�gico direito

		if (AxisTimed(AxisRX, AxisRY, 0.400f))
		{
			float ang = Vector::Angle(0, 0, float(gamepad->Axis(AxisRX)), float(gamepad->Axis(AxisRY)));
			BasicAI::audio->Play(FIRE);
			BasicAI::scene->Add(new Missile(ang), STATIC);
		}
	}
	// -----------------
	// Teclado
	// -----------------
	else
	{
		// controla movimenta��o do jogador
		if (window->KeyDown('D') && window->KeyDown('W'))
			Move(Vector(45.0f, accel));
		else if (window->KeyDown('A') && window->KeyDown('W'))
			Move(Vector(135.0f, accel));
		else if (window->KeyDown('A') && window->KeyDown('S'))
			Move(Vector(225.0f, accel));
		else if (window->KeyDown('D') && window->KeyDown('S'))
			Move(Vector(315.0f, accel));
		else if (window->KeyDown('D'))
			Move(Vector(0.0f, accel));
		else if (window->KeyDown('A'))
			Move(Vector(180.0f, accel));
		else if (window->KeyDown('W'))
			Move(Vector(90.0f, accel));
		else if (window->KeyDown('S'))
			Move(Vector(270.0f, accel));
		else
			// se nenhuma tecla est� pressionada comece a frear
			if (speed.magnitude > 0.1f)
				Move(Vector(speed.angle + 180.0f, 5.0f * gameTime));
			else
				// velocidade muita baixa, n�o use soma vetorial, apenas pare
				speed.magnitude = 0.0f;

		// controla dire��o dos disparos
		if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_UP)) {
			keysPressed = true;
			firingAngle = 45.0f;
		}
		else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_UP)) {
			keysPressed = true;
			firingAngle = 135.0f;
		}
		else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_DOWN)) {
			keysPressed = true;
			firingAngle = 225.0f;
		}
		else if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_DOWN)) {
			keysPressed = true;
			firingAngle = 315.0f;
		}
		else if (window->KeyDown(VK_RIGHT)) {
			keysPressed = true;
			firingAngle = 0.0f;
		}
		else if (window->KeyDown(VK_LEFT)) {
			keysPressed = true;
			firingAngle = 180.0f;
		}
		else if (window->KeyDown(VK_UP)) {
			keysPressed = true;
			firingAngle = 90.0f;
		}
		else if (window->KeyDown(VK_DOWN)) {
			keysPressed = true;
			firingAngle = 270.0f;
		}
		else
		{
			keysPressed = false;
		}

		// dispara m�ssil
		if (KeysTimed(keysPressed, 0.150f))
		{
			BasicAI::audio->Play(FIRE);
			BasicAI::scene->Add(new Missile(firingAngle), STATIC);
		}
	}

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed.XCom() * 50.0f * gameTime, -speed.YCom() * 50.0f * gameTime);

	// atualiza calda do jogador
	tail->Generator().angle = speed.angle + 180;
	tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
	tail->Update(gameTime);

	Hud::particles -= tailCount;
	tailCount = tail->Size();
	Hud::particles += tailCount;

	// restringe a �rea do jogo
	if (x < 50)
		MoveTo(50, y);
	if (y < 50)
		MoveTo(x, 50);
	if (x > game->Width() - 50)
		MoveTo(game->Width() - 50, y);
	if (y > game->Height() - 50)
		MoveTo(x, game->Height() - 50);
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
	sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed.angle + 90.0f);
	if (speed.magnitude > 0) {
		tail->Draw(Layer::MIDBACK, 1.0f);
		ra->Draw(x, y, Layer::MIDDLE, 1.0f, -speed.angle + 90.0f);
		ra->NextFrame();
	}
}


// -------------------------------------------------------------------------------
