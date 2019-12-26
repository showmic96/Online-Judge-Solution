// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t , c = 0;
    cin >> t;

    while(t--){

        string ar;
        cin >> ar;

        int fr[1010];
        memset(fr , 0 , sizeof(fr));

        int n = 0 , m = 0;

        for(int i=0;i<ar.size();i++){

            if(ar[i]=='!'){

                m++;
                continue;
            }

            n*=10;
            n+=ar[i]-'0';
        }

        for(int i=n;i>=0;i-=m){

            ll temp = i;

            for(ll j=2;j<=temp;j++){

                if(temp%j==0){

                    while(temp%j==0){

                        temp/=j;
                        fr[j]++;
                    }
                }
            }
        }

        ll ans = 1;
        double dig = 0;

        for(int i=2;i<=1000;i++){

            ll temp = fr[i] + 1;
            ans*=temp;
            dig+=log10(temp);
        }

        cout << "Case " << ++c << ": ";

        if(ceil(dig)>18)cout << "Infinity" << endl;
        else cout << ans << endl;
    }

    return 0;
}
