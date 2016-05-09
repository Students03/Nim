#pragma once
#include "Logic_Nim.h"
bool draw_str_button(char * str, int posY_for_text);

bool set_bk_color_and_return_true_if_click(char * str, int posY_for_text);

void choose_difficulty(Logic_Nim & nim);

bool choose_mode(Logic_Nim & nim);

void draw_who_do_move(Logic_Nim & nim, int color_background, int color_text);

void draw_end(Logic_Nim &nim, int color_background);

void* get_image();

void put_image_and_free_mem(void * screen);

bool Pause();

void getstate__func__putstate(void (*function)());

bool getstate__func__putstate(bool(*function)());