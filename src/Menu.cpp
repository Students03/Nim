#include "Menu.h"
#include "graphics.h"

extern int X_max;
extern int Y_max;

Menu::Menu() {

}

void Menu::draw_fon(int color) {
	setfillstyle(1, color);
	bar(0, 0, X_max, Y_max);
}

void Menu::make_headline(char* str, int size_char) {
	settextstyle(Menu::font_text, 0, size_char);
	Menu::fill_coord_str_for_out(str, Menu::start_Y_of_headline);
	outtextxy(Menu::coord_name_game.x, Menu::coord_name_game.y, str);
}

void Menu::fill_coord_str_for_out(char* str, int Y_pos_for_outtext) {
	Menu::coord_name_game.x = find_coorX_for_str(str);
	Menu::coord_name_game.y = Y_pos_for_outtext;
}

int Menu::find_coorX_for_str(char* str) {
	return (X_max - textwidth(str)) / 2;
}

int Menu::draw_body_of_menu(char ** array_for_item_of_menu, bool flag_click) {
	int mx = mousex();
	int my = mousey();
	for (int i = 0; i < Menu::num_of_item_menu; i++) {
		setcolor(Menu::determine_color_text(mx, my, i));
		outtextxy(Menu::ar_coord_menu[i].left_top.x, Menu::ar_coord_menu[i].left_top.y, array_for_item_of_menu[i]);
		if (if_in_area(ar_coord_menu[i], mx, my))
			if(flag_click)
				return i;
	}
	return -1;//!!!!!!!!!!!!!!!!!!!!!!!!!
}

int Menu::determine_color_text(int mx, int my, int i) {
	if (Menu::if_in_area(Menu::ar_coord_menu[i], mx, my))
		return Menu::color_abnorm_item_menu;
	else
		return Menu::color_norm_item_menu;
}

void Menu::fill_array_coord_menu(char** arr_str_menu) {
	int buff_Y_for_str = Menu::start_Y_of_menu;
	for (int i = 0; i < Menu::num_of_item_menu; i++) 
		Menu::ar_coord_menu[i] = Menu::compute_coord_str_in_menu(arr_str_menu[i], buff_Y_for_str);
}

Menu::location Menu::compute_coord_str_in_menu(char* str_menu, int &buff) {
	Menu::location coor_str_in_menu;
	coor_str_in_menu.left_top = { Menu::find_coorX_for_str(str_menu), buff};
	coor_str_in_menu.right_bottom = Menu::compute_right_bottom(str_menu, coor_str_in_menu.left_top);
	buff += Menu::interval_between_str + textheight(str_menu);
	return coor_str_in_menu;
}

Menu::coordinate Menu::compute_right_bottom(char *str, Menu::coordinate left_top) {
	Menu::coordinate temp = { left_top.x + textwidth(str), left_top.y + textheight(str) };
	return temp;
}

int Menu::find_interval_between_str(int height_str) {
	int free_placeY = Y_max - Menu::start_Y_of_menu - Menu::finish_Y_of_menu;
	return (free_placeY - Menu::num_of_item_menu * height_str) / Menu::num_of_item_menu;
}

bool Menu::if_in_area(Menu::location pos_str, int mx, int my) {
	if ((mx > pos_str.left_top.x) && (mx < pos_str.right_bottom.x) &&
		(my > pos_str.left_top.y) && (my < pos_str.right_bottom.y))
		return true;
	return false;
}

Menu::~Menu() {

}
