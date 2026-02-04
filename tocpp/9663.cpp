#include<iostream>
#include<vector>

/*
백트래킹
1행부터 n행까지 모든 열에 하나씩 넣어보기
promising 검사
벡터 전역변수로 사용
*/

std::vector<int> col;
int ans = 0;
int n;

bool promising(int current) {
	for (int row = 1;row < current; row++) {
		if (col[current] == col[row] || std::abs(col[current] - col[row]) == current - row) { return false; }
	}
	return true;
}

void nqueens(int current) {
	if (promising(current)) {
		if (current == n) { ans++; }
		else {
			for (int i = 1;i <= n;i++) {
				col[current + 1] = i;
				nqueens(current + 1);
			}
		}
	}
}

int main() {
	std::cin >> n;
	col = std::vector<int>(n + 1);
	nqueens(0);
	std::cout << ans;
}