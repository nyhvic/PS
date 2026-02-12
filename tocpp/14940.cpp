#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

/*
출발지부터 너비우선 탐색 시행 (좌표), 길이 저장하는 큐 사용
7576 토마토와 유사, 임의 점부터 목표까지 최단거리 -> 시작점(목표)부터 임의 점까지의 최단거리로 바꾸어 BFS
*/

int main() {
	int n, m,sti,stj;
	std::cin >> n >> m;
	std::vector<std::vector<int>> map(n, std::vector<int>(m));
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m,false));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) { sti = i;stj = j; }
			if (map[i][j] == 0) { visited[i][j] = 1; }
		}
	}
	std::queue<std::tuple<int, int, int>> q;
	q.push({ sti,stj,0 });
	int i, j, len;
	while (!q.empty()) {
		auto [i, j, len] = q.front();
		q.pop();
		if (visited[i][j]) { continue; }
		visited[i][j] = true;
		map[i][j] = len;
		if (i != 0 && visited[i - 1][j] != 1) { q.push({ i - 1,j,len + 1 }); }
		if (i != n - 1 && visited[i + 1][j] != 1) { q.push({ i + 1,j,len + 1 }); }
		if (j != 0 && visited[i][j - 1] != 1) { q.push({ i, j - 1, len + 1 }); }
		if (j != m - 1 && visited[i][j + 1] != 1) { q.push({ i, j + 1, len + 1 }); }
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (visited[i][j]) {
				std::cout << map[i][j];
			}
			else { std::cout << -1; }
			if (j != m-1) { std::cout << ' '; }
		}
		if (i != n-1) { std::cout << '\n'; }
	}
}