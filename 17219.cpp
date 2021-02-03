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
			//��Ƽ���� ����ؼ� key�� ��з�, val�� ���� �ִ´�.
			map1.insert({ key, val });

			//map2���� ��з� ������ �˻�
			auto it = map2.find(key);
			//������ ��з� ������ ���� 1����
			if (it != map2.end()) {
				it->second++;
			}
			//������ ��з� ������ 1������ ����
			else {
				map2.insert({ key, 1 });
			}
		}

		int sum = 1;
		// ���� ���ϴ� ����
		// Ex)a=1, b=2, c=3 �̸� (1+1)*(2+1)*(3+1)�� �Ǿ����.
		for (auto elem : map2) {
			sum *= (elem.second + 1);
		}
		//�������� ������ ����
		cout << sum - 1 << endl;
	}
		
	return 0;
}