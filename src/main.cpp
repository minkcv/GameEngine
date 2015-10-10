#include <SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include "gmath/matrix4.h"
#include "gmath/vector3.h"
#include "interactive/interactivemanager.h"

using namespace std;
using namespace gmath;
using namespace interactive;

bool fWasReleased = false;
int max_fps = 60;
int screen_width = 800;
int screen_height = 600;
string window_title = "SFML works!";
sf::Uint32 window_style = sf::Style::Default;
InteractiveManager* iManager;

void test()
{
	double matrixValues[4][4] =
	{
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 1, 2, 3},
			{4, 5, 6, 7}
	};

	//Matrix4<double>* mat = new Matrix4<double>(matrixValues); // example heap declaration
	Matrix4<double> mat1(matrixValues); // stack declaration
	Matrix4<double> mat2(mat1); // example of copy constructor
	Matrix4<double> mat3 = Matrix4<double>::mult(mat1, mat2);
	for(int itr = 0; itr < 4; itr++){
		for(int itr2 = 0; itr2 < 4; itr2++){
			printf("%f ", mat3.getValue(itr, itr2));
		}
		printf("\n");
	}

	Matrix4<double> mat4 = Matrix4<double>::mult(mat3, Matrix4<double>::transpose(Matrix4<double>::getIdentity()));
	printf("%f\n", mat4.getValue(0, 2));
	Vector3<int> v3(1, 2, 3);
}

int main()
{
//	test();
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	clock.restart();
	sf::Time tick = sf::milliseconds(64);

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(800, 600), window_title, sf::Style::Default, settings);
	window.setFramerateLimit(max_fps);
	iManager = new InteractiveManager(&window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if(event.type == sf::Event::Resized){
//				glViewport(0, 0, event.size.width, event.size.height);
			}

		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if(sf::Keyboard::isKeyPressed((sf::Keyboard::F))){
			if(fWasReleased){
				switch(window_style) {
				case sf::Style::Default:
					window_style = sf::Style::Fullscreen;
					break;
				case sf::Style::Fullscreen:
					window_style = sf::Style::None;
					break;
				case sf::Style::None:
					window_style = sf::Style::Default;
					break;
				}
				window.create(sf::VideoMode(screen_width, screen_height), window_title, window_style, settings);
			}
			fWasReleased = false;
		}
		else{
			fWasReleased = true;
		}

		elapsed = clock.getElapsedTime();
		if(elapsed > tick) {
			iManager->update(elapsed.asMilliseconds());
			clock.restart();
		}
		iManager->render();
		window.display();
	}
	delete iManager;
	return 0;
}
