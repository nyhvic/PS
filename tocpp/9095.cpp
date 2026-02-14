#include<iostream>

/*
1 1
2 2
3 4
4 7
5 13...
정수론이나 순열 문제로 접근했으나 실패, 점화식 구해 DP로 풀이
f(n) = f(n-1) + f(n-2) + f(n-3), n-1 구하고 1더하기, n-2구하고... 트리보나치 수열
*/

int DP[11] = { 0 };

int ans(int n) {
	if (n == 1) { return 1; }
	if (n == 2) { return 2; }
	if (n == 3) { return 4; }
	if (DP[n]) { return DP[n]; }
	DP[n] = ans(n - 1) + ans(n - 2) + ans(n - 3);
	return DP[n];
}

int main() {
	int t, n;
	std::cin >> t;
	for (int i = 0;i < t;i++) {
		std::cin >> n;
		std::cout << ans(n);
		if (i != t - 1) { std::cout << '\n'; }
	}
}