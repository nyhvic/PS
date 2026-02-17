#include<iostream>
#include<vector>
#include<algorithm>
typedef unsigned long long int it;
/*
매개변수 탐색, 기준점 이하 높이 h
v[i]+...+v[n-1] - (n-i)h >= m
마지막 h값 저장해서 탐색 끝날때 return할수 있도록 하기
조건식 범위설정 오류로 0,n부분 검사 못했음, 중복숫자 있는경우 해결
로직 수정 -> 0~v[n-1]범위에서 이분탐색, 수식으로 h 구하지 않고 이분탐색으로 찾기
*/

it sum(std::vector<it>& v,it mid) {
	it ret = 0;
	for (auto& elem : v) {
		if (elem > mid) { ret += elem - mid; }
	}
	return ret;
}

int main() {
	it n, m;
	std::cin >> n >> m;
	std::vector<it> v(n);
	for (int i = 0;i < n;++i) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	it first = 0;
	it last = v[n - 1];
	it mid = 0;
	it h = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		it s = sum(v, mid);
		if (s < m) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
			h = mid;
		}
	}
	std::cout << h;
}
