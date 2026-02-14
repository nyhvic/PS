#include<iostream>
#include<vector>

/*
배열 만들고 합 시간초과 O(N)
구간 합(i번째까지 합)만들고 s[j]-s[i-1]로 구하기 - O(1)
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> v(n+1,0),s(n+1,0);
	for (int i = 1;i < n+1;i++) {
		std::cin >> v[i];
		if (i == 1) { s[i] = v[i]; }
		else { s[i] = v[i] + s[i - 1]; }
	}
	int i, j;
	for (int t = 0;t < m;t++) {
		std::cin >> i >> j;
		std::cout << s[j] - s[i-1];
		if (t != m - 1) { std::cout << '\n'; }
	}
}