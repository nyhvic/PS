#include<iostream>

/*
P(n)=P(n-1)+2P(n-2), P(1) = 1, P(2) = 3
*/

int dp[1001];

int P(int n) {
	if (dp[n]) { return dp[n]; }
	dp[n] = (P(n - 1) + 2 * P(n - 2)) % 10007;
	return dp[n];
}

int main() {
	dp[1] = 1;
	dp[2] = 3;
	int n;
	std::cin >> n;
	std::cout << P(n);
}