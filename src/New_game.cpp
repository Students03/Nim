#include "Button.h"
#include "Logic_Nim.h"
#include "graphics.h"
#include "Bunches.h"
#include "secondary_functions.h"
#include <iostream>
extern int X_max;
extern int Y_max;

void New_game() {
	Bunches bun;
	Logic_Nim nim;
	Button butts;
	if(choose_mode(nim))
		choose_difficulty(nim);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, X_max, Y_max);
	bun.draw_razm();
	bun.set_form_figure(Bunches::trian);
	bun.draw_all(nim);
	draw_who_do_move(nim, LIGHTBLUE, RED);
	while (true) {
		if (butts.draw_exit())
			break;
		if (butts.draw_pause()) {
			/*Пауза*/
		}
		bun.set_mouse_click(false);
		butts.set_flag_click(false);
		if (ismouseclick(WM_LBUTTONUP)) {
			clearmouseclick(WM_LBUTTONUP);
			bun.set_mouse_click(true);
			butts.set_flag_click(true);
		}
		bun.draw_all(nim);
		if(butts.draw_makemove() && nim.chosen_bunch >= 0 && nim.chosen_bunch <= nim.num_of_bunches){
			bun.delete_chosing_stones(nim, LIGHTBLUE);
			nim.do_turn();
			if (nim.end_of_game()) {
				draw_end(nim, LIGHTBLUE);
				delay(1000);
					break;
			}
			nim.swap_priority();
			nim.set_num_chosen_bunch_stone(-1, -1);
			draw_who_do_move(nim, LIGHTBLUE, RED);
			if (nim.who_do_move == Logic_Nim::bot) {
				nim.bot_choosing();
				bun.draw_all(nim);
				delay(1500);
				bun.delete_chosing_stones(nim, LIGHTBLUE);
				nim.do_turn();
				if (nim.end_of_game()) {
					draw_end(nim, LIGHTBLUE);
					delay(1000);
					break;
				}
				nim.swap_priority();
				nim.set_num_chosen_bunch_stone(-1, -1);
				draw_who_do_move(nim, LIGHTBLUE, RED);
			}
		}
	}
}