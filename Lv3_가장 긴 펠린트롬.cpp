#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int solution(char* s) {
    int answer = 0;
    int length = strlen(s);
    int i, subLength, left, right;

    for(i=0;i<length;i++) {
        for(subLength = length;subLength>answer;subLength--) {
            left = i;
            right = i + subLength - 1;
            while(left<right && s[left] == s[right]) {
                left++;
                right--;
            }
            if(left>=right && answer < subLength) {
                answer = subLength;
            }
        }
    }

    return answer;
}

int main(){
    int ans;
    char str[100];

    while(true) {

        cout << "문자열을 입력하세요: ";

        cin >> str;

        ans = solution(str);

        cout << ans << endl;

    }
    return 0;
}
