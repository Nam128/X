#include "team.h"
void chooseDifficulty() {
    loadingBar();
    system("cls");
    int select=0, play1=0, play2=0, play3=0, i=0;
    do {
        if (!myHP||select==3||esc) break; // ü�� 0�̸� ����, select�� 3�̸� ����, ���� ���� esc ������ ����
        if (!i) {
            printf("**********************************************************\n");
            printf("1 �ʱ�\n2 �߱�\n3 ���\n4 ���� �޴��� ���ư���\n"); // ���̵� ��� ���� �̸��� ������ �� ��.
            printf("**********************************************************\n");
            printf("���̵�:");
            scanf("%d", &select); // �޴� �Է� �ޱ�
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
    } while (select != 4); // 4�� �Է��ϸ� �״�� ����, 1,2,3,4�� �ƴ� �ٸ� �� �Է��ϸ� �ٽ� ���
}