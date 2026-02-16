#include<iostream>
/*
전역으로 array 만들어 사용
i,j / i+n/2,j / i,j+n/2 / i+n/2,j+n/2부분으로 나뉨
판단하는 함수 하나, 재귀함수 하나
*/

int arr[128][128];
int white = 0;
int blue = 0;

bool allsame(int x, int y, int n) {
	if (arr[x][y]) {
		for (int i = x;i < x + n;++i) {
			for (int j = y;j < y + n;++j) {
				if (!arr[i][j]) { return false; }
			}
		}
		++blue;
		return true;
	}
	else {
		for (int i = x;i < x + n;++i) {
			for (int j = y;j < y + n;++j) {
				if (arr[i][j]) { return false; }
			}
		}
		++white;
		return true;
	}
}

void ans(int x, int y, int n) {
	if (!allsame(x, y, n)) {
		ans(x, y, n / 2);
		ans(x + n / 2, y, n / 2);
		ans(x, y + n / 2, n / 2);
		ans(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			std::cin >> arr[i][j];
		}
	}
	ans(0, 0, n);
	std::cout << white << '\n' << blue;
}