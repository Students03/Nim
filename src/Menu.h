#pragma once
#include "graphics.h"
class Menu
{
private:
	
public:
	int color_name = BLACK;
	int color_norm_item_menu = RED;
	int color_abnorm_item_menu = YELLOW;
	int color_fon = GREEN;
	int color_bk = GREEN;
	int font_text = 10;
	static const int num_of_item_menu = 5;
	int start_Y_of_headline = 20;
	int start_Y_of_menu = 140;
	int finish_Y_of_menu = 120;
	int interval_between_str = 20;
	struct coordinate
	{
		int x;
		int y;
	} coord_name_game;
	struct location
	{
		coordinate left_top;
		coordinate right_bottom;
	} ar_coord_menu[Menu::num_of_item_menu];
	
	Menu();

	void draw_fon(int color);

	void make_headline(char* str, int size_char);

	void fill_coord_str_for_out(char * str, int Y_pos_for_outtext);

	int find_coorX_for_str(char * str);

	int draw_body_of_menu(char ** array_for_item_of_menu, bool flag_click);

	int determine_color_text(int mx, int my, int i);

	void fill_array_coord_menu(char ** arr_str_menu);

	Menu::location compute_coord_str_in_menu(char * arr_str_menu, int & buff);

	Menu::coordinate compute_right_bottom(char * str, Menu::coordinate left_top);

	int find_interval_between_str(int height_str);

	bool if_in_area(Menu::location pos_str, int mx, int my);

	~Menu();
};