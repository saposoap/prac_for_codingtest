#include <string>
#include <algorithm>
#include <iostream>

#define INF -1
using namespace std;

int main()
{
    int map[402][402];
    int v, e, a, b, c;

    scanf("%d %d\n", &v, &e);

    for (int i = 0; i <= v; i++)
        for (int j = 0; j <= v; j++)
            map[i][j] = INF;

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }

    /*
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    */


    // �÷��̵� �˰��� ����. �� ������ �ٸ��������� �ּڰ� ��������.
    // �������� �������� ���� ��� �����ϱ�. INF�� -1�� ���� �ش�Ǵ� ��δ� Ž���� �ʿ����.
    for (a = 1; a <= v; a++) {
        for (b = 1; b <= v; b++) {
            if (b == a) continue;
            for (c = 1; c <= v; c++) {
                if (b == c) continue;
                if (a == c) continue;

                if (map[b][c] == INF) {
                    if (map[b][a] != INF && map[a][c] != INF)
                        map[b][c] = map[b][a] + map[a][c];
                }
                else {
                    if (map[b][a] != INF && map[a][c] != INF)
                        map[b][c] = min(map[b][c], map[b][a] + map[a][c]);
                }
            }
        }
    }


    // a���� b�� ���� b���� a�� ���ƿ� �� ������ ����Ŭ Ȯ��. �ִ� ã��.
    int mini = 10000000, tmp;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) continue;
            if (map[i][j] == INF || map[j][i] == INF) continue;
            tmp = map[i][j] + map[j][i];
            if (tmp < mini)
                mini = tmp;
        }
    }
    if (mini == 10000000)
        printf("-1");
    else
        printf("%d", mini);
    return 0;
}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.