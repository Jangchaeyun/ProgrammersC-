#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
	int answer = 0;
	int server = 0;
	queue<pair<int, int>> time;

	for (int i = 0; i < players.size(); ++i) {
		if (!time.empty() && time.front().first == i) {
			server -= time.front().second;
			time.pop();
		}

		if (m <= players[i]) {
			int required = players[i] / m;

			if (required > server) {
				int newServer = required - server;
				server += newServer;
				answer += newServer;
				time.push({ i + k, newServer });
			}
		}
	}
	return answer;
}