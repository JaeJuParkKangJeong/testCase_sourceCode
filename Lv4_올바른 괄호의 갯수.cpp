#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cnt;

int dfs(int right,int left,int n)
{
    if(right > n || left > n )  return 0;
    if(right < left)            return 0;
    if(left == n)
    {
        cnt++;
        return 1;
    }
    dfs(right+1,left,n);
    dfs(right,left+1,n);
}


int solution(int n) {
    dfs(1,0,n);
    int answer = cnt;
    return answer;
}

int main(){

    int input;
    int res;

    printf("입력해: ");
    scanf("%d", &input);

    res = solution(input);

    printf("%d\n", res);


    return 0;
}