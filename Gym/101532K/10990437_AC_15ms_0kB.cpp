// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll fact[21];
    fact[0] = 1;

    for(ll i = 1;i<21;i++)fact[i] = i*fact[i-1];

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        string ar;

        cin >> ar;

        int fr[26] , counter = 0;

        memset(fr , 0 , sizeof(fr));

        for(int i=0;i<n;i++){

            fr[ar[i]-'a']++;
        }

        for(int i=0;i<26;i++){

            if(fr[i]%2==1)counter++;
        }



        if(counter>1){

            cout << 0 << endl;
        }

        else{

            vector<int>store;
            int sum = 0;

            for(int i=0;i<26;i++){

                if(fr[i]!=0)sum+=fr[i]/2 , store.push_back(fr[i]/2);
            }

            ll ans = fact[sum];

            int si = store.size();

            for(int i=0;i<si;i++){

                ans/=fact[store[i]];
            }

            cout << ans << endl;
        }
    }

    return 0;
}
