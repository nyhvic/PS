#include<iostream>
#include<queue>
#include<vector>

/*
DP로 n-1,n/3.n/2결과 재사용, 비교 연산 대신 pq사용
n-1을 호출하지 말고 n%2 or n%3더한값 사용하면 호출횟수 줄어들고 비교연산 더 적게함.
*/

int dp[1000001] = { 0 };

int makeone(int n) {
	if (dp[n]|| n == 1) { return dp[n]; }
	std::priority_queue<int,std::vector<int>,std::greater<int>> q;
	if (n % 2 == 0) { q.push(makeone(n / 2)); }
	if (n % 3 == 0) { q.push(makeone(n / 3)); }
	q.push(makeone(n - 1));
	dp[n] = q.top()+1;
	return dp[n];
}

int main() {
	int n;
	std::cin >> n;
	std::cout << makeone(n);
}