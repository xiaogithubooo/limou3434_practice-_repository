#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define SNAKE_MAX_LENGTH 100

int board[BOARD_HEIGHT][BOARD_WIDTH];
int snake[SNAKE_MAX_LENGTH][2];
int snake_length = 3;
enum Direction { UP, DOWN, LEFT, RIGHT };
enum Direction current_direction;

int score = 0;

void initialize_board() {
	int i, j;
	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			if (i == 0 || j == 0 || i == BOARD_HEIGHT - 1 || j == BOARD_WIDTH - 1) {
				board[i][j] = -1;
			}
			else {
				board[i][j] = 0;
			}
		}
	}
}

void print_board() {
	int i, j;
	system("cls");
	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			if (board[i][j] == -1) {
				printf("*");
			}
			else if (board[i][j] == 0) {
				printf(" ");
			}
			else if (board[i][j] == 1) {
				printf("*"); // 用 * 表示蛇身
			}
			else if (board[i][j] == 2) {
				printf("\033[31mF\033[0m"); // 红色的 F 表示食物
			}
		}
		printf("\n");
	}
	printf("Score: %d\n", score);
}

void generate_food() {
	int x, y;
	do {
		x = rand() % (BOARD_WIDTH - 2) + 1;
		y = rand() % (BOARD_HEIGHT - 2) + 1;
	} while (board[y][x] != 0);
	board[y][x] = 2;
}

void initialize_snake() {
	int i;
	for (i = 0; i < snake_length; i++) {
		snake[i][0] = BOARD_HEIGHT / 2;
		snake[i][1] = BOARD_WIDTH / 2 - i;
		board[snake[i][0]][snake[i][1]] = 1;
	}
	current_direction = RIGHT;
}

void move_snake() {
	int i;
	int tail_x = snake[snake_length - 1][1];
	int tail_y = snake[snake_length - 1][0];
	board[tail_y][tail_x] = 0;
	for (i = snake_length - 1; i > 0; i--) {
		snake[i][0] = snake[i - 1][0];
		snake[i][1] = snake[i - 1][1];
	}
	if (current_direction == UP) {
		snake[0][0]--;
	}
	else if (current_direction == DOWN) {
		snake[0][0]++;
	}
	else if (current_direction == LEFT) {
		snake[0][1]--;
	}
	else if (current_direction == RIGHT) {
		snake[0][1]++;
	}
	if (board[snake[0][0]][snake[0][1]] == 2) {
		snake_length++;
		generate_food();
		score += 10;
	}
	else if (board[snake[0][0]][snake[0][1]] == -1 || board[snake[0][0]][snake[0][1]] == 1) {
		exit(0); // 游戏结束
	}
	board[snake[0][0]][snake[0][1]] = 1;
}

void handle_input() {
	if (_kbhit()) {
		char ch = _getch();
		if (ch == 'w' || ch == 'W') {
			if (current_direction != DOWN) {
				current_direction = UP;
			}
		}
		else if (ch == 's' || ch == 'S') {
			if (current_direction != UP) {
				current_direction = DOWN;
			}
		}
		else if (ch == 'a' || ch == 'A') {
			if (current_direction != RIGHT) {
				current_direction = LEFT;
			}
		}
		else if (ch == 'd' || ch == 'D') {
			if (current_direction != LEFT) {
				current_direction = RIGHT;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	initialize_board();
	generate_food();
	initialize_snake();

	while (1) {
		print_board();
		handle_input();
		move_snake();
		Sleep(100);
	}
	return 0;
}