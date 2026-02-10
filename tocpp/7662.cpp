#include<iostream>
#include<set>

/*
pq두개쓰고 map으로 원소 관리하며 구현
삭제 1+추가된 최소/최대보다 작은 원소, 삽입 lgn, map 접근 lgn
multiset 이용해서 구현
lgn
stl 자료구조들 멤버와 구조 알면 쉽게 풀릴듯
*/

int main() {
	std::multiset<long long int> pq;
	int t,k;
	long long int m;
	char input;
	std::cin >> t;
	for (t;t > 0;--t) {
		pq.clear();
		std::cin >> k;
		for (k;k > 0;--k) {
			std::cin >> input >> m;
			if (input == 'I') {
				pq.insert(m);
			}
			else if (input == 'D') {
				if (pq.empty()) { continue; }
				if (m == 1) {
					pq.erase(std::prev(pq.end()));
				}
				else {
					pq.erase(pq.begin());
				}
			}
		}
		if (pq.empty()) { std::cout << "EMPTY"; }
		else {
			std::cout << *(pq.rbegin())<<' '<< *pq.begin();
		}
		if (t != 1) { std::cout << '\n'; }
	}
}