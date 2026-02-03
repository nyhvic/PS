#include<iostream>
#include<queue>
#include<vector>

/*
숫자 받기
pq에 넣기
두개씩 빼고 합쳐서 다시넣기
반복
*/


int main() {
	int n, deck;
	int ans = 0;
	std::priority_queue<int,std::vector<int>, std::greater<int>> cards;
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		std::cin >> deck;
		cards.push(deck);
	}
	int a, b;
	while (cards.size()>1) {
		a = cards.top();
		cards.pop();
		b = cards.top();
		cards.pop();
		ans += a + b;
		cards.push(a + b);
	}
	std::cout << ans;
}