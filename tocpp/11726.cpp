#include<iostream>

/*
f(1) = 1
f(2) = 2
f(3) = 3
f(4) = f(2)+f(3) 끝부분 1x2 2x1 피보나치
*/

int fib(int n) {
	if (n <= 2) { return n; }
	int a = 1;
	int b = 2;
	int c = a + b;
	for (int i = 2;i < n;i++) {
		c = (a + b)%10007;
		a = b % 10007;
		b = c % 10007;
	}
	return c;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << fib(n);
}