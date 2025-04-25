#include <vector>

using namespace std;

const int INF = 1e9;
int N, K, mid, cnt;
bool is_pos;

vector<int> tree[10010];
vector<bool> is_root(10010, true);

int dfs(vector<int>& num, int node) {
    if (!is_pos) return INF;

    if (cnt >= K || num[node] > mid) {
        is_pos = false;
        return INF;
    }

    if (tree[node].size() == 2) {
        int c1 = dfs(num, tree[node][0]);
        int c2 = dfs(num, tree[node][1]);

        if (c1 + c2 + num[node] <= mid) {
            return c1 + c2 + num[node];
        }

        else if (c1 + num[node] <= mid && c2 + num[node] <= mid) {
            cnt++;
            return c1 > c2 ? c2 + num[node] : c1 + num[node];
        }
        else if (c1 + num[node] <= mid) {
            cnt++;
            return c1 + num[node];
        }
        else if (c2 + num[node] <= mid) {
            cnt++;
            return c2 + num[node];
        }

        else {
            cnt += 2;
            return num[node];
        }
    }
    else if (tree[node].size() == 1) {
        int c = dfs(num, tree[node][0]);

        if (c + num[node] <= mid) return c + num[node];
        else {
            cnt++;
            return num[node];
        }
    }
    else return num[node];
}

bool solve(vector<int>& num, int root) {
    is_pos = true;
    cnt = 0;

    dfs(num, root);

    if (cnt >= K || !is_pos) return false;

    return true;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = INF;
    N = num.size();
    K = k;

    for (int i = 0; i < N; ++i) {
        if (links[i][0] != -1) {
            tree[i].push_back(links[i][0]);
            is_root[links[i][0]] = false;
        }

        if (links[i][1] != -1) {
            tree[i].push_back(links[i][1]);
            is_root[links[i][1]] = false;
        }
    }
    int root = -1;
    for (int i = 0; i < N; ++i) {
        if (is_root[i]) {
            root = i;
            break;
        }
    }

    int start = 1, end = INF;
    while (start <= end) {
        mid = (start + end) / 2;

        if (solve(num, root)) {
            answer = min(answer, mid);
            end = mid - 1;
        }
        else start = mid + 1;
    }

    return answer;
}