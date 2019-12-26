// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll , ll>mp;
ll counter = 0 , n;

void f(int i , ll val)
{
    if(i==min(11LL , n)){

        if(mp.find(val)==mp.end())counter++;
        mp[val] = 1;
        return ;
    }

    f(i+1 , val+1);
    f(i+1 , val+10);
    f(i+1 , val+5);
    f(i+1 , val+50);
}


int main(void)
{
    cin >> n;
    f(0 , 0);

    if(n>11)counter+=49LL*(n-11);
    cout << counter << endl;

    return 0;
}
