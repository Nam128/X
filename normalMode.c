#include "team.h"
void show_string(char*);

int normalMode() {
    char word[NORMAL_SIZE], ch, input[NORMAL_SIZE]; // SIZE-1개의 글자가 들어감
    int s_time, j = 0, combo = 0, monster2 = MONSTER2;

    srand(time(0));
    printf("**********************************************************\n");
    printf("MONSTER'S HP:%d\n올바르게 입력하여 몬스터를 무찔러보자!\nMy HP:%d\n", monster2, myHP);
    printf("**********************************************************\n");
    Sleep(1000);
    show_string(word); // 임의의 문자열을 생성해서 word에 추가
    s_time = time(0);
    while (myHP && monster2) {
        // 시간 체크
        if (time(0) == s_time + NORMAL_TIME_LIMIT)
        {
            combo = 0; // 틀리면 콤보 초기화
            myHP -= 5; // 틀리면 체력 -5
            printf("\n틀렸어... 다시 도전해보자!\n콤보: %d\n", combo);
            Sleep(1000);
            system("cls");
            printf("**********************************************************\n");
            if (monster2 > MONSTER2 * 2 / 3)
                printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster2, myHP);
            else if (monster2 > MONSTER2 / 3)
                printf("MONSTER'S HP:%d \n굉장한데? 녀석이 당황하고 있어!\nMy HP:%d\n", monster2, myHP);
            else
                printf("MONSTER'S HP:%d \n이제 얼마 안 남았으니 힘을 내!\nMy HP:%d\n", monster2, myHP);
            printf("**********************************************************\n");
            show_string(word); // 새로운 문자 출력
            s_time = time(0);
            j = 0;
        }
        // 키 입력 처리
        if (_kbhit()) { // 키가 눌리면
            ch = _getch(); // ch에 저장
            if (ch == 27) {
                esc++;
                break;
            }
            if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
                printf("%c", ch); // getch에 입력한 것을 보여줌
                input[j] = ch;
                j++;
            }
            if (ch == '\b' && j > 0) {
                j--;
                system("cls");
                printf("**********************************************************\n");
                if (monster2 > MONSTER2 * 2 / 3)
                    printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster2, myHP);
                else if (monster2 > MONSTER2 / 3)
                    printf("MONSTER'S HP:%d \n굉장한데? 녀석이 당황하고 있어!\nMy HP:%d\n", monster2, myHP);
                else
                    printf("MONSTER'S HP:%d \n이제 얼마 안 남았으니 힘을 내!\nMy HP:%d\n", monster2, myHP);
                printf("**********************************************************\n");
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
                monster2 -= 6; // 맞추면 몬스터2의 체력 -6
                total += 10; // 맞추면 기본적으로 10점
                printf("\n맞췄어!\n콤보: %d\n", combo);
                if (comboMax < combo) comboMax = combo;
                if (combo >= 4) total += 6; // 4콤보 이상 시 6점 추가
                Sleep(1000); // 1초 쉼
            }
            else {
                combo = 0; // 틀리면 콤보 초기화
                myHP -= 5; // 틀리면 체력 -5
                printf("\n틀렸어... 다시 도전해보자!\n콤보: %d\n", combo);
                Sleep(1000);
            }
            system("cls");
            printf("**********************************************************\n");
            if (monster2 > MONSTER2 * 2 / 3)
                printf("MONSTER'S HP:%d\n\nMy HP:%d\n", monster2, myHP);
            else if (monster2 > MONSTER2 / 3)
                printf("MONSTER'S HP:%d \n굉장한데? 녀석이 당황하고 있어!\nMy HP:%d\n", monster2, myHP);
            else
                printf("MONSTER'S HP:%d \n이제 얼마 안 남았으니 힘을 내!\nMy HP:%d\n", monster2, myHP);
            printf("**********************************************************\n");
            if (myHP && monster2) show_string(word);
            if (monster2 <= 0) {
                system("cls");
                printf("**********************************************************\n");
                printf("굉장해! 몬스터를 물리쳤어! 이제 제일 강한 상대를 만나러 가보자!\n");
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
    printf("\a"); // 알림음 출력
}