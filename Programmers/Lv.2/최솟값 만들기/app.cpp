#include <bits/stdc++.h>
using namespace std;
vector<int> A = {1, 4, 2};
vector<int> B = {5, 4, 4};

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    // 최소값을 만들기 위해서 정렬을 한 곳은 오름차순 한 곳은 내림차순으로 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i < A.size(); i++) {
        // answer에 최소값 정제
        int sum = A[i] * B[i];
        answer += sum;
    }
    return answer;
}

int main(void) {
    cout << solution(A, B);
}