#include<iostream>

/*
dfs로 풀이, 1012와 유사, 그래프버전
인접 리스트 방식 사용하는게 훨 빠름.
*/

int arr[1001][1001];
int visited[1001];
int n;

void dfs(int x) {
	if (!visited[x]) {
		visited[x] = 1;
		for (int i = 1;i < n + 1;++i) {
			if (arr[x][i]) { dfs(i); }
		}
	}
}

int main() {
	int m;
	std::cin >> n >> m;
	while (m--) {
		int x, y;
		std::cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	int ans = 0;
	for (int i = 1;i < n + 1;++i) {
		if (!visited[i]) {
			ans++;
			dfs(i);
		}
	}
	std::cout << ans;
}