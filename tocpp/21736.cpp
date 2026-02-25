#include<iostream>
#include<vector>
#include<queue>

/*
I¿¡¼­ BFS
*/

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<char>> v(n, std::vector<char>(m));
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> v[i][j];
			if (v[i][j] == 'I') { q.push({ i,j }); }
		}
	}
	int ans = 0;
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();
		if (v[i][j] == 'X') { continue; }
		if (v[i][j] == 'P') { ++ans; }
		v[i][j] = 'X';
		if (i < n - 1 && v[i + 1][j] != 'X') { q.push({ i + 1,j }); }
		if (0 < i && v[i - 1][j] != 'X') { q.push({ i - 1,j }); }
		if (j < m - 1 && v[i][j + 1] != 'X') { q.push({ i ,j + 1 }); }
		if (0 < j && v[i][j - 1] != 'X') { q.push({ i ,j - 1 }); }
	}
	if (ans) {
		std::cout << ans;
	}
	else {
		std::cout << "TT";
	}
}