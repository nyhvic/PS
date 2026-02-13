#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
#include<iostream>
#include<complex>
/*
0 - 1,0
1 - 0,1
2 - 1,1
3 - 1,2
4 - 2,3
5 - 3,5
벡터로 만든 피보나치 꼴, complex로 벡터합 사용, 테스트 케이스 여러개니 dp로 풀이, complex는 부동소수만 지원한다... 평소엔 만들어서 쓰자
*/

std::complex<int> DP[41] = { 0,0 };

std::complex<int> ans(int n) {
	if (n == 0) { return { 1,0 }; }
	if (n == 1) { return { 0,1 }; }
	if (DP[n]!=std::complex<int>(0,0)) { return DP[n]; }
	DP[n] = ans(n - 1) + ans(n - 2);
	return DP[n];
}

int main() {
	int t, n;
	std::cin >> t;
	std::complex<int> a;
	for (int i = 0;i < t;i++) {
		std::cin >> n;
		a = ans(n);
		std::cout << a.real()<<' ' << a.imag();
		if (i != t - 1) { std::cout << '\n'; }
	}
}