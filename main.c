#include "team.h"

int myHP = 50;
int total = 0;
int monsterNum = 0;
int comboMax = 0;
int esc = 0;
int monster3 = MONSTER3;

int main() {
    int select; // 메뉴 초기화
    do {
        if (!myHP||monster3<=0) break; // 체력 0이면 종료
        printf("%d", monster3);
        esc = 0;
        printf("**********************************************************\n");
        printf("몬스터 탐험대\n1 게임 시작!\n2 게임을 잠시 멈추고 점수 보기\n3 끝내기\n");
        printf("**********************************************************\n");
        printf("메뉴:");
        scanf("%d", &select); // 메뉴 입력 받기
        if (select == 1) {
            system("cls");
            chooseDifficulty(); // 1) 게임
        }
        else if (select == 2) {
            system("cls");
            printf("**********************************************************\n");
            printf("지금까지의 점수는 %d입니다.\n", total); // 2) 점수 보기
            printf("**********************************************************\n");
            Sleep(3000);
            system("cls");
        }
    } while (select != 3); // 3를 입력하면 그대로 종료, 1,2,3가 아닌 다른 값 입력하면 다시 물어봄
    printf("**********************************************************\n");
    printf("게임이 종료되었습니다. \n용사님의 남은 HP는 %d이고, %d마리의 몬스터를 잡으셨습니다!\n최대 %d콤보를 성공하셨습니다. 최종 점수는 %d입니다.\n", myHP, monsterNum, comboMax, total);
    printf("**********************************************************\n");
}