#include<iostream>
#include<map>
#include<vector>

/*
union find로 구현
union find에 모두 추가 모든 원소에 상하좌우 merge한 후 집합 개수
map으로 좌표 1ㄷ1 매핑 1~K, map[i,j] = k, 상하좌우 merge
*/

class UnionFind {
	std::vector<int> parent;
	std::vector<int> rank;
	int count;
public:
	UnionFind(int n):parent(n+1,0), rank(n+1,0), count(n){
		for (int i = 1;i < n + 1;++i) {
			parent[i] = i;
		}
	}
	int find(int n) {
		if (parent[n] == n) { return n; }
		return parent[n] = find(parent[n]);
	}
	void uni(int a, int b) {
		if (b == 0) { return; }
		a = find(a);
		b = find(b);
		if (a == b) { return; }

		if (rank[a] < rank[b]) { parent[a] = b; }
		else {
			parent[b] = a;
			if (rank[a] == rank[b]) { ++rank[a]; }
		}
		count--;
	}
	int getcount() const { return count; }	
	void print() {
		for (auto& elem : parent) {
			std::cout << elem << ' ';
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::map<std::pair<int, int>, int> map;
	std::cin >> T;
	for (int t = 0;t < T;++t) {
		int m, n, k;
		std::cin >> m >> n >> k;
		UnionFind u(k);
		for (int i = 1;i < k+1;++i) {
			int x, y;
			std::cin >> x >> y;
			map[{x, y}] = i;
			if (0 < x) { u.uni(i, map[{x - 1, y}]); }
			if (x < m - 1) { u.uni(i, map[{x + 1, y}]); }
			if (0 < y) { u.uni(i, map[{x, y - 1}]); }
			if (y < n - 1) { u.uni(i, map[{x, y + 1}]); }
		}
		std::cout << u.getcount();
		if (t != T - 1) { std::cout << '\n'; }
		map.clear();
	}
}