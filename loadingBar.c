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
	printf("������ ������ �� �߻��� ���Ͱ� ��Ÿ����!\n");
	printf("���ĺ��� �˸°� ���� �Է��ϸ� ���͸� ������ �� �ִ�! \n"
		"���͸� ������ ������ HP�� 0���� ����� �¸�����.\n");
	printf("���ڿ��� �������� ��Ȯ�ϰ� �Է��ϸ� �������� ���� ������, \n���͸� ����ġ�� �� ���� ���Ͱ� ���´�!\n");
	printf("**********************************************************\n");
	// printf("%0.2f%%���� bar 1�� ��� \n\n", tick);
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