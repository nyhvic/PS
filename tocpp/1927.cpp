#include<iostream>
#include<queue> 

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int>> pq;
	int command;
	while (n--) {
		std::cin >> command;
		if (command) { pq.push(command); }
		else {
			if (pq.empty()) { std::cout << 0; }
			else { std::cout << pq.top();pq.pop(); }
			if (n != 0) { std::cout << '\n'; }
		}
	}
}