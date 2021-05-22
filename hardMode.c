#include "team.h"
void show_string(char*);

int hardMode() {
    char word[HARD_SIZE], ch, input[HARD_SIZE]; // SIZE-1���� ���ڰ� ��
    int s_time, j = 0, combo = 0;

    srand(time(0));
    printf("**********************************************************\n");
    printf("MONSTER'S HP:%d\n�ùٸ��� �Է��Ͽ� ���͸� ���񷯺���!\nMy HP:%d\n", monster3, myHP);
    printf("**********************************************************\n");
    Sleep(1000);
    show_string(word); // ������ ���ڿ��� �����ؼ� word�� �߰�
    s_time = time(0);
    while (myHP && monster3) {
        // �ð� üũ
        if (time(0) == s_time + HARD_TIME_LIMIT) // 5�ʸ���
        {
            combo = 0; // Ʋ���� �޺� �ʱ�ȭ
            myHP -= 10; // Ʋ���� ü�� -10
            printf("\nƲ�Ⱦ�... �ٽ� �����غ���!\n�޺�: %d\n", combo);
            Sleep(1000);
            system("cls");
            printf("**********************************************************\n");
            if (monster3 > MONSTER3 * 2 / 3)
                printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster3, myHP);
            else if (monster3 > MONSTER3 / 3)
                printf("MONSTER'S HP:%d \n�����ѵ�? �༮�� ��Ȳ�ϰ� �־�!\nMy HP:%d\n", monster3, myHP);
            else
                printf("MONSTER'S HP:%d \n���� �� �� �������� ���� ��!\nMy HP:%d\n", monster3, myHP);
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
                if (monster3 > MONSTER3 * 2 / 3)
                    printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster3, myHP);
                else if (monster3 > MONSTER3 / 3)
                    printf("MONSTER'S HP:%d \n�����ѵ�? �༮�� ��Ȳ�ϰ� �־�!\nMy HP:%d\n", monster3, myHP);
                else
                    printf("MONSTER'S HP:%d \n���� �� �� �������� ���� ��!\nMy HP:%d\n", monster3, myHP);
                printf("**********************************************************\n");
                printf("%s\n", word);
                for (int i = 0; i < j; i++) {
                    printf("%c", input[i]);
                }
            }
        }
        //
        if (j >= HARD_SIZE - 1) {
            input[HARD_SIZE - 1] = 0; // null
            if (!strcmp(word, input)) {
                combo++;
                monster3 -= 8; // ���߸� ����1�� ü�� -8
                total += 15; // ���߸� �⺻������ 15��
                printf("\n�����!\n�޺�: %d\n", combo);
                if (comboMax < combo) comboMax = combo;
                if (combo >= 5) total += 10;
                if (!monster3) monsterNum++;
                Sleep(1000); // 1�� ��
            }
            else {
                combo = 0; // Ʋ���� �޺� �ʱ�ȭ
                myHP -= 10; // Ʋ���� ü�� -10
                printf("\nƲ�Ⱦ�... �ٽ� �����غ���!\n�޺�: %d\n", combo);
                Sleep(1000);
            }
            system("cls");
            printf("**********************************************************\n");
            if (monster3 > MONSTER3 * 2 / 3)
                printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster3, myHP);
            else if (monster3 > MONSTER3 / 3)
                printf("MONSTER'S HP:%d \n�����ѵ�? �༮�� ��Ȳ�ϰ� �־�!\nMy HP:%d\n", monster3, myHP);
            else
                printf("MONSTER'S HP:%d \n���� �� �� �������� ���� ��!\nMy HP:%d\n", monster3, myHP);
            printf("**********************************************************\n");
            if (myHP && monster3) show_string(word);
            if (monster3 <= 0) {
                system("cls");
                printf("**********************************************************\n");
                printf("������! ��� ���͸� �����ƾ�! \n");
                printf("**********************************************************\n");
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
    for (i = 0; i < HARD_SIZE - 1; i++) {
        letterCase = rand() % 2;
        switch (letterCase) {
        case 0:
            w[i] = 'a' + (rand() % 26); // +1 �ƴ�?
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