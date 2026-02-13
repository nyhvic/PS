#include<iostream>
#include<string>
#include<vector>
#include<map>

/*
map이랑 벡터 사용해서 바로 출력, 입출력 많아서 tie, sync 끔
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> v(n);
	std::map<std::string, int> ms;
	for (int i = 0;i < n;i++) {
		std::cin >> v[i];
		ms.insert({ v[i],i + 1 });
	}
	std::string input;
	for (int i = 0;i < m;i++) {
		std::cin >> input;
		if (ms[input]) { std::cout << ms[input]; }
		else { std::cout << v[std::stoi(input)-1]; }
		if (i != m - 1) { std::cout << '\n'; }
	}
}