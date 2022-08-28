#include<stdio.h>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;
int a[100001], c[100001];
vector<int> v;
stack<int> st;
long long solve(int n, int i){
    long long j=1, cnt=0;
    while(1){
        if(n/((long long)v[i]*j)) cnt+=n/((long long)v[i]*j);
        else break;
        j*=v[i];
    }
    return cnt;
}
void nprime(int n){
    int i=2, j, cnt;
    st.push(1);
    for(; n!=1; i++)
        if(!(n%i)){
            st.push(i);
            while(!(n%i)) c[i]++, n/=i;
        }
}
void prime(int n){
    int i=2, j;
    a[1]=1;
    for(; i<=n; i++){
        j=2;
        while(i*j<=n)
            a[i*j]=1, j++;
    }
    for(i=2; i<=n; i++)
        if(!a[i])
            v.push_back(i);
}
int main(){
    int i, s, k, m, ans=1, cnt;
    scanf("%d%d%d",&s,&k,&m);
    prime(m);
    memset(a, 0, sizeof(a));
    a[1]=1;
    for(i=0; i<v.size(); i++)
        a[v[i]]+=solve(s+k,i)-solve(s,i)-solve(k,i);
    for(i=m; i>1; i--){
        memset(c, 0, sizeof(c));
        while(!st.empty()) st.pop();
        nprime(i);
        cnt=0;
        while(!st.empty())
            if(c[st.top()]>a[st.top()]){
                cnt=1;
                break;
            }
            else
                st.pop();
        if(!cnt){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
}