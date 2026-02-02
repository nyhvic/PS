#include<iostream>
#include<vector>

/*
물병 크기마다 개수 vector
가장 작은것들 합치기 안되면 그다음 마지막까지 안되면 추가 반복
tota<=k면 중지
*/

int main() {
	int n, k;
	std::cin >> n >> k;
	int total = n;
	int size = 1;
	int i = 0;
	int ans = 0;
	int merge;
	std::vector<int> water = { n };
	while (total > k) {
		if (water[i] > 1) {
			merge = water[i] / 2;
			water[i] -= 2*merge;
			if (i == size - 1) { water.push_back(merge); size++; }
			else { water[i + 1] += merge; }
			total -= merge;
		}
		else {
			if (i < size - 1) { i++; }
			else { i = 0; total ++; water[0]++; ans++; }
		}
	}
	std::cout << ans;
}