#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

/*
bfs
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int m, n, h;
	int ans = 0;
	std::queue<std::tuple<int, int, int,int>> q;
	std::cin >> m >> n >> h;
	std::vector<std::vector<std::vector<int>>> v(h, std::vector<std::vector<int>>(n, std::vector<int>(m, 0)));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				std::cin >> v[i][j][k];
				if (v[i][j][k]==1) { q.push({ i,j,k,0 }); }
			}
		}
	}
	int i, j, k, day;
	std::tuple<int, int, int, int> current;
	while (!q.empty()) {
		current = q.front();
		std::tie(i, j, k, day) = current;
		q.pop();
		if (v[i][j][k]==-1) { continue; }
		v[i][j][k] = -1;
		ans = day;
		if (0 < i && !v[i - 1][j][k]) { q.push({ i - 1,j,k,day + 1 }); }
		if (i < h - 1 && !v[i + 1][j][k]) { q.push({ i + 1,j,k,day + 1 }); }
		if (0 < j && !v[i][j - 1][k]) { q.push({ i ,j - 1,k,day + 1 }); }
		if (j < n - 1 && !v[i][j + 1][k]) { q.push({ i ,j + 1,k,day + 1 }); }
		if (0 < k && !v[i][j][k - 1]) { q.push({ i ,j,k - 1,day + 1 }); }
		if (k < m - 1 && !v[i][j][k + 1]) { q.push({ i ,j,k + 1,day + 1 }); }
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (!v[i][j][k]) { std::cout << -1; return 0; }
			}
		}
	}
	std::cout << ans;
}