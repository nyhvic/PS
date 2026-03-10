#include<iostream>
#include<vector>

/*
플로이드 워셜 알고리즘, 길이 1이상인 경우 1 출력
*/

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> v(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> v[i][j];
			if (!v[i][j]) { v[i][j] = n+1; }
		}
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] <= n) { std::cout << 1; }
			else { std::cout << 0; }
			if (j != n - 1)std::cout << ' ';
		}
		if (i != n - 1)std::cout << '\n';
	}
}