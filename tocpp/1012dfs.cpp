#include<iostream>
#include<array>

/*
dfs/bfs 쓰는게 더 효율적임. union find방식 사용 위해서 추가로 배열 생성하고 해시, union 연산 추가 필요
arr말고 map써도 map 연산때문에 비슷할듯
*/

std::array<std::array<int,50>,50> arr;

int m, n;

void dfs(int x, int y) {
	if (!arr[x][y]) { return; }
	arr[x][y] = 0;
	if (0 < x) { dfs(x - 1, y); }
	if (x < m - 1) { dfs(x + 1, y); }
	if (0 < y) { dfs(x, y - 1); }
	if (y < n - 1) { dfs(x, y + 1); }
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int  k;
		std::cin >> m >> n >> k;
		while (k--) {
			int x, y;
			std::cin >> x >> y;
			arr[x][y] = 1;
		}
		int ans = 0;
		for (int i = 0;i < m;++i) {
			for (int j = 0;j < n;++j) {
				if (arr[i][j]) { 
					++ans;
					dfs(i, j);
				}
			}
		}
		std::cout << ans;
		if (t != 0) { std::cout << '\n'; }
	}
}