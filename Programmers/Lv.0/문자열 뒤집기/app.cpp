#include <bits/stdc++.h>
using namespace std;
string my_string = "jaron";

string solution(string my_string) {
    // reverse를 이용해서 문자열을 뒤집기
    reverse(my_string.begin(), my_string.end());
    return my_string;
}

int main(void) {
    cout << solution(my_string);
}