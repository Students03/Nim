#include "Button.h"
#include "graphics.h"

Button::Button() {
	// настраиваем кнопки по умолчанию
	Button::set_exit_style(LIGHTGRAY, LIGHTMAGENTA, LIGHTCYAN);
	Button::set_pause_style(LIGHTGRAY, LIGHTMAGENTA, LIGHTCYAN);
	Button::set_exit_loc_size(0, 0, 40, 40);
	Button::set_pause_loc_size(43, 0, 40, 40);
}

void Button::set_exit_style(int color_line, int color_norm_fill, int color_abnorm_fill) {
	Button::exit.style.color_line = color_line;
	Button::exit.style.color_norm_fill = color_norm_fill;
	Button::exit.style.color_abnorm_fill = color_abnorm_fill;
}
void Button::set_exit_loc_size(int left, int top, int sizeX, int sizeY) {
	Button::exit.loc_size.left = left;
	Button::exit.loc_size.top = top;
	Button::exit.loc_size.right = left + sizeX;
	Button::exit.loc_size.bottom = top + sizeY;
}
bool Button::draw_exit(int mx, int my, bool flag_click) {
	bool if_click = Button::set_fill_color_and_return_true_if_click(mx, my, Button::exit, flag_click);
	if (if_click)
		return true;
	setlinestyle(0, 0, 2);
	setcolor(Button::exit.style.color_line);
	rectangle(Button::exit.loc_size.left, Button::exit.loc_size.top, Button::exit.loc_size.right, Button::exit.loc_size.bottom);
	line(Button::exit.loc_size.left + 5, Button::exit.loc_size.top + 5, Button::exit.loc_size.right - 5, Button::exit.loc_size.bottom - 5);
	line(Button::exit.loc_size.right - 5, Button::exit.loc_size.top + 5, Button::exit.loc_size.left + 5, Button::exit.loc_size.bottom - 5);
	floodfill(Button::exit.loc_size.left + 2, Button::exit.loc_size.top + 2, Button::exit.style.color_line);
	return false;
}


void Button::set_pause_style(int color_line, int color_norm_fill, int color_abnorm_fill) {
	Button::pause.style.color_line = color_line;
	Button::pause.style.color_norm_fill = color_norm_fill;
	Button::pause.style.color_abnorm_fill = color_abnorm_fill;
}
void Button::set_pause_loc_size(int left, int top, int sizeX, int sizeY) {
	Button::pause.loc_size.left = left;
	Button::pause.loc_size.top = top;
	Button::pause.loc_size.right = left + sizeX;
	Button::pause.loc_size.bottom = top + sizeY;
}
bool Button::draw_pause(int mx, int my, bool flag_click) {
	bool if_click = Button::set_fill_color_and_return_true_if_click(mx, my, Button::pause, flag_click);
	if (if_click)
		return true;
	setlinestyle(0, 0, 2);
	setcolor(Button::pause.style.color_line);
	rectangle(Button::pause.loc_size.left, Button::pause.loc_size.top, Button::pause.loc_size.right, Button::pause.loc_size.bottom);
	line(Button::pause.loc_size.left + 15, Button::pause.loc_size.top + 7, Button::pause.loc_size.left + 15, Button::pause.loc_size.bottom - 7);
	line(Button::pause.loc_size.right - 15, Button::pause.loc_size.top + 7, Button::pause.loc_size.right - 15, Button::pause.loc_size.bottom - 7);
	floodfill(Button::pause.loc_size.left + 2, Button::pause.loc_size.top + 2, Button::pause.style.color_line);
	return false;
}


bool Button::set_fill_color_and_return_true_if_click(int mx, int my, Button::type_button button, bool flag_click) {
	if (mx > button.loc_size.left && mx < button.loc_size.right &&
		my > button.loc_size.top && my < button.loc_size.bottom) {
		if (flag_click)
			return true;
		setfillstyle(1, button.style.color_abnorm_fill);
	}
	else
		setfillstyle(1, button.style.color_norm_fill);
	return false;
}


Button::~Button() {}
