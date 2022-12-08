#include <bits/stdc++.h>
using namespace std;
string word = "AAAAE";
vector<string> ret;
char words[5] = {'A', 'E', 'I', 'O', 'U'};

// 미해결
void permu(vector<char> v, int n) {
    if (v.size() == n) {
        string s = "";
        for(int i = 0; i < n; i++) s += v[i];
        ret.push_back(s);
    } else {
        for (int i = 0; i < 5; i++) {
            v.push_back(words[i]);
            permu(v, i);
        }  
    }
}

int solution(string word) {
    int answer = 0;
    vector<char> v;
    for(int i = 1; i <= 5; i++) {
        permu(v, i);
        v.clear();
    }
    sort(v.begin(), v.end());
    answer = find(v.begin(), v.end(), word) - v.begin();
    return answer + 1;
}

int main(void) {
    cout << solution(word);
}