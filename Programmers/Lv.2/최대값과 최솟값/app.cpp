#include <bits/stdc++.h>
using namespace std;
string s = "1 2 3 4";

// 문자열을 나누는 split 함수 생성
vector<string> split(string input, string delmiter) {
    vector<string> ret;
    int pos = 0;
    string token;
    while(input.find(delmiter) != string::npos) {
        // 해당 인덱스 추출
        pos = input.find(delmiter);
        // 해당 delmiter 전의 문자열 정제
        token = input.substr(0, pos);
        // vector에 문자 추가
        ret.push_back(token);
        // 해당 요소를 delmiter의 길이를 합쳐서 삭제
        input.erase(0, pos + delmiter.length());
    }
    // 마지막 요소 push
    ret.push_back(input);
    return ret;
}

string solution(string s) {
    int _min = 987654321;
    int _max = -987654321;
    vector<int> num;
    vector<string> ret = split(s, " ");
    // 형변환
    for(auto item: ret) {
        int toInt = stoi(item);
        num.push_back(toInt);
    }
    // 최대값, 최솟값 정제
    for(auto item: num) {
        _min = min(_min, item);
        _max = max(_max, item);
    }
    // 형변환
    return to_string(_min) + " " + to_string(_max); 
}

int main(void) {
    cout << solution(s);
}