#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int N, i, num;
    
    vector <int> arr;
    vector <int> v = { 0 };

    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &num);
        arr.push_back(num);
    }

    for (i = 0; i < N; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
        }
        else {
            //v에 들어가는 원소들은 오름차순 되어있음. lower_bound로 이분탐색하여 적합한 위치에 들어간다.
            //갯수만 파악하기 때문에 중간 원소를 교체해도 기존 최대값을 갖는 오름차순 배열의 길이는 유지가 된다.
            v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
        }
    }
    
    printf("%d", v.size() - 1);

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