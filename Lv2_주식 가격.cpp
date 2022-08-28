#include <string>
#include <vector>
#include <stack>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}

int main(){

//    vector<string> arr = {"10010","100","1111111010", 101010, 01010};
    vector<int> arr(5);

//    cout << "입력해: " ;

    for(int i = 0; i < arr.size(); i++) {
        cin >> arr.at(i);
    }

    vector<int> res;

    res = solution(arr);

    for(int i = 0; i < res.size(); i++) {
        cout << res.at(i);
        cout << " ";
    }

    cout<<endl;

    return 0;
}