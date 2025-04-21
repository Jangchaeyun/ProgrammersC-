#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
private:
    Trie* child[26];  
    int count;
public:
    Trie() : child(), count(0) {}
    void Insert(string str) {
        Trie* now = this;
        for (char ch : str) {
            now->count++;
            if (now->child[ch - 'a'] == nullptr)
                now->child[ch - 'a'] = new Trie();
            now = now->child[ch - 'a'];
        }
    }

    int Search(string str) {
        Trie* now = this;
        for (char ch : str) {
            if (ch == '?')
                return now->count; 
            now = now->child[ch - 'a'];
            if (now == nullptr)
                return 0;
        }
        return -1;
    }
};

Trie TrieRoot[10000];
Trie ReTrieRoot[10000];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (string str : words) {
        TrieRoot[str.length() - 1].Insert(str);

        reverse(str.begin(), str.end());
        ReTrieRoot[str.length() - 1].Insert(str);
    }
    for (string query : queries) {
        if (query[0] != '?')
            answer.push_back(TrieRoot[query.length() - 1].Search(query));
        else {
            reverse(query.begin(), query.end());
            answer.push_back(ReTrieRoot[query.length() - 1].Search(query));
        }
    }
    return answer;
}