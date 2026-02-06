#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

/*
pair로 1이 있는 부분 큐에 저장, i,j(위치), 날짜 가지는 튜플
BFS로 탐색
탐색 끝나고 전체 순회 - m*n번 검사
메모리 초과... 방문할 부분을 1로 만들지 않고 방문시 검사도 하지않아 중복 발생해 메모리 초과
-> 방문시 1인지 확인하고 1이라면 넘어가도록 검사 시행, 메모리 초과는 안되지만 실패 - 처음 부분엔 1로 시작이라 예외처리 필요
-> 방문할 부분 1로 만들고 담아 예외처리 없이 중복으로 큐에 담기지 않게 하여 통과, 연산수도 조금 더 줄어들듯
*/

bool check(const std::vector<std::vector<int>>& v, int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (v[i][j] == 0) { return false; }
		}
	}
	return true;
}

int main() {
	int m, n;
	std::queue<std::tuple<int, int, int>> q;
	std::cin >> m >> n;
	std::vector<std::vector<int>> tomato(n, std::vector<int>(m));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			std::cin >> tomato[i][j];
			if (tomato[i][j] == 1) { q.push(std::tuple<int, int, int>(i, j, 0)); }
		}
	}
	int ans = 0;
	int i, j, day;
	std::tuple<int, int, int> current;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		std::tie(i, j, day) = current;
		ans = day;
		if (i != 0 && tomato[i - 1][j] == 0) { tomato[i - 1][j] = 1; q.push(std::tuple<int, int, int>(i - 1, j, day + 1)); }
		if (i != n - 1 && tomato[i + 1][j] == 0) { tomato[i + 1][j] = 1;q.push(std::tuple<int, int, int>(i + 1, j, day + 1)); }
		if (j != 0 && tomato[i][j - 1] == 0) { tomato[i][j - 1] = 1;q.push(std::tuple<int, int, int>(i, j - 1, day + 1)); }
		if (j != m - 1 && tomato[i][j + 1] == 0) { tomato[i][j + 1] = 1;q.push(std::tuple<int, int, int>(i, j + 1, day + 1)); }
	}
	check(tomato, n, m) ? std::cout << ans : std::cout << -1;
}