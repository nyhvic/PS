#include<iostream>
#include<vector>
#include<algorithm>

/*
1~최대값 매개변수 탐색
*/

int main() {
	unsigned int k, n;
	std::cin >> k >> n;
	std::vector<unsigned int> v(k);
	for (int i = 0;i < k;++i) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());

	unsigned int first = 1;
	unsigned int last = v[k - 1];
	unsigned int mid = (first + last) / 2;
	unsigned int ans = mid;
	unsigned int num = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		for (int i = 0;i < k;++i) {
			num += v[i] / mid;
		}
		if (num >= n) {
			first = mid + 1;
			ans = mid;
		}
		else {
			last = mid - 1;	
		}
		num = 0;
	}
	std::cout << ans;
}