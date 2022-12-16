#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer,v;
    for(int i=s.size()-1; i>=0; i--){
        for(int j=i-1; ; j--){
            if(s[i] == s[j]){
                v.push_back(i-j);
                break;
            }
            else if(j <= 0){
                v.push_back(-1);
                break;
            }
        }
    }
    
    for(int i=v.size()-1; i>=0 ; i--)
        answer.push_back(v[i]);
   
    return answer;
}
