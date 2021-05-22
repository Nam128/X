#include "team.h"
void show_string(char*);

int hardMode() {
    char word[HARD_SIZE], ch, input[HARD_SIZE]; // SIZE-1개의 글자가 들어감
    int s_time, j = 0, combo=0, monster3=MONSTER3;

    srand(time(0));
    show_string(word); // 임의의 문자열을 생성해서 word에 추가
    s_time = time(0);
    while (myHP&&monster3) {
        // 시간 체크
        if (time(0) == s_time + HARD_TIME_LIMIT) // 5초마다
        {
            system("cls");
            show_string(word); // 새로운 문자 출력
            s_time = time(0);
            j = 0;
        }
        // 키 입력 처리
        if (_kbhit()) { // 키가 눌리면
            ch = _getch(); // ch에 저장
            if (ch == 27) {
                esc++;
                break; // esc를 누르면 while 탈출
            }
            if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
                printf("%c", ch); // getch에 입력한 것을 보여줌
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
        if (j >= HARD_SIZE - 1) {
            input[HARD_SIZE - 1] = 0; // null
            if (!strcmp(word, input)) {
                combo++;
                monster3 -= 5; // 맞추면 몬스터1의 체력 -5
                total += 10; // 맞추면 기본적으로 10점
                printf("\n축하합니다.\n콤보: %d\n체력: %d\n몬스터 체력: %d", combo, myHP, monster3);
                if (comboMax < combo) comboMax = combo;
                if (combo >= 5) total += 5; // 5콤보 이상 시 5점 추가
                if (!monster3) monsterNum++;
                Sleep(1000); // 1초 쉼
            }
            else {
                combo = 0; // 틀리면 콤보 초기화
                myHP -= 5; // 틀리면 체력 -5
                printf("\n틀렸습니다.\n콤보: %d\n체력: %d\n몬스터 체력: %d", combo, myHP, monster3);
                Sleep(500);
            }
            system("cls");
            if (myHP && monster3) show_string(word);
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
            w[i] = 'a' + (rand() % 26); // +1 아님?
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