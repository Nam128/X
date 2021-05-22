#include "team.h"

int myHP = 50;
int total = 0;
int monsterNum = 0;
int comboMax = 0;
int esc = 0;

int main() {
    int select; // 메뉴 초기화
    do {
        if (!myHP) break; // 체력 0이면 종료
        esc = 0;
        printf("몬스터 탐험대\n1) 게임 시작!\n2) 점수 보기\n3) 끝내기\n메뉴를 선택하세요:");
        scanf("%d", &select); // 메뉴 입력 받기
        if (select == 1) {
            chooseDifficulty(); // 1) 게임
        }
        else if (select == 2) {
            printf("지금까지의 점수는 0입니다.\n"); // 2) 점수 보기
        }
    } while (select != 3); // 3를 입력하면 그대로 종료, 1,2,3가 아닌 다른 값 입력하면 다시 물어봄
    printf("게임이 종료되었습니다. \n용사님의 남은 HP는 %d이고, %d마리의 몬스터를 잡으셨습니다!\n최대 %d콤보를 성공하셨습니다. 최종 점수는 %d입니다.", myHP, monsterNum, comboMax, total);
}