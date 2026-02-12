#include<iostream>
#include<queue>
#include<cmath>

/*
pq에 pair로 절대값, 실제값 넣어 사용 or 비교 함수 사용
람다+decltype 써서 사용자 설정 비교함수 사용하는건 c++20부터란다..
struct + 연산자 이용해 구현
pair : 메모리 더쓰고 연산시간 줄어듦
비교함수 : 메모리 덜쓰고 연산시간 조금 생김
*/

struct cmp {
	bool operator() (const long long int& a, const long long int& b){
		if (std::abs(a) == std::abs(b)) { return a > b; }
		return std::abs(a) > std::abs(b);
	}
};

int main() {
	int n;
	std::cin >> n;
	std::priority_queue<long long int, std::vector<long long int>,cmp > pq;
	long long int command;
	for (int i = 0;i < n;i++) {
		std::cin >> command;
		if (command) {
			pq.push(command);
		}
		else {
			if (pq.empty()) {
				std::cout << 0;
			}
			else {
				std::cout << pq.top();
				pq.pop();
			}
			if (i != n) {
				std::cout << '\n';
			}
		}
	}
}