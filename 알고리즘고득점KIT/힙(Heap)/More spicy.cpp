#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	while (pq.size() >= 2 && pq.top() < K) {
		int firstMin = pq.top();
		pq.pop();

		int secondMin = pq.top();
		pq.pop();

		answer++;
		pq.push(firstMin + secondMin * 2);
	}

	if (!pq.empty() && pq.top() < K) return -1;
	return answer;
}