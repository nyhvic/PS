#include<iostream>
#include<cmath>

/*
분할정복, 
길이 L(n) = 2L(n-1) + 3, L(0) = 1, 일반항 2^(n+2) -3
패티 개수 P(n) = 2P(n-1) + 1, P(0) = 1, 일반항 2^(n+1)-1
B l-1 P l-1 B
작은 버거 2개로 나눠짐, 범위 구간별로 나누어 풀이
*/

unsigned long long int burger(int n, unsigned long long int x) {
	if (x <= 1) { return 0; }
	if (n == 1) {/*BPPPB*/
		if (x == 5) { return 3; }
		if (0 < x && x < 5) { return x - 1; }
	}
	unsigned long long int len = (1ULL << (n + 2)) - 3;
	unsigned long long int half = (1ULL << (n + 1)) - 3;
	if (x == len) { return (1UL << (n + 1)) - 1; }
	if (x > half + 2) { return (1ULL << (n )) + burger(n - 1, x - half - 2); }
	if (x < half+1) { return burger(n - 1, x-1); }
	if (x  == half+1) { return (1ULL << (n )) - 1; }
	if (x  == half + 2) { return 1ULL << (n ); }
}

int main() {
	int n;
	unsigned long long int x;
	std::cin >> n >> x;
	std::cout << burger(n, x);
}