#include "graphics.h"
#include "Menu.h"
#include <string.h>
#include <iostream>
int X_max = 800;
int Y_max = 600;


int main()/*WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)*/ {
	char game_name[] = "Ним";
	const int num_of_item_menu = 5;
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
	Menu Main_Menu;
	Main_Menu.draw_fon(Main_Menu.color_fon);
	setcolor(Main_Menu.color_name);
	setbkcolor(Main_Menu.color_fon);
	Main_Menu.make_headline(game_name, 8);
	settextstyle(Main_Menu.font_text, 0, 5);
	Main_Menu.interval_between_str = Main_Menu.find_interval_between_str(textheight("Привет"));
	Main_Menu.fill_array_coord_menu(arr_str_menu);
	bool flag_click = false;
	bool flag_exit = false;
	int number_of_func = -1;
	while (!flag_exit) {
		flag_click = false;
		if (ismouseclick(WM_LBUTTONDOWN)) {
			clearmouseclick(WM_LBUTTONDOWN);
			flag_click = true;
		}
		number_of_func = Main_Menu.draw_body_of_menu(arr_str_menu, flag_click);
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
	for (int i = 0; i < num_of_item_menu; i++) {
		delete[] arr_str_menu[i];
	}
	return 0;
}