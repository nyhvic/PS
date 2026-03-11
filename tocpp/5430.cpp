#include<iostream>
#include<deque>
#include<string>
#include<sstream>

/*
덱 사용 R입력마다 front back 변경
*/

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin >> T;
	while (T--) {
		bool front = true;
		bool err = false;
		std::deque<int> d;
		std::string p;
		int n;
		std::string ar;
		std::cin >> p >> n >> ar;
		std::stringstream ss(ar.substr(1, ar.size() - 2));
		std::string elem;
		while (std::getline(ss, elem, ',')) {
			d.push_back(std::stoi(elem));
		}
		for (auto c : p) {
			if (c == 'R') {
				front = !front;
			}
			else {
				if (d.empty()) { err = true; break; }
				if (front) {
					d.pop_front();
				}
				else {
					d.pop_back();
				}
			}
		}
		if (err) { std::cout << "error"; }
		else {
			std::cout << '[';
			if (front) {
				for (auto iter = d.begin(); iter != d.end(); ++iter) {
					std::cout << *iter;
					if (iter != d.end() - 1) { std::cout << ','; }
				}
			}
			else {
				for (auto iter = d.rbegin(); iter != d.rend(); ++iter) {
					std::cout << *iter;
					if (iter != d.rend() - 1) { std::cout << ','; }
				}
			}
			std::cout << ']';
		}
		if (T != 0) { std::cout << '\n'; }
	}
}