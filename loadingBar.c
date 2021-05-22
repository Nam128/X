#include "team.h"

int loadingBar() {
	const char bar = '=';
	const char blank = ' ';
	const int LEN = 20;
	const int MAX = 500;
	const int SPEED = 3;
	int count = 0;
	int i;
	float tick = (float)100 / LEN;
	printf("**********************************************************\n");
	printf("모험을 떠나던 중 야생의 몬스터가 나타났다!\n");
	printf("알파벳을 알맞게 따라 입력하면 몬스터를 공격할 수 있다! \n"
		"몬스터를 공격해 몬스터의 HP를 0으로 만들어 승리하자.\n");
	printf("문자열을 연속으로 정확하게 입력하면 데미지가 더욱 세지며, \n몬스터를 물리치면 더 강한 몬스터가 나온다!\n");
	printf("**********************************************************\n");
	// printf("%0.2f%%마다 bar 1개 출력 \n\n", tick);
	int bar_count;
	float percent;
	while (count <= MAX) {
		printf("\r%d/%d [", count, MAX);
		percent = (float)count / MAX * 100;
		bar_count = percent / tick;
		for (i = 0; i < LEN; i++) {
			if (bar_count > i) {
				printf("%c", bar);
			}
			else {
				printf("%c", blank);
			}
		}
		printf("] %0.2f%%", percent);
		count++;
		Sleep(SPEED);
	}
	printf(" done!\n\n");
	system("pause");
	return 0;
}