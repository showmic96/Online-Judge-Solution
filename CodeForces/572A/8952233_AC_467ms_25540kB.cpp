// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6;
ll ar1[MAX+9] , ar2[MAX+9];

int main(void)
{
    ll na , nb , k , m , last;
    cin >> na >> nb;
    cin >> k >> m;

    map<ll ,int>mp;

    for(int i=0;i<na;i++)cin >> ar1[i];
    for(int i=0;i<nb;i++)cin >> ar2[i];

    sort(ar1 , ar1+na);
    sort(ar2 , ar2+nb);

    for(int i=0;i<na;i++){

        if(k>0){k--;mp[ar1[i]] = 1; last = ar1[i];}
    }
    for(int i=0;i<nb;i++){

        if(mp[ar2[i]]==0&&ar2[i]>last)m--;
    }

    if(k<=0&&m<=0)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
