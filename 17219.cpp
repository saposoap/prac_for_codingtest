#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, ask;
	string val, key;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ask;
		
		unordered_multimap<string, string> map1;
		unordered_map<string, int> map2;

		for (int j = 0; j < ask; j++) {
			cin >> val >> key;
			//멀티맵을 사용해서 key로 대분류, val에 값을 넣는다.
			map1.insert({ key, val });

			//map2에서 대분류 아이템 검색
			auto it = map2.find(key);
			//있으면 대분류 아이템 갯수 1증가
			if (it != map2.end()) {
				it->second++;
			}
			//없으면 대분류 아이템 1개부터 시작
			else {
				map2.insert({ key, 1 });
			}
		}

		int sum = 1;
		// 갯수 구하는 공식
		// Ex)a=1, b=2, c=3 이면 (1+1)*(2+1)*(3+1)이 되어야함.
		for (auto elem : map2) {
			sum *= (elem.second + 1);
		}
		//마지막에 공집합 빼기
		cout << sum - 1 << endl;
	}
		
	return 0;
}