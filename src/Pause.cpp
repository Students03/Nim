#include "Menu.h"
#include <string.h>
#include "secondary_functions.h"
#include "graphics.h"

bool Pause() {
	char it_is_pause[] = "Пауза";
	const int num_of_item_menu = 5;
	bool flag_exit = false;
	bool flag_is_click = false;
	int number_of_func = -1;
	char* arr_str_menu[num_of_item_menu];
	for (int i = 0; i < num_of_item_menu; i++) {
		arr_str_menu[i] = new char[17];
	}
	strcpy(arr_str_menu[0], "Продолжить");
	strcpy(arr_str_menu[1], "Сохранить игру");
	strcpy(arr_str_menu[2], "Настройки");
	strcpy(arr_str_menu[3], "Правила игры");
	strcpy(arr_str_menu[4], "Выход в меню");
	Menu Pause_Menu(it_is_pause, arr_str_menu);
	for (int i = 0; i < num_of_item_menu; i++)
		delete[] arr_str_menu[i];

	Pause_Menu.draw_background();
	Pause_Menu.set_style_headline(BLACK, 5, 10);
	Pause_Menu.set_coord_start_headline(320, 30);
	Pause_Menu.draw_headline();
	Pause_Menu.set_style_body(GREEN, YELLOW, 4, 10);
	Pause_Menu.set_starting_settings_for_output_of_body(200, 150, 600, 500);
	while (!flag_exit) {
		flag_is_click = false;
		if (ismouseclick(WM_LBUTTONUP)) {
			clearmouseclick(WM_LBUTTONUP);
			flag_is_click = true;
		}
		number_of_func = Pause_Menu.draw_body(mousex(), mousey(), flag_is_click);
		switch (number_of_func)
		{
		case 0:
			/*Продолжить игру*/
			return false;
			//std::cout << " 0 ";
			break;
		case 1:
			/*Сохранить игру*/
			//std::cout << " 1 ";
			break;
		case 2:
			/*Настройки*/
			//std::cout << " 2 ";
			break;
		case 3:
			/*Правила игры*/
			//std::cout << " 3 ";
			break;
		case 4:
			/*Выход в главное меню*/
			return true;
		default:
			break;
		}
	}
}