// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int four = 0 , seven = 0;

    seven = (n/7);

    while(four*4 + seven*7 != n){

        if(four*4 + seven*7<n)four++;
        else seven--;

        if(seven<0){

            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=0;i<four;i++)cout << 4;
    for(int i=0;i<seven;i++)cout << 7;
    cout << endl;

    return 0;
}
