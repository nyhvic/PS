#include<iostream>
#include<string>
#include<unordered_map>

/*
unordered_map 써서 풀기, 해시 테이블 구조
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::string site, pass;
	std::unordered_map<std::string, std::string> map;
	for (int i = 0;i < n;++i) {
		std::cin >> site >> pass;
		map.insert({ site, pass });
	}
	for (int i = 0;i < m;++i) {
		std::cin >> site;
		std::cout << map[site];
		if (i != m - 1) { std::cout << '\n'; }
	}
}