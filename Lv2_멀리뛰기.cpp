#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned long long dp[2000];

long long solution(int n)
{
    unsigned long long answer = 0;
    unsigned long long bNum = 0;
    unsigned long long nNum = 1;

    for (int i = 0; i < n; i++)
    {
        answer = (bNum + nNum) % 1234567;
        bNum = nNum;
        nNum = answer;
    }
    return answer % 1234567ULL;
}



int main(){
    int n;
    int res;

    while(1){
        printf("n 입력해: ");
        scanf("%d", &n);

        res = solution(n);

        printf("%d\n",res);
    }

    return 0;
}