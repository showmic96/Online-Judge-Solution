// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int a , int b)
{
    ll ans = 1;

    for(int i=0;i<b;i++){

        ans*=a;
        ans%=10;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int>v;

    ll n;
    for(int j=1;j<=110;j++){

        n = j;

        ll ans = 0;

        for(int i=1;i<=n;i++){

            ans+=f(i , i);
            ans%=10;
        }

        v.push_back(ans);
    }

    string ar;

    while(cin >> ar){

        if(ar=="0")break;

        n = 0;

        if(ar.size()>=2){

            n = ar[ar.size()-2]-'0';
        }

        n*=10;
        n+=ar[ar.size()-1]-'0';

        if(n==0)n=100;

        cout << v[n-1] << endl;
    }

    return 0;
}
