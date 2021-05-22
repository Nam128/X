#include "team.h"
void chooseDifficulty() {
    loadingBar();
    system("cls");
    int select=0, play1=0, play2=0, play3=0, i=0;
    do {
        if (!myHP||select==3||esc) break; // 체력 0이면 종료, select가 3이면 종료, 게임 도중 esc 누르면 종료
        if (!i) {
            printf("**********************************************************\n");
            printf("1 초급\n2 중급\n3 상급\n4 이전 메뉴로 돌아가기\n"); // 난이도 대신 몬스터 이름도 괜찮을 듯 함.
            printf("**********************************************************\n");
            printf("난이도:");
            scanf("%d", &select); // 메뉴 입력 받기
        }
        else select++;
        system("cls");
        if (select == 1) {
            easyMode();
            i++;
        }
        else if (select == 2) {
            normalMode();
            i++;
        }
        else if (select == 3) {
            hardMode();
            i++;
        }
    } while (select != 4); // 4를 입력하면 그대로 종료, 1,2,3,4가 아닌 다른 값 입력하면 다시 물어봄
}