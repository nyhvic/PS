#include<iostream>
#include<queue>

/*
그래프 문제, x to x-1, x to x+1, x to 2x까지 거리 1로 초기화 후 n to k bfs
n-1, n+1, 2n방문후 다음방문 큐에넣기, v[n][j] = v[n][i] + v[i][j](1)
메모리 초과, 큐에 넣기 전에 visited 검사 후 큐에 넣고 visited 1로 변경, 또 메모리 초과 최대 200000x200000배열은 너무 크다..
이중 배열을 쓸 필요가 없다. 배열 범위도 0~100000까지면 충분하다.
좌표,거리 pair 사용, n,0 n-1,1 n+1,1 2n,1 ...
처음 생각난 식이 f(n) = min(f(n-1),f(n+1),f(2n))+1로 DP와 재귀를 이용하려 하였으나 무한 반복 문제, 최단 시간(경로)이므로 bfs 사용
상위권은 수학적으로 식 만들어 재귀로 풀었다. 문제 읽고 사용할 알고리즘,자료구조 생각->알고리즘 바탕으로 식 세우고 알고리즘 수정->구현
*/

int main() {
	int n, k;
	std::cin >> n >> k;
	std::queue<std::pair<int, int>> q;
	bool visited[100001] = { 0 };
	q.push({ n,0 });
	while (!q.empty()) {
		auto [point, len] = q.front();
		q.pop();
		if (point == k) { std::cout << len; break; }
		if (point != 0 && !visited[point - 1]) { q.push({ point - 1,len + 1 });visited[point - 1] = true; }
		if (point != 100000 && !visited[point + 1]) { q.push({ point + 1, len + 1 });visited[point + 1] = true;}
		if (point <= 50000 && !visited[2*point]) { q.push({ 2 * point,len + 1 });visited[2*point] = true;}
	}
}