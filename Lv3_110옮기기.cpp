#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include<iostream>
using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;

    for (auto elem : s)
    {
        string prev = "";

        stack<char> St;
        stack<char> Qu;
        int count110 = 0;
        for (auto it = elem.rbegin(); it != elem.rend(); it++)
            St.push(*it);
        while (St.size() >= 3)
        {
            string part = "";
            part += St.top();
            St.pop();
            part += St.top();
            St.pop();
            part += St.top();
            St.pop();
            if (part == "110")
            {
                for (int i = 0; i < 2; i++)
                {
                    if (Qu.empty())
                        continue;
                    St.push(Qu.top());
                    Qu.pop();
                }
                count110++;
            }

            else
            {
                St.push(part[2]);
                St.push(part[1]);
                Qu.push(part[0]);
            }
        }
        while (!Qu.empty())
        {
            prev += Qu.top();
            Qu.pop();
        }
        reverse(prev.begin(), prev.end());
        while (!St.empty())
        {
            prev += St.top();
            St.pop();
        }
        bool flag = true;
        for (int i = 0; i < prev.length(); i++)
        {
            if (prev[i] == '0')
                flag = false;
        }
        if (flag)
        {
            string s110 = "";
            while (count110--)
                s110 += "110";
            answer.push_back(s110 + prev);
        }
        else
        {
            int countOne = 0;
            string s110 = "";
            bool found = false;
            string ANS = "";
            while (count110--)
                s110 += "110";
            for (int i = 0; i < prev.length(); i++)
            {
                if (prev[i] == '1')
                {
                    countOne++;
                    if (countOne == 3)
                    {
                        ANS = string(prev.begin(), prev.begin() + i - 2) + s110 + string(prev.begin() + i - 2, prev.end());
                        found = true;
                        break;
                    }
                }
                else
                {
                    countOne = 0;
                }
            }
            if (!found)
            {
                ANS = string(prev.begin(), prev.end() - countOne) + s110 + string(prev.end() - countOne, prev.end());
            }
            answer.push_back(ANS);
        }
    }

    return answer;
}




int main(){

//    vector<string> arr = {"10010","100","1111111010", 101010, 01010};
    vector<string> arr(5);

    cout << "?????????: " ;

    for(int i = 0; i < arr.size(); i++) {
        cin >> arr.at(i);
    }

    vector<string> res;

    res = solution(arr);

    for(int i = 0; i < res.size(); i++) {
        cout << res.at(i);
        cout << " ";
    }

    cout<<endl;

    return 0;
}