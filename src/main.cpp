#include <SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include "gmath/matrix4.h"
#include "gmath/vector3.h"
#include "interactive/interactivemanager.h"
#include "gengine/configmanager.h"
#include "gengine/windowmanager.h"

using namespace std;
using namespace gmath;

bool fWasReleased = false;
int max_fps = 60;
int screen_width = 800;
int screen_height = 600;
string window_title = "SFML works!";
sf::Uint32 window_style = sf::Style::Default;
InteractiveManager* iManager;
WindowManager* wManager;

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

	ConfigManager::loadConfig();
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	clock.restart();
	sf::Time tick = sf::milliseconds(64);
	GameConfig gConfig = ConfigManager::getConfig();
	wManager = new WindowManager(iManager, gConfig);
	wManager->createWindow();
	iManager = new InteractiveManager(wManager->getWindow());
	while (wManager->windowIsOpen()) {
		wManager->manageEvents();

		elapsed = clock.getElapsedTime();
		if(elapsed > tick) {
			iManager->update(elapsed.asMilliseconds());
			clock.restart();
		}
		iManager->render();
		wManager->displayWindow();
	}
	delete iManager;
	delete wManager;
	return 0;
}
