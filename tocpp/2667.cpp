#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

/*
1 주변 bfs, 플러드필
*/

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	std::vector<int> ans;
	int num = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == '1') {
				q.push({ i,j });
				++num;
				ans.push_back(0);
				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					if (v[x][y] == '0') { continue; }
					v[x][y] = '0';
					++ans[num - 1];
					if (0 < x && v[x - 1][y] == '1') { q.push({ x - 1,y }); }
					if (x<n-1 && v[x + 1][y] == '1') { q.push({ x + 1,y }); }
					if (0 < y && v[x][y - 1] == '1') { q.push({ x ,y - 1 }); }
					if (y < n - 1 && v[x][y + 1] == '1') { q.push({ x ,y + 1 }); }
				}
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	std::cout << num;
	for (auto elem : ans) {
		std::cout << '\n' << elem;
	}
}