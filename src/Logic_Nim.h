#pragma once

class Logic_Nim
{
public:
	static const int num_of_bunches = 3;
	int max_num_of_stones = 10;
	int min_num_of_stones = 4;
	int chosen_bunch = -1;
	int chosen_stones = -1;
	int array_bunches[Logic_Nim::num_of_bunches];
	enum diffic
	{
		easy, hard
	};
	enum mode
	{
		bot_vs_player, player1_vs_player2
	};
	enum priority
	{
		bot, player, playe1, player2
	};
	mode game_mode;
	diffic difficulty;
	priority who_do_move;

	Logic_Nim();

	void fill_array_bunches();

	void sort_array_bunches();

	int nim_sum();

	void bot_choosing();

	int choose_bunch();

	int hard_choose_bunch_bot();

	int choose_stones();

	int hard_choose_stones_bot();

	void man_choosing(int num_of_chosen_bunch, int amount_of_chosen_stones);

	void swap_priority();

	~Logic_Nim();
};