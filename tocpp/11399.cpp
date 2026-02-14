#include<iostream>
#include<vector>
#include<algorithm>

/*
정렬후 n-i 곱해서 합
*/

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0;i < n;i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0;i < n;i++) {
		ans += v[i] * (n-i);
	}
	std::cout << ans;
}