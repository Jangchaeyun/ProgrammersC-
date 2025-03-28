#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (auto skill_tree : skill_trees) {
		bool is_good = true;
		int skill_idx = 0;
		for (auto user_skill : skill_tree) {
			int cur_idx = skill.find(user_skill);
			if (cur_idx == -1) continue;
			if (cur_idx != skill_idx) {
				is_good = false;
				break;
			}
			skill_idx++;
		}
		if (is_good) answer++;
	}
	return answer;
}