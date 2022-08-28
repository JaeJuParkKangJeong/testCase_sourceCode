#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(a == 0) return b;
    return GCD(b % a, a);
}

long long solution(int w,int h)
{
    long long answer = 1;

    int gcd = GCD(w, h);
//    cout << w + h - gcd;
    answer = ((long)w * h) - ((long)w + h - gcd);

    return answer;
}


int main(){

    int w, h, res;
while(true) {
    cout << "입력해: ";
//    cin >> w;
//    cout << "입력해: " ;
//    cin >> h;

    cin >> w >> h;


    res = solution(w, h);

    cout << res << endl;
}
    return 0;
}