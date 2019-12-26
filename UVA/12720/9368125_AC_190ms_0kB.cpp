// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll f(vector<ll>v)
{
    int si = v.size();

    ll temp = v[0];

    for(int i=1;i<si;i++){

        temp*=2;
        temp+=v[i];
        temp%=MOD;
    }

    return temp;
}

int main(void)
{
    int t , c = 0 ;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();

        vector<ll>v;

        if(si%2==1){

            v.push_back(ar[si/2]-'0');
        }

        int i = si/2 - 1;
        int j = si/2;

        if(si%2==1)j++;

        while(i!=-1){

            if(ar[i]>ar[j]){

                v.push_back(ar[i]-'0');
                v.push_back(ar[j]-'0');
            }
            else{

                v.push_back(ar[j]-'0');
                v.push_back(ar[i]-'0');

            }

            i--;
            j++;

        }

        ll ans = f(v);

        printf("Case #%d: %lld\n",++c , ans);
    }
    return 0;
}
