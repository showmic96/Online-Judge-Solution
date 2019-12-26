// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double n , m;
    while(cin >> n >> m){

        cout << ceil(n/(m-n)) + 1 << endl;
    }
    return 0;
}
