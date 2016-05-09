#include "graphics.h"
#include "Menu.h"
#include "Button.h"
#include <string.h>
#include <iostream>
#include "func_for_menu.h"
#include "secondary_functions.h"
int X_max = 800;
int Y_max = 600;


int main()/*WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)*/ {	
	char game_name[] = "Ним";
	const int num_of_item_menu = 5;
	bool flag_exit = false;
	bool flag_is_click = false;
	int number_of_func = -1;
	char* arr_str_menu[num_of_item_menu];
	for (int i = 0; i < num_of_item_menu; i++) {
		arr_str_menu[i] = new char[17];
	}
	strcpy(arr_str_menu[0], "Новая игра");
	strcpy(arr_str_menu[1], "Продолжить игру");
	strcpy(arr_str_menu[2], "Настройки");
	strcpy(arr_str_menu[3], "Правила игры");
	strcpy(arr_str_menu[4], "Выход");
	
	initwindow(X_max, Y_max, "Игра Ним", 200, 0);
	Menu Main_Menu(game_name, arr_str_menu);
	for (int i = 0; i < num_of_item_menu; i++)
		delete[] arr_str_menu[i];

	Main_Menu.draw_background();
	Main_Menu.draw_headline();
	Main_Menu.set_style_body();
	while (!flag_exit) {
		flag_is_click = false;
		if (ismouseclick(WM_LBUTTONUP)) {
			clearmouseclick(WM_LBUTTONUP);
			flag_is_click = true;
		}
		number_of_func = Main_Menu.draw_body(mousex(), mousey(), flag_is_click);
		switch (number_of_func)
		{
		case 0:
			New_game();//getstate__func__putstate(array_func[0]);
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
		default:
			break;
		}
	}	
	closegraph();
	return 0;
}