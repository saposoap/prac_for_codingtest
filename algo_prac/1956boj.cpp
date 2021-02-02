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


    // 플로이드 알고리즘 수행. 각 점에서 다른점까지의 최솟값 구해진다.
    // 시작점과 도착점이 같은 경우 제외하기. INF를 -1로 놓고 해당되는 경로는 탐색할 필요없음.
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


    // a에서 b로 가고 b에서 a로 돌아올 수 있으면 사이클 확정. 최단 찾기.
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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.