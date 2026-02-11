#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<climits>

/*
다익스트라 알고리즘 구현
인접 리스트 그래프 사용, pq와 방문 set 사용
c++17 구조화된 바인딩 편하다
*/

int main() {
	int V, E, start, u, v, w,cur,weight;
	std::cin >> V >> E >> start;
	std::vector<std::vector<std::pair<int, int>>> Graph(V + 1);
	for (int i = 0;i < E;i++) {
		std::cin >> u >> v >> w;
		Graph[u].push_back({ v,w });
	}
	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::vector<int> dist(V + 1,INT_MAX);
	dist[start] = 0;
	std::set<int> visited;
	pq.push({ 0,start });
	while (!pq.empty()) {
		auto [weight, cur] = pq.top();
		pq.pop();
		if (visited.find(cur)!=visited.end()) { continue; }
		visited.insert(cur);
		for (auto [v, w] : Graph[cur]) {
			if (dist[cur] + w < dist[v]) {
				dist[v] = dist[cur] + w;
				pq.push({ dist[v],v });
			}
		}
	}
	for (int i = 1;i < V + 1;i++) {
		if (dist[i] == INT_MAX) { std::cout << "INF"; }
		else { std::cout << dist[i]; }
		if (i != V + 1) { std::cout << '\n'; }
	}
}