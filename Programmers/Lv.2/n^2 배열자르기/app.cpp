#include <bits/stdc++.h>
using namespace std;
int n = 3;
long long lf = 2; 
long long rg = 5;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ret;
    for(long long i = left; i <= right; i++) {
        // 해당 좌표의 y값은 나누기의 몫
        int y = i / n;
        // 해당 좌표의 x값은 나누기의 나머지
        int x = i % n;
        // 좌표 + 1 값이 해당 숫자의 값.
        int pos = max(y, x) + 1;
        ret.push_back(pos);
    }
    return ret;
}

int main(void) {
   vector<int> v = solution(n, lf, rg);
   for(auto item: v) cout << item << " ";
}