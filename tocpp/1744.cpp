#include<iostream>
#include<queue>
#include<vector>

/*
큰 숫자로 곱하는게 최대
양수 큐 음수 큐 나누어 관리, 1은 바로 더하기 ,0은 한개이상 받으면 상관x
양수 - 큰 수부터 두개씩 묶어 곱
1 - 1 더하기
0 - 하나만 저장하고 남는 음수에 곱
음수 - 작은 수부터 두개씩 묶어 곱, 남는 하나는 0이 있으면 곱해 더함
*/

int main() {
	int n,input;
	int ans = 0;
	int zero = 1;
	int p;
	std::priority_queue<int> pq;
	std::priority_queue<int, std::vector<int>, std::greater<int>> nq;
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		std::cin >> input;
		if (input == 1) { ans++; }
		else if (input == 0) { zero = 0; }
		else if (input > 1) { pq.push(input); }
		else { nq.push(input); }
	}
	while (pq.size() > 1) {
		p = pq.top();
		pq.pop();
		ans += p * pq.top();
		pq.pop();
	}
	while (nq.size() > 1) {
		n = nq.top();
		nq.pop();
		ans += n * nq.top();
		nq.pop();
	}
	if (!pq.empty()) { ans += pq.top(); }
	if (!nq.empty()) { ans += zero * nq.top(); }
	std::cout << ans;
}