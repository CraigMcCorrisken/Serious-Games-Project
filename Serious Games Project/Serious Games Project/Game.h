#pragma once
#include <GL/glew.h>
#include <glut.h>
#include "PlaySound.h"
#include <Windows.h>
#include <mmsystem.h>
#include "WindowMaker.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stack>
#include "Cocktail.h"

using namespace std;
using namespace glm;

class Game
{
private:
	WindowMaker* window;
	Cocktail* cocktail = new Cocktail();

	bool mouseActive = false, leftPressed = false, rightPressed = false;	//used for mouse inputs
	int highScore, currentScore;
	int lives = 3;
	bool alive = true; bool win = false;
	
	
	ifstream infile;	//file which holds cocktail ingredients
	ofstream outFile;

	//used for labels
	TTF_Font* textFont;

	//array of Labels
	GLuint labels[5];
	GLuint textures[5];

	//Used by BASS library
	HSAMPLE* samples = new HSAMPLE[5];

	bool allowPlay = true;

	int x = 200, y = 100;

	POINT mousePos;

	int numChoice = 0;

public:
	Game game() 
	{
	
	}

	void init();
	void update(float dt);
	void mouseInput();
	void keyboard(unsigned char key, int x, int y);
	void ReshapeWindow(int weigth, int height);
	
	void draw();
	void drawString(void* font, float x, float y, string s);
	void drawAlive();
	void drawDead();
	void drawWin();

	void saveHighScore();
	void readHighscore();
};