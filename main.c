#include "team.h"

int myHP = 50;
int total = 0;
int monsterNum = 0;
int comboMax = 0;
int esc = 0;

int main() {
    int select; // �޴� �ʱ�ȭ
    do {
        if (!myHP) break; // ü�� 0�̸� ����
        esc = 0;
        printf("���� Ž���\n1) ���� ����!\n2) ���� ����\n3) ������\n�޴��� �����ϼ���:");
        scanf("%d", &select); // �޴� �Է� �ޱ�
        if (select == 1) {
            chooseDifficulty(); // 1) ����
        }
        else if (select == 2) {
            printf("���ݱ����� ������ 0�Դϴ�.\n"); // 2) ���� ����
        }
    } while (select != 3); // 3�� �Է��ϸ� �״�� ����, 1,2,3�� �ƴ� �ٸ� �� �Է��ϸ� �ٽ� ���
    printf("������ ����Ǿ����ϴ�. \n������ ���� HP�� %d�̰�, %d������ ���͸� �����̽��ϴ�!\n�ִ� %d�޺��� �����ϼ̽��ϴ�. ���� ������ %d�Դϴ�.", myHP, monsterNum, comboMax, total);
}