#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Page {
    int idx;
    vector<string> out_url_list;
    int basic_point;
    double link_point;
    double match_point;
};
vector<Page> page_list;
string WORD;
map<string, int> page_num;

string tolower(string word) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }

    return word;
}

string get_url(string page) {
    string front_url = "<meta property=\"og:url\" content=\"https://";
    string url = "";
    int idx = page.find(front_url);
    idx += front_url.length();

    while (page[idx] != '\"') {
        url += page[idx];
        idx++;
    }

    return url;
}

vector<string> get_out_url(string page) {
    vector<string> url_list;
    string front_url = "<a href=\"https://";
    int idx = page.find(front_url);

    while (idx != page.npos) {
        idx += front_url.length();
        string url = "";

        while (page[idx] != '\"') {
            url += page[idx];
            idx++;
        }

        url_list.push_back(url);
        page = page.substr(idx);
        idx = page.find(front_url);
    }

    return url_list;
}

int find_text(string page) {
    string start = "<body>";
    string end = "</body>";
    int s = page.find(start);
    s += start.length();
    int e = page.find(end);
    page = page.substr(s, e - s);

    string text = "";
    int count = 0;

    for (int i = 0; i < page.length(); i++) {
        if (!isalpha(page[i])) {
            if (text == WORD) {
                count++;
            }
            text = "";
        }
        else {
            text += page[i];
        }
    }

    return count;
}

void save_page(vector<string> pages) {
    int num = 0;
    for (string page : pages) {
        string page_to_low = tolower(page);
        string url = get_url(page_to_low);
        page_num[url] = num + 1;
        vector<string> out_url_list = get_out_url(page_to_low);
        int basic_point = find_text(page_to_low);
        page_list.push_back({ num, out_url_list, basic_point, 0.0, 0.0 });
        num++;
    }
}

int cal_point() {
    int p_size = page_list.size();
    double max_match_point = -999999999.0;
    int index = -1;

    for (int i = 0; i < p_size; i++) {
        vector<string> out_pages = page_list[i].out_url_list;
        int o_size = out_pages.size();

        for (int j = 0; j < o_size; j++) {
            string url = out_pages[j];

            if (page_num[url] != 0) {
                int idx = page_num[url] - 1;
                page_list[idx].link_point += ((double)page_list[i].basic_point / (double)o_size);
            }
        }
    }

    for (int i = 0; i < p_size; i++) {
        page_list[i].match_point = (double)page_list[i].basic_point + page_list[i].link_point;
        if (page_list[i].match_point > max_match_point) {
            max_match_point = page_list[i].match_point;
            index = page_list[i].idx;
        }
    }

    return index;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    WORD = tolower(word);
    save_page(pages);
    answer = cal_point();

    return answer;
}