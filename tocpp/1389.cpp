#include<iostream>
#include<vector>
#include<climits>
#include<numeric>

/*
인접행렬, 플로이드 워셜 최단거리 알고리즘
오버플로우 주의, 거리 최대값 99
*/

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n+1, std::vector<int>(n+1,102));
	for (int i = 1; i < n+1; ++i) {
		v[i][i] = 0;
	}
	int s, e;
	while (m--) {
		std::cin >> s >> e;
		v[s][e] = 1;
		v[e][s] = 1;
	}
	for (int k = 1; k < n+1; ++k) {
		for (int i = 1; i < n+1; ++i) {
			for (int j = 1; j < n+1; ++j) {
				v[i][j] = std::min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	int ans = 0, min = INT_MAX, sum = 0;
	for (int i = 1; i < n+1; ++i) {
		sum = std::accumulate(v[i].begin() + 1, v[i].end(), 0);
		if (sum < min) { ans = i; min = sum; }
	}
	std::cout << ans;
}