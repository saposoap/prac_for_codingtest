#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

#define INF 2147483647
using namespace std;

int main()
{
    int n, m, i, start, end, fee;
    int map[100][100];

    // 초기화 and 입력
    for (i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            map[i][j] = INF;
    for (i = 0; i < 100; i++)
        map[i][i] = 0;
    scanf("%d\n", &n);
    scanf("%d\n", &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &start, &end, &fee);
        if( fee < map[start-1][end-1] )
            map[start - 1][end - 1] = fee;
    }
    //  초기화 and 입력 끝


    for (int l1 = 0; l1 < n; l1++) {
        for (int l2 = 0; l2 < n; l2++) {
            for (int l3 = 0; l3 < n; l3++) {
                if(map[l2][l1] != INF && map[l1][l3] != INF)
                    map[l2][l3] = min(map[l2][l3], map[l2][l1] + map[l1][l3]);
            }
        }
    }
    

    // 출력
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == INF)
                map[i][j] = 0;
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    // 출력 끝
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
