#include<iostream>
#include<vector>

/*
i번째 계단 가는 경우
i-3 to i-1 to i, i-2 to i
dp[i-3]+v[i-1]+v[i] or v[i-2]+v[i]
*/

int ans(int n,const std::vector<int>& v, std::vector<int>& dp) {
	if (dp[n]) { return dp[n]; }
	int ret;
	ret = ans(n - 2, v, dp) < ans(n - 3, v, dp) + v[n - 1] ? ans(n - 3, v, dp) + v[n - 1] : ans(n - 2, v, dp);
	dp[n] = ret + v[n];
	return dp[n];
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n+1),dp(n+1);
	for (int i = 1;i < n + 1;++i) {
		std::cin >> v[i];
	}
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = v[1] < v[2] ? v[2] : v[1];
	dp[3] += v[3];
	std::cout << ans(n,v,dp);
}