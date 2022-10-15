#include <bits/stdc++.h>
using namespace std;
vector<int> v = { -2, 3, 0, 2, -5 };

int solution(vector<int> number) {
    int ret = 0;
    // n개 중에 3개를 뽑는 방법을 수행
    for(int i = 0; i < number.size(); i++) {
        for(int j = i + 1; j < number.size(); j++) {
            for(int k = j + 1; k < number.size(); k++) {
                int sum = number[i] + number[j] + number[k];
                if (sum == 0) ret++;
            }
        }
    }
    return ret;
}

int main(void) {
    cout << solution(v);
}