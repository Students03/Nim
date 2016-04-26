#include "graphics.h"

int X_max = 800;
int Y_max = 600;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	initwindow(X_max, Y_max, "Игра Ним", 200, 0);
	while (true) {

	}
	closegraph();
	return 0;
}