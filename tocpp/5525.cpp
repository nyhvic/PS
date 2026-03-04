#include<iostream>
#include<string>

/*
P(N) 만들고 cur=0부터 시작해 cur,cur+2n+1과 P(N) 비교
P와 비교 대신 IOI와 비교후 반복횟수 카운팅으로 최적화 가능, P 안구하고 리터럴 IOI 사용
*/

int main() {
	int n, m;
	std::string s, p;
	int ans = 0;
	std::cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) {
		p += "IO";
	}
	p += 'I';
	int cur = 0;
	while (cur + p.length() <= m) {
		if (s[cur] == 'O') {
			++cur;
		}
		else {
			if (!s.compare(cur, p.length(), p)) {
				++ans;
				cur += p.length();
				while (cur + 2 <= m && !s.compare(cur, 2, "OI")) {
					++ans;
					cur += 2;
				}
			}
			else {
				++cur;
			}
		}
	}
	std::cout << ans;
}