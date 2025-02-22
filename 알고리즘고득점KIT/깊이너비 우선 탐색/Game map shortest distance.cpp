#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

bool vst[104][104];
int dist[104][104];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

int solution(vector<vector<int>> m) {
	int ans = 0;
	int ns = m.size();
	int ms = m[0].size();
	memset(dist, -1, sizeof(dist));
	q.push({ 0, 0 });
	vst[0][0] = 1;
	dist[0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first == ns - 1 && cur.second == ms - 1) {
			return dist[ns - 1][ms - 1];
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (nx < 0 || ny < 0 || nx >= ms || ny >= ns) continue;
			if (vst[ny][nx] || m[ny][nx] == 0 || dist[ny][nx] != -1) continue;
			q.push({ ny, nx });
			vst[ny][nx];
			dist[ny][nx] = dist[cur.first][cur.second] + 1;
		}
	}
	if (dist[ns - 1][ms - 1] == -1) ans = -1;
	else ans = dist[ns - 1][ms - 1];
	return ans;
}