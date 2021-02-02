#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int N, i, j, max;
    int arr[1001];
    int maxcnt[1001]; //각 인덱스에서 가질수 있는 최대 증가순열의 크기
    
    // 입력, 초기화 시작
    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        maxcnt[i] = 0;
    }
    max = 0;
    // 입력, 초기화 끝

    // 배열의 처음부터 끝까지 각각 살펴본다
    for (int l1 = 0; l1 < N; l1++) {
        // idx l1 - 1부터 idx 0까지 살펴본다.
        for (int l2 = l1 - 1; -1 < l2; l2--) {
            // 증가순열이고
            if (arr[l2] < arr[l1]) {
                // 나의 값을 바꾸다 보면 최대값을 찾게된다.
                if( maxcnt[l2] >= maxcnt[l1])
                    // 나보다 크거나 같은 idx보다 무조건 1더 크다.
                    maxcnt[l1] = maxcnt[l2] + 1;
            }
        }

        if (maxcnt[l1] == 0)
            maxcnt[l1] = 1;
    }

    //제일 큰게 답
    for (i = 0; i < N; i++) {
        if (max < maxcnt[i])
            max = maxcnt[i];
    }

    //출력
    printf("%d", max);

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