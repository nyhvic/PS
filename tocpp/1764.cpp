#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

/*
map 사용해 n개 입력에 넣고 m개 입력 받으며 map과 비교
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::map<std::string, bool> map;
	std::string input;
	std::vector<std::string > ans;
	for (int i = 0;i < n;i++) {
		std::cin >> input;
		map.insert({ input,true });
	}
	for (int i = 0;i < m;i++) {
		std::cin >> input;
		if (map[input]) { ans.push_back(input); }
	}
	std::cout << ans.size();
	std::sort(ans.begin(), ans.end());
	for (int i = 0;i < ans.size();i++) {
		std::cout << '\n' << ans[i];
	}
}