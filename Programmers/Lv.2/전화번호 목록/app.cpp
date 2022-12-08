#include <bits/stdc++.h>
using namespace std;
vector<string> phone_book = {"119", "97674223", "1195524421"};

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++) {
        string compare = phone_book[i + 1].substr(0, phone_book[i].size());
        if(phone_book[i] == compare) {
            answer = false;
            return answer;
        }
    }
    return answer;
}

int main(void) {
    cout << solution(phone_book);
}