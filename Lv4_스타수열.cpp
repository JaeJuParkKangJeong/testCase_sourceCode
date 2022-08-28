#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[500005];
bool check[500005];

int solution(std::vector<int> a) {

    int max_cnt = 0;
    int max_num;

    for (int i = 0; i < a.size(); ++i) {
        cnt[a[i]]++;
        if (cnt[a[i]] > max_cnt) {
            max_cnt = cnt[a[i]];
            max_num = a[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < a.size() - 1;) {
        if (((a[i] == max_num && a[i+1] != max_num)||
             (a[i] != max_num && a[i+1] == max_num))&&
            !check[i] && !check[i+1] ) {

            ans++;
            check[i] = check[i + 1] = true;
            i += 2;
        }
        else {
            i++;
        }
    }

    return ans*2;
}


int main(){

    int res;

    vector<int> input = {0,1,2,4,3,5};

    res = solution(input);

    cout << res << endl;


    return 0;
}
