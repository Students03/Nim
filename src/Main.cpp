#include "graphics.h"
#include "Menu.h"
#include <string.h>
#include <iostream>
int X_max = 800;
int Y_max = 600;

void qwer() {
	settextstyle(10, 0, 10);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {	
	char game_name[] = "Ним";
	const int num_of_item_menu = 5;
	bool flag_exit = false;
	bool flag_is_click = false;
	int mx, my, number_of_func = -1;
	char* arr_str_menu[num_of_item_menu];
	for (int i = 0; i < num_of_item_menu; i++) {
		arr_str_menu[i] = new char[17];
	}
	std::strcpy(arr_str_menu[0], "Новая игра");
	std::strcpy(arr_str_menu[1], "Продолжить игру");
	std::strcpy(arr_str_menu[2], "Настройки");
	std::strcpy(arr_str_menu[3], "Правила игры");
	std::strcpy(arr_str_menu[4], "Выход");
	
	initwindow(X_max, Y_max, "Игра Ним", 200, 0);
	Menu Main_Menu(game_name, arr_str_menu);
	for (int i = 0; i < num_of_item_menu; i++)
		delete[] arr_str_menu[i];

	Main_Menu.draw_background();
	Main_Menu.draw_headline();
	Main_Menu.set_style_body();
	while (!flag_exit) {
		mx = mousex();
		my = mousey();
		flag_is_click = false;
		if (ismouseclick(WM_LBUTTONDOWN)) {
			clearmouseclick(WM_LBUTTONDOWN);
			flag_is_click = true;
		}
		number_of_func = Main_Menu.draw_body(mx, my, flag_is_click);
		switch (number_of_func)
		{
		case 0:
			/*Новая игра*/
			std::cout << " 0 ";
			break;
		case 1:
			/*Продолжить игру*/
			std::cout << " 1 ";
			break;
		case 2:
			/*Настройки*/
			std::cout << " 2 ";
			break;
		case 3:
			/*Правила игры*/
			std::cout << " 3 ";
			break;
		case 4:
			/*Выход*/
			flag_exit = true;
			break;
		case -1:

			break;
		default:
			break;
		}
	}	
	closegraph();
	return 0;
}