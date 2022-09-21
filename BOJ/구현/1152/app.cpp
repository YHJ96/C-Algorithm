#include <bits/stdc++.h>
using namespace std;
string s;

// 시간 초과
vector<string> split(string input, string delmiter) {
    vector<string> ret;
    int pos = 0;
    string token;
    while(input.find(delmiter) != string::npos) {
        pos = input.find(delmiter);
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delmiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    cout << split(s, " ").size();
}