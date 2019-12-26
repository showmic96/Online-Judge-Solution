// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;

        cout << ar[0] - '0' + ar[ar.size()-1]-'0' << endl;
    }

    return 0;
}