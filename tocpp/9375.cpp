#include<iostream>
#include<string>
#include<map>

/*
type만 받고 각 경우 조합, 모두 안입는 경우 1 빼기
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T, n;
	std::string name, type;
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::map<std::string, int> map;
		int ans = 1;
		while (n--) {
			std::cin >> name >> type;
			map[type] += 1;
		}
		for (auto [type, num] : map) {
			ans *= num + 1;
		}
		std::cout << ans - 1;
		if (T != 0) { std::cout << '\n'; }
	}
}