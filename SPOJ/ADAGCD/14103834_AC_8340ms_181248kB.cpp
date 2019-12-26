// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e7+9;
int hv[MAX+9] , prime[MAX+9] , cnt[MAX+9] , ar[MAX+9];
ll MOD = 1e9+7;

void seive()
{
    for(int i=0;i<=MAX;i++)prime[i] = i;

    for(int i=2;i<=MAX;i++){

        if(prime[i]==i){

            for(int j=2*i;j<=MAX;j+=i){

                prime[j] = i;
            }
        }
    }
}

ll BM(ll a , ll b , ll M)
{
    if(b==0)return 1%M;
    ll x = BM(a , b/2 , M);
    x = (x*x)%M;

    if(b%2==1)x = (x*a)%M;
    return x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    seive();

    int n , t;
    cin >> n;

    for(int i=0;i<=10000005;i++)ar[i] = 1e9;
    memset(hv , 0 , sizeof(hv));
    memset(cnt , 0 , sizeof(cnt));

    t = n;

    while(t--){

        int m;
        cin >> m;

        set<int>st;

        for(int i=0;i<m;i++){

            int in;
            cin >> in;

            while(in>1){

                int temp = prime[in];

                st.insert(temp);

                while(in%temp==0){

                    hv[temp]++;
                    in/=temp;
                }
            }
        }

        for(set<int>::iterator it = st.begin();it!=st.end();it++){

            cnt[*it]++;
            ar[*it] = min(ar[*it] , hv[*it]);
            hv[*it] = 0;
        }
    }

    ll ans = 1;

    for(int i=2;i<=MAX;i++){

        if(cnt[i]==n){

            ans*=BM(i , ar[i] , MOD);
            ans%=MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
