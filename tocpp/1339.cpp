#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

/*
자리수, 횟수 높은순으로 9부터 배정
벡터와 맵 사용해 문자 자릿수 횟수 저장해서 사용하려 하였으나 비효율적
맵에 문자, 자릿수*횟수총합 저장하여 input받으며 저장하고 value값 벡터에 넣고 정렬하여 ind*value로 총합
map대신 크기 26배열에 자릿수*횟수 저장해 사용하여 메모리 효율 높일 수 있을듯
*/


int main() {
	int n, size;
	std::string s;
	std::cin >> n;
	std::map<char, int> m;
	std::vector<int> v;
	for (int i = 0;i < n;i++) {
		std::cin >> s;
		size = s.size();
		for (int j = 0;j < size; j++) {
			m[s[size - 1 - j]] += std::pow(10, j);
		}
	}
	for (auto& iter : m) {
		v.push_back(iter.second);
	}
	std::sort(v.begin(), v.end());
	int ans = 0;
	int digit = 9;
	for (auto iter = v.rbegin();iter != v.rend();iter++) {
		ans += (*iter) * digit;
		digit--;
	}
	std::cout << ans;
}