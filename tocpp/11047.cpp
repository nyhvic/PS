#include<iostream>
#include<vector>

/*
그리디하게 큰 동전부터 차례대로 사용
*/

int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n);
	for (int i = 0; i< n;i++) {
		std::cin >> v[i];
	}
	int ans = 0;
	for (auto iter = v.rbegin(); iter != v.rend();iter++) {
		ans += k / (*iter);
		k -= (*iter) * (k / (*iter));
	}
	std::cout << ans;
}