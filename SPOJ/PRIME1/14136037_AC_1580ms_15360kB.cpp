// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll x)
{
    if(x==1)return false;
    if(x==2)return true;

    if(x%2==0)return false;

    for(ll i=3;i*i<=x;i+=2){

        if(x%i==0)return false;
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    bool space = false;

    while(t--){

        if(space)cout << endl;space = true;

        int n , m;
        cin >> n >> m;

        for(int i=n;i<=m;i++){

            if(check(i)==true)cout << i << endl;
        }
    }

    return 0;
}
