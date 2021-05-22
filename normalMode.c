#include "team.h"
void show_string(char*);

int normalMode() {
    char word[NORMAL_SIZE], ch, input[NORMAL_SIZE]; // SIZE-1���� ���ڰ� ��
    int s_time, j = 0, combo=0, monster2=MONSTER2;

    srand(time(0));
    show_string(word); // ������ ���ڿ��� �����ؼ� word�� �߰�
    s_time = time(0);
    while (myHP&&monster2) {
        // �ð� üũ
        if (time(0) == s_time + NORMAL_TIME_LIMIT)
        {
            system("cls");
            show_string(word); // ���ο� ���� ���
            s_time = time(0);
            j = 0;
        }
        // Ű �Է� ó��
        if (_kbhit()) { // Ű�� ������
            ch = _getch(); // ch�� ����
            if (ch == 27) {
                esc++;
                break;
            }
            if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
                printf("%c", ch); // getch�� �Է��� ���� ������
                input[j] = ch;
                j++;
            }
            if (ch == '\b' && j > 0) {
                j--;
                system("cls");
                printf("%s\n", word);
                for (int i = 0; i < j; i++) {
                    printf("%c", input[i]);
                }
            }
        }
        //
        if (j >= NORMAL_SIZE - 1) {
            input[NORMAL_SIZE - 1] = 0; // null
            if (!strcmp(word, input)) {
                combo++;
                monster2 -= 5; // ���߸� ����1�� ü�� -5
                total += 10; // ���߸� �⺻������ 10��
                printf("\n�����մϴ�.\n�޺�: %d\nü��: %d\n���� ü��: %d", combo, myHP, monster2);
                if (comboMax < combo) comboMax = combo;
                if (combo >= 5) total += 5; // 5�޺� �̻� �� 5�� �߰�
                if (!monster2) monsterNum++;
                Sleep(1000); // 1�� ��
            }
            else {
                combo = 0; // Ʋ���� �޺� �ʱ�ȭ
                myHP -= 5; // Ʋ���� ü�� -5
                printf("\nƲ�Ƚ��ϴ�.\n�޺�: %d\nü��: %d\n���� ü��: %d", combo, myHP, monster2);
                Sleep(500);
            }
            system("cls");
            if (myHP && monster2) show_string(word);
            s_time = time(0);
            j = 0;
        }
    }
}
void static show_string(char* w) {
    int i, letterCase;
    for (i = 0; i < NORMAL_SIZE - 1; i++) {
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