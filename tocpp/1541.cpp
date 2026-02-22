#include<iostream>
#include<string>
/*
-나오면 다 빼기
*/

int main() {
	std::string s;
	std::cin >> s;
	int cur = 0;
	int numst = 0;
	int ans = 0;
	int isplus = 1;
	while (cur != s.size()) {
		if (s[cur] == '+' || s[cur] == '-') {
			ans += isplus * std::stoi(s.substr(numst, cur));
			numst = cur + 1;
			if (s[cur] == '-') { isplus = -1; }
		}
		++cur;
	}
	ans += isplus * std::stoi(s.substr(numst, cur));
	std::cout << ans;
}