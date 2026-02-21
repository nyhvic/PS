#include<iostream>

/*
P(n)=P(n-1)+P(n-5) n>=6
수열 구하는 문제는 unsigned long long 써보기
*/

unsigned long long int dp[101] = { 0 };

unsigned long long int P(int n) {
	if (dp[n]) { return dp[n]; }
	dp[n] = P(n - 1) + P(n - 5);
	return dp[n];
}

int main() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::cout << P(n);
		if (t != 0) { std::cout << '\n'; }
	}
}