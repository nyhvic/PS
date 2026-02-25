#include<iostream>
#include<vector>
#include<map>

/*
front, rear index로 사용, map으로 개수 관리
그리디하게 front, rear중에서 개수가 가장 적은거 제외
그리디하게 풀 수 없었다. 브루트포스로 풀이
front를 증가시키며 rear 빼면서 구하기 - map 복사 필요(O(n)))
rear 0에서부터 증가시키며 풀이 - map 복사 불필요, 반복 적어짐
rear 0~n-1로 증가, front는 0~n-1로 증가(되돌아가지 않음)
input 받으며 map 갱신할 필요 없음
*/

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	std::map<int, int> map;
	int type = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	int ans = 0;
	int front = 0;
	for (int rear = 0; rear < n; ++rear) {
		++map[v[rear]];
		if (map[v[rear]] == 1) { ++type; }
		while (type > 2) {
			if (!--map[v[front++]]) { --type; }
		}
		ans = std::max(ans, rear - front + 1);
	}
	std::cout << ans;
}