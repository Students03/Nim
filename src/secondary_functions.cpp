#include "graphics.h"
#include "Logic_Nim.h"
#include "secondary_functions.h"
extern int X_max;
extern int Y_max;

bool draw_str_button(char* str, int posY_for_text) {
	setcolor(RED);
	bool if_click = set_bk_color_and_return_true_if_click(str, posY_for_text);
	if (if_click)
		return true;
	outtextxy((X_max - textwidth(str)) / 2, posY_for_text, str);
	return false;
}

bool set_bk_color_and_return_true_if_click(char* str, int posY_for_text) {
	int mx = mousex(), my = mousey();
	if (mx > (X_max - textwidth(str)) / 2 && mx < (X_max - textwidth(str)) / 2 + textwidth(str) &&
		my > posY_for_text && my < posY_for_text + textheight(str)) {
		if (ismouseclick(WM_LBUTTONUP)) {
			clearmouseclick(WM_LBUTTONUP);
			return true;
		}
		setbkcolor(BLACK);
	}
	else
		setbkcolor(YELLOW);
	return false;
}

void choose_difficulty(Logic_Nim &nim){
	setfillstyle(1, LIGHTBLUE);
	setbkcolor(LIGHTBLUE);
	bar(0, 0, X_max, Y_max);
	settextstyle(10, 0, 5);
	setcolor(RED);
	outtextxy((X_max - textwidth("�������� ��������� ����")) / 2, 30, "�������� ��������� ����");
	settextstyle(10, 0, 4);
	setcolor(GREEN);
	while (true) {
		if (draw_str_button("������", 250)) {
			nim.difficulty = Logic_Nim::hard;
			return;
		}
		if (draw_str_button("�������", 350)) {
			nim.difficulty = Logic_Nim::easy;
			return;
		}
	}
}

bool choose_mode(Logic_Nim &nim) {
	setbkcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, X_max, Y_max);
	settextstyle(10, 0, 5);
	setcolor(RED);
	outtextxy((X_max - textwidth("�������� ����� ����")) / 2, 30, "�������� ����� ����");
	settextstyle(10, 0, 4);
	setcolor(GREEN);
	while (true) {
		if (draw_str_button("����� VS ���������", 250)) {
			nim.game_mode = Logic_Nim::bot_vs_player;
			nim.set_who_do_move(nim.player);
			return true;
		}
		if (draw_str_button("����� VS �����", 350)) {
			nim.game_mode = Logic_Nim::player1_vs_player2;
			nim.set_who_do_move(nim.player1);
			return false;
		}
	}
	return false;
}

void draw_who_do_move(Logic_Nim &nim, int color_background, int color_text) {
	settextstyle(10, 0, 4);
	setcolor(BLUE);
	setbkcolor(color_background);
	setfillstyle(1, color_background);
	char str[] = "����� ���������"; // �������� ������ ��� ��������, ��� ����������� ������� �������
	bar((X_max - textwidth(str)) / 2 - 1, 0, (X_max - textwidth(str)) / 2 + textwidth(str) + 1, textheight(str));
	switch (nim.who_do_move)
	{
	case Logic_Nim::bot:
		outtextxy((X_max - textwidth("����� ���������")) / 2, 0, "����� ���������");
		break;
	case Logic_Nim::player:
		outtextxy((X_max - textwidth("��� ���")) / 2, 0, "��� ���");
		break;
	case Logic_Nim::player1:
		outtextxy((X_max - textwidth("����� _ 1")) / 2, 0, "����� _ 1");
		break;
	case Logic_Nim::player2:
		outtextxy((X_max - textwidth("����� _ 2")) / 2, 0, "����� _ 2");
		break;
	default:
		break;
	}
}

void draw_end(Logic_Nim &nim, int color_background) {
	struct textsettingstype t;
	gettextsettings(&t);
	settextstyle(10, 0, 5);
	setbkcolor(color_background);
	switch (nim.who_do_move)
	{
	case Logic_Nim::bot:
		outtextxy((X_max - textwidth("�� ���������")) / 2, 200, "�� ���������");
		break;
	case Logic_Nim::player:
		outtextxy((X_max - textwidth("�� ��������")) / 2, 200, "�� ��������");
		break;
	case Logic_Nim::player1:
		outtextxy((X_max - textwidth("������� �����_1")) / 2, 200, "������� �����_1");
		break;
	case Logic_Nim::player2:
		outtextxy((X_max - textwidth("������� �����_2")) / 2, 200, "������� �����_2");
		break;
	default:
		break;
	}
	settextstyle(t.font, t.direction, t.charsize);
}

void get_textsettings(textsettingstype &t) {
	gettextsettings(&t);
}

void put_textsettings(textsettingstype &t) {
	settextstyle(t.font, t.direction, t.charsize);
}

void* get_image() {
	void* screen = malloc(imagesize(0, 0, X_max, Y_max));
	getimage(0, 0, X_max, Y_max, screen);
	return screen;
}

void put_image_and_free_mem(void* screen) {
	putimage(0, 0, screen, 0);
	free(screen);
}


void getstate__func__putstate(void (*function)()) {
	void *screen = get_image();
	textsettingstype textsettings;
	gettextsettings(&textsettings);
	linesettingstype lineinfo;
	getlinesettings(&lineinfo);
	int color_bk = getbkcolor();
	int color = getcolor();
	fillsettingstype fillsettings;
	getfillsettings(&fillsettings);

	(*function)();
	
	settextstyle(textsettings.font, textsettings.direction, textsettings.charsize);
	setlinestyle(lineinfo.linestyle, lineinfo.upattern, lineinfo.thickness);
	setbkcolor(color_bk);
	setcolor(color);
	setfillstyle(fillsettings.pattern, fillsettings.color);
	put_image_and_free_mem(screen);	
}
bool getstate__func__putstate(bool(*function)()) {
	void *screen = get_image();
	textsettingstype textsettings;
	gettextsettings(&textsettings);
	linesettingstype lineinfo;
	getlinesettings(&lineinfo);
	int color_bk = getbkcolor();
	int color = getcolor();
	fillsettingstype fillsettings;
	getfillsettings(&fillsettings);

	bool value = (*function)();

	settextstyle(textsettings.font, textsettings.direction, textsettings.charsize);
	setlinestyle(lineinfo.linestyle, lineinfo.upattern, lineinfo.thickness);
	setbkcolor(color_bk);
	setcolor(color);
	setfillstyle(fillsettings.pattern, fillsettings.color);
	put_image_and_free_mem(screen);
	return value;
}
