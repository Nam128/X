#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define EASY_SIZE 4
#define EASY_TIME_LIMIT 6
#define NORMAL_SIZE 5
#define NORMAL_TIME_LIMIT 4
#define HARD_SIZE 6
#define HARD_TIME_LIMIT 2
#define MONSTER1 30
#define MONSTER2 70
#define MONSTER3 100

extern int myHP;
extern int total;
extern int monsterNum;
extern int comboMax;
extern int esc;

enum {
	black,
	blue,
	green,
	red,
	white
};
void chooseDifficulty();
void setColor(int, int);
int normalMode();
int easyMode();
int hardMode();