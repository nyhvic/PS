#include<iostream>
#include<bitset>

int main() {
	int n, k;
	std::cin >> n >> k;
	int total = n;
	int ind = 0;
	std::bitset<24> totalbit(n);
	while (totalbit.count() > k) {
		for (int i = 0;i <24 ;i++) {
			if (totalbit[i]) { ind = i; break; }
		}
		total += (1 << ind);
		totalbit = std::bitset<24>(total);
	}
	std::cout << total - n;
}

/*
2진수 활용
2진수로 변환할 시 모든 물병 최대로 합침, 1의 개수가 물병 개수
1이 처음으로 오는 인덱스 이용해 물병 한번에 필요한만큼 추가
*/