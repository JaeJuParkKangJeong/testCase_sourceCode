#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int solution(vector<int> a) {
    int answer = a.size();
    stack<int> stack;
    for(int comp : a){
        while(!stack.empty() && comp < stack.top()){
            stack.pop();
            if(!stack.empty())
                answer--;
        }
        stack.push(comp);
    }
    return answer;
}


int main(void){
     vector<int> arr  = {-234, -170, -160, 0, 77, 1, 2, 4};

     int result = solution(arr);

     cout << result << endl;

    return 0;

}
