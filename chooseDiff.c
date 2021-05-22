#include "team.h"
void chooseDifficulty() {
    int select=0, play1=0, play2=0, play3=0, i=0;
    do {
        if (!myHP||select==3||esc) break; // 체력 0이면 종료, select가 3이면 종료, 게임 도중 esc 누르면 종료
        if (!i) {
            printf("모험을 떠나던 중 야생의 몬스터가 나타났다!\n");
            printf("알파벳을 알맞게 따라 입력하고, 몬스터의 HP를 0으로 만들자!\n");
            printf("문자열을 연속으로 정확하게 입력하면 데미지가 더욱 세진다.\n");
            printf("1) 초급\n2) 중급\n3) 상급\n4) 이전 메뉴로 돌아가기\n난이도를 선택하세요:"); // 난이도 대신 몬스터 이름도 괜찮을 듯 함.
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