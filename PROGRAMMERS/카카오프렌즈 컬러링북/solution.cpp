#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//위 오른쪽 아래 왼쪽
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int M, N;
vector<vector<int>> pic;
bool visited[100][100];
struct loc { int x, y; };

int bfs(loc start) {
	int cnt = 1;
	queue<loc> q;
	q.push(start);
	visited[start.y][start.x] = true;
	while (!q.empty()) {
		loc now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i];
			//화면 영역을 벗어나는 경우 pass
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			//현재 영역 값과 다음 영역 값이 같고, 다음 영역이 방문처리 되지 않은 경우
			if (pic[now.y][now.x] == pic[ny][nx] && !visited[ny][nx]) {
				q.push(loc({ nx, ny }));
				visited[ny][nx] = true;
				cnt++;
			}
		}

	}
	return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	N = n;
	M = m;
	pic = picture;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	}


	for (int y = 0; y < m; y++) {   //y
		for (int x = 0; x < n; x++) {   //x
			if (visited[y][x] || !picture[y][x]) continue;
			number_of_area++;
			max_size_of_one_area = max(max_size_of_one_area, bfs(loc({ x, y })));
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}