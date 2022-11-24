#include <bits/stdc++.h>
using namespace std;
string s = "110010101001";

vector<int> solution(string s) {
    vector<int> answer = {0, 0};

    while(s != "1") {
        answer[0]++;
        string temp = "";
        // 단계별 정제
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '1') temp += '1';
            else answer[1]++;
        }

        int t1 = temp.size();
        string t2 = "";
        // 2진법 치환
        while(t1 != 0) {
            if (t1 % 2 == 0) {
                t1 /= 2;
                t2 += "0";
            } else {
                t1 /= 2;
                t2 += "1";
            }
        }
        // 2진법의 원형 모형을 위해 뒤집기
        reverse(t2.begin(), t2.end());
        s = t2;
    }
    
    return answer;
}