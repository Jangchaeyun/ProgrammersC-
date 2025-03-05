#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for (int i = 0; i < new_id.size(); i++) {
        if (isupper(new_id[i])) new_id[i] = tolower(new_id[i]);
        else if (!isalnum(new_id[i]) && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
            new_id.erase(new_id.begin() + i--);
        }
    }
    for (int i = new_id.size() - 1; i > 0; i--)
        if (new_id[i - 1] == '.' && new_id[i] == '.') new_id.erase(new_id.begin() + i);
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.end() - 1);
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id == "") new_id += 'a';
    int size = new_id.size();
    if (size <= 2) while (new_id.size() != 3) new_id.push_back(new_id[size - 1]);
    if (size >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.') new_id.erase(new_id.end() - 1);
    }
    return new_id;
}