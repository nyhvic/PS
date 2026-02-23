#include<iostream>
#include<climits>

/*
최소~최대 브루트포스, 최종 B<0이면 넘기기, 인풋 아웃풋 범위 생각해서 오버플로 조심하기, 현재 최소 시간 이용해서 가지치기
*/

int arr[501][501];

int main() {
	int n, m;
	long long int b;
	int mine = 257;
	int maxe = -1;
	std::cin >> n >> m >> b;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			std::cin >> arr[i][j];
			mine = std::min(arr[i][j], mine);
			maxe = std::max(arr[i][j], maxe);
		}
	}
	int mint = INT_MAX;
	int maxh = -1;
	for (int h = mine;h < maxe + 1;++h) {
		int time = 0;
		long long  int currentb = b;
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < m;++j) {
				if (arr[i][j] >= h) {
					currentb += arr[i][j] - h;
					time += (arr[i][j] - h) * 2;
				}
				else {
					currentb -= h - arr[i][j];
					time += h - arr[i][j];
				}
				if (time > mint) { break; }
			}
			if (time > mint) { break; }
		}
		if (currentb < 0) { continue; }
		if (mint > time) {
			mint = time;
			maxh = h;
		}
		else if (mint == time) {
			maxh = std::max(maxh, h);
		}
	}
	std::cout << mint << ' ' << maxh;
}