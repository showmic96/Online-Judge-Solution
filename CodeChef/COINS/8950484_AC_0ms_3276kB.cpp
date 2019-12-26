// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll , ll>mp;
ll value;

ll f(ll value)
{
    if(value<=0)return 0;
    if(value==1)return 1;
    if(value==2)return 2;

    if(mp[value]!=0)return mp[value];

    ll v = 0;

    v+= max(f(value/2) , value/2);
    v+= max(f(value/3) , value/3);
    v+= max(f(value/4) , value/4);

    mp[value] = v;

    return v;
}

int main(void)
{

    while(cin >> value){

        cout << f(value) << endl;
    }
    return 0;
}
