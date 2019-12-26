// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , k;
    cin >> n >> k;
    int first = 1 , last = k+1 , rem = k+2;

    while(first<last){

        cout << first << " " << last << " ";
        first++;
        last--;
    }

    if(first==last)cout << first << " ";

    for(int i=rem;i<=n;i++)cout << i << " ";
    cout << endl;

    return 0;
}
