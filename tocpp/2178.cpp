#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>

/*
BFS, tuple로 좌표 거리 저장
*/

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	std::queue<std::tuple<int, int, int>> q;
	q.push({ 0,0,1 });
	while (true) {
		auto [i, j, len] = q.front();
		q.pop();
		if (v[i][j] == '0') { continue; }
		if (i == n - 1 && j == m - 1) { std::cout << len; break; }
		v[i][j] = '0';
		if (0 < i && v[i - 1][j] != '0') { q.push({ i - 1,j,len + 1 }); }
		if (i<n-1 && v[i + 1][j] != '0') { q.push({ i + 1,j,len + 1 }); }
		if (0 < j && v[i][j - 1] != '0') { q.push({ i ,j - 1,len + 1 }); }
		if (j < m - 1 && v[i][j + 1] != '0') { q.push({ i ,j + 1,len + 1 }); }
	}
}