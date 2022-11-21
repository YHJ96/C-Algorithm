#include<bits/stdc++.h>
using namespace std;
string s = "3people unFollowed me";

/*
  1. split에 익숙하기 위해 사용
  2. 문자열을 원본으로 탐색하는 방법도 있음
*/

// split 함수 생성
vector<string> split(string input, string del) {
    vector<string> ret;
    int pos;
    string token;
    while(input.find(del) != string::npos) {
        pos = input.find(del);
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + del.length());
    }
    ret.push_back(input);
    return ret;
}

string solution(string s) {
    string answer = "";
    auto items = split(s, " ");
    for(string item: items) {
        for(int i = 0; i < item.length(); i++) {
            // 문자열이 첫 번째 문자열이면서 소문자에 해당하면 대문자로 치환
            if (i == 0 && (97 <= item[0] && item[0] <= 122)) {
                answer += toupper(item[0]);
            }
            // 문자열이 첫 번째 문자열이 아니면서 대문자에 해당하면 소문자로 치환
            else if (i != 0 && (65 <= item[i] && item[i] <= 90)) {
                answer += tolower(item[i]);
            }
            // 알파벳이 아니면 원본 그대로 사용
            else {
                answer += item[i];
            }
        }
        answer += " ";
    }
    // 문자열 정제
    return answer.substr(0, answer.length() - 1);
}

int main(void) {
    cout << solution(s);
}