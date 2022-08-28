#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int div_num;
long long  n;

int main(void)
{
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            div_num++;
            if (div_num > 1)
                break ;
            n /= i;
            i--;
        }
    }
    if (div_num == 1)
        cout << "cubelover\n";
    else
        cout << "koosaga\n";
    return (0);
}
