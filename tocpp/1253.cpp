#include<iostream>
#include<vector>
#include<algorithm>
/*
배열 받고 정렬, 처음 두 수는 못만듦
3번째 원소부터 판정(i), 범위는 0~i-1
투 포인터로 합 되는지 검사
실패 - 같은 수가 있다면 1,2번째 원소도 판정 가능, 자신보다 큰 수와 음수로도 만들 수 있음
-> 0~n-1범위로 검사, target 자기자신 예외처리
*/

int n;

bool IsGood(const std::vector<long long int>& v, int target) {
	int first = 0;
	int last = n - 1;
	while (first < last) {
		if (first == target) { first++; continue; }
		if (last == target) { last--; continue; }

		if (v[first] + v[last] == v[target]) { return true; }
		else if (v[first] + v[last] < v[target]) { first++; }
		else { last--; }
	}
	return false;
}

int main() {
	std::cin >> n;
	std::vector<long long int> v(n);
	for (int i = 0;i < n;i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0;i < n;i++) {
		if (IsGood(v, i))ans++;
	}
	std::cout << ans;
}