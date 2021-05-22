#include "team.h"
void show_string(char*);

int easyMode() {
    char word[EASY_SIZE], ch, input[EASY_SIZE]; // SIZE-1���� ���ڰ� ��
    int s_time, j = 0, combo=0, monster1=MONSTER1;

    srand(time(0));
    printf("**********************************************************\n");
    printf("MONSTER'S HP:%d\n�ùٸ��� �Է��Ͽ� ���͸� ���񷯺���!\nMy HP:%d\n", monster1, myHP);
    printf("**********************************************************\n");
    Sleep(1000);
    show_string(word); // ������ ���ڿ��� �����ؼ� word�� �߰�
    s_time = time(0);
    while (myHP&&monster1) {
        // �ð� üũ
        if (time(0) == s_time + EASY_TIME_LIMIT)
        {
            combo = 0; // Ʋ���� �޺� �ʱ�ȭ
            myHP -= 5; // Ʋ���� ü�� -5
            printf("\nƲ�Ⱦ�... �ٽ� �����غ���!\n�޺�: %d\n", combo);
            Sleep(1000);
            system("cls");
            printf("**********************************************************\n");
            if (monster1 > MONSTER1 * 2 / 3)
                printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster1, myHP);
            else if (monster1 > MONSTER1 / 3)
                printf("MONSTER'S HP:%d \n�����ѵ�? �༮�� ��Ȳ�ϰ� �־�!\nMy HP:%d\n", monster1, myHP);
            else
                printf("MONSTER'S HP:%d \n���� �� �� �������� ���� ��!\nMy HP:%d\n", monster1, myHP);
            printf("**********************************************************\n");
            show_string(word); // ���ο� ���� ���
            s_time = time(0);
            j = 0;
        }
        // Ű �Է� ó��
        if (_kbhit()) { // Ű�� ������
            ch = _getch(); // ch�� ����
            if (ch == 27) {
                esc++;
                break; // esc�� ������ while Ż��
            }
            if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
                printf("%c", ch); // getch�� �Է��� ���� ������
                input[j] = ch;
                j++;
            }
            if (ch == '\b' && j > 0) {
                j--;
                system("cls");
                printf("**********************************************************\n");
                if (monster1 > MONSTER1 * 2 / 3)
                    printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster1, myHP);
                else if (monster1 > MONSTER1 / 3)
                    printf("MONSTER'S HP:%d \n�����ѵ�? �༮�� ��Ȳ�ϰ� �־�!\nMy HP:%d\n", monster1, myHP);
                else
                    printf("MONSTER'S HP:%d \n���� �� �� �������� ���� ��!\nMy HP:%d\n", monster1, myHP);
                printf("**********************************************************\n");
                printf("%s\n", word);
                for (int i = 0; i < j; i++) {
                    printf("%c", input[i]);
                }
            }
        }
        //
        if (j >= EASY_SIZE - 1) {
            input[EASY_SIZE - 1] = 0; // null
            if (!strcmp(word, input)) {
                combo++;
                monster1 -= 5; // ���߸� ����1�� ü�� -5
                total += 5; // ���߸� �⺻������ 5��
                printf("\n�����!\n�޺�: %d\n", combo);
                if (comboMax < combo) comboMax = combo;
                if (combo >= 3) total += 2; // 5�޺� �̻� �� 5�� �߰�
                Sleep(1000); // 1�� ��
            }
            else {
                combo = 0; // Ʋ���� �޺� �ʱ�ȭ
                myHP -= 5; // Ʋ���� ü�� -5
                printf("\nƲ�Ⱦ�... �ٽ� �����غ���!\n�޺�: %d\n", combo);
                Sleep(1000);
            }
            system("cls");
            printf("**********************************************************\n");
            if (monster1 > MONSTER1 * 2 / 3)
                printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster1, myHP);
            else if (monster1 > MONSTER1 / 3)
                printf("MONSTER'S HP:%d \n�����ѵ�? �༮�� ��Ȳ�ϰ� �־�!\nMy HP:%d\n", monster1, myHP);
            else
                printf("MONSTER'S HP:%d \n���� �� �� �������� ���� ��!\nMy HP:%d\n", monster1, myHP);
            printf("**********************************************************\n");
            if(myHP&&monster1) show_string(word);
            if (monster1 <= 0) {
                system("cls");
                printf("**********************************************************\n");
                printf("������! ���͸� �����ƾ�! ���� �� ���� ��븦 ������ ������!\n");
                printf("**********************************************************\n");
                monsterNum++;
                Sleep(3000);
                break;
            }
            s_time = time(0);
            j = 0;
        }
    }
}
void static show_string(char* w) {
    int i, letterCase;
    for (i = 0; i < EASY_SIZE - 1; i++) {
        letterCase = rand() % 2;
        switch (letterCase) {
        case 0:
            w[i] = 'a' + (rand() % 26);
            break;
        case 1:
            w[i] = 'A' + (rand() % 26);
            break;
        }
    }
    w[i] = 0;
   printf("%s\n", w);
    printf("\a"); // �˸��� ���
}