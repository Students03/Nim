#pragma once
class Button
{
private:
	struct butt_style
	{
		int color_line;
		int color_norm_fill;
		int color_abnorm_fill;
	};
	struct locat_size
	{
		int left;
		int top;
		int right;
		int bottom;
	};
	struct type_button
	{
		butt_style style;
		locat_size loc_size;
	} exit, pause;

	bool set_fill_color_and_return_true_if_click(int mx, int my, Button::type_button button, bool flag_click);

public:
	Button();

	void set_exit_style(int color_line, int color_norm_fill, int color_abnorm_fill);
	void set_exit_loc_size(int left, int top, int sizeX, int sizeY);
	bool draw_exit(int mx, int my, bool flag_click);

	void set_pause_style(int color_line, int color_norm_fill, int color_abnorm_fill);
	void set_pause_loc_size(int left, int top, int sizeX, int sizeY);
	bool draw_pause(int mx, int my, bool flag_click);


	~Button();
};

