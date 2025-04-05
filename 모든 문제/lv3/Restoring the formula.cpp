#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector<string> StrSplit(string str) {
    stringstream sst(str);
    string buf;
    vector<string>retV;
    while (getline(sst, buf, ' ')) {
        retV.push_back(buf);
    }
    return retV;
}


int convAtoB(int a, int b) {
    int retN = 0;
    int tt = 1;
    while (a > 0) {
        if (a % 10 >= b) {
            return -1;
        }
        retN += (a % 10) * tt;
        tt *= b;
        a /= 10;
    }
    return retN;
}

int conv10toB(int a, int b) {
    int retN = 0;
    int tt = 1;
    while (a > 0) {
        retN += (a % b) * tt;
        tt *= 10;
        a /= b;
    }
    return retN;
}

vector<int> notNLst(vector<string> str) {
    int A, B, C;
    vector<int> retVi;
    for (int i = 2; i < 10; i++)
    {
        A = convAtoB(stoi(str[0]), i);
        B = convAtoB(stoi(str[2]), i);
        if (str[4] == "X") {
            if (A < 0 || B < 0) {
                retVi.push_back(i);
            }
        }
        else {
            C = convAtoB(stoi(str[4]), i);
            if (A < 0 || B < 0 || C < 0) {
                retVi.push_back(i);
                continue;
            }
            if (str[1] == "-")
            {
                if (A - B != C)
                    retVi.push_back(i);
            }
            else
            {
                if (A + B != C)
                    retVi.push_back(i);
            }
        }
    }
    return retVi;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<vector<string>> tmpAns;
    vector<bool>visit(10, true);
    for (int i = 0; i < expressions.size(); i++) {
        vector<string> tmpS = StrSplit(expressions[i]);
        if (tmpS[4] == "X") {
            tmpAns.push_back(tmpS);
        }
        vector<int> ti = notNLst(tmpS);
        for (int j = 0; j < ti.size(); j++) {
            visit[ti[j]] = false;
        }
    }
    vector<int> canList;
    for (int i = 2; i < 10; i++) {
        if (visit[i])
        {
            canList.push_back(i);
        }
    }
    for (int i = 0; i < tmpAns.size(); i++) {
        int A, B, C, cmpC;
        bool flag = true;
        A = convAtoB(stoi(tmpAns[i][0]), canList[0]);
        B = convAtoB(stoi(tmpAns[i][2]), canList[0]);
        if (tmpAns[i][1] == "+")
        {
            C = conv10toB(A + B, canList[0]);
        }
        else {
            C = conv10toB(A - B, canList[0]);
        }
        for (int j = 1; j < canList.size(); j++) {
            A = convAtoB(stoi(tmpAns[i][0]), canList[j]);
            B = convAtoB(stoi(tmpAns[i][2]), canList[j]);
            if (tmpAns[i][1] == "+")
            {
                cmpC = conv10toB(A + B, canList[j]);
            }
            else {
                cmpC = conv10toB(A - B, canList[j]);
            }
            if (cmpC != C) {
                flag = false;
                tmpAns[i][4] = "?";
                break;
            }
        }
        if (flag) {
            tmpAns[i][4] = to_string(C);
        }
        string sss = "";
        for (int j = 0; j < 4; j++) {
            sss += tmpAns[i][j] + " ";
        }
        sss += tmpAns[i][4];
        answer.push_back(sss);
    }
    return answer;
}