#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
int main() {
	RenderWindow window(VideoMode(800, 600), "Pong");

	Font font;
	font.loadFromFile("TimesNewRoman.ttf");
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(50, 10);
	scoreText.setString("Player 1: " + 0);

	int score = 0;

	Text scoreText2;
	scoreText2.setFont(font);
	scoreText2.setCharacterSize(24);
	scoreText2.setFillColor(Color::White);
	scoreText2.setPosition(650, 10);
	scoreText2.setString("Player 2: " + 0);

	int score2 = 0;

	RectangleShape leftPaddle(Vector2f(10, 100));
	leftPaddle.setPosition(10, 300);

	RectangleShape rightPaddle(Vector2f(10, 100));
	rightPaddle.setPosition(780, 300);

	CircleShape ball(10);
	ball.setPosition(400, 300);

	Vector2f ballVelocity(200, 200);

	Clock clock;

	while (window.isOpen()) { //GAME LOOP START #################################################################################################

		/*sf::Music music;
		music.openFromFile(".wav");
		music.play();*/

		/*SoundBuffer paddleHitBuffer;
		paddleHitBuffer.loadFromFile("birb.wav");
		Sound paddleHitSound(paddleHitBuffer);*/

		Time deltaTime = clock.restart();
		float dt = deltaTime.asSeconds();

		//Input
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		if (ball.getPosition().x <= leftPaddle.getPosition().x + 10 &&
			ball.getPosition().x + 20 >= leftPaddle.getPosition().x &&
			ball.getPosition().y + 20 >= leftPaddle.getPosition().y &&
			ball.getPosition().y <= leftPaddle.getPosition().y + 100) {
			ballVelocity.x = -ballVelocity.x;
		}

		if (ball.getPosition().x <= rightPaddle.getPosition().x + 10 &&
			ball.getPosition().x + 20 >= rightPaddle.getPosition().x &&
			ball.getPosition().y + 20 >= rightPaddle.getPosition().y &&
			ball.getPosition().y <= rightPaddle.getPosition().y + 100) {
			ballVelocity.x = -ballVelocity.x;
		}


		//Physics
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftPaddle.move(0, -400 * dt);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftPaddle.move(0, 400 * dt);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightPaddle.move(0, -400 * dt);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightPaddle.move(0, 400 * dt);
		}

		ball.move(ballVelocity * dt);

		if (ball.getPosition().y <= 0 || ball.getPosition().y + ball.getRadius() * 2 >= 600) {
			ballVelocity.y = -ballVelocity.y;
		}


		if (ball.getPosition().x <= 0) {
			ballVelocity.x = -ballVelocity.x;
			score2++;
			scoreText2.setString("Player 2: " + to_string(score2));
		}
		{	if (ball.getPosition().x + ball.getRadius() * 2 >= 800) {
			ballVelocity.x = -ballVelocity.x;
			score++;
			scoreText.setString("Player 1: " + to_string(score));
		}



		//Render
		window.clear();

		window.draw(leftPaddle);

		window.draw(rightPaddle);

		window.draw(ball);

		window.draw(scoreText);

		window.draw(scoreText2);

		window.display();

		}//GAME LOOP END ##########################################################################################################################

		

	}
	return 0;
}
