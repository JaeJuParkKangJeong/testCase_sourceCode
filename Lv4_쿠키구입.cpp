#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> coo) { // 0 ~ n-1
    int ans = 0;
    int n = coo.size();

    for(int i=0; i < n-1; ++i) { // 0 ~ n-2
        int lo = i, hi = i;
        int left = coo[i], right = 0;
        while(1) { // lo : [0, i], hi : (i, n-1]
            if(left <= right) {
                lo--;
                if(lo == -1) break;
                left += coo[lo];
            }
            else {
                hi++;
                if(hi == n) break;
                right += coo[hi];
            }

            if(left == right) ans = max(ans, left);
        }
    }

    return ans;
}
int main(){

    int res;

    vector<int> input = {500, 10, 200, 11, 1, 1};

    res = solution(input);

    cout << res << endl;


    return 0;
}