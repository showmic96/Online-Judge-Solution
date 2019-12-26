// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;

int ar[MAX+9] , br[MAX+9];

ll BM(ll a , ll b , ll MOD)
{
    if(b==0)return 1%MOD;
    ll x = BM(a , b/2 , MOD);

    x = (x*x)%MOD;

    if(b%2==0)x = (x*a)%MOD;

    return x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(ar , 0 , sizeof(ar));
    memset(br , 0 , sizeof(br));

    string s;
    cin >> s;

    ll m1 , m2;

    cin >> m1 >> m2;

    int si = s.size();

    ll t1 = 0 , t2 = 0;

    for(int i=0;i<si;i++){

        t1*=10;

        t1+=s[i]-'0';

        t1%=m1;

        ar[i] = t1;
    }

    br[si-1] = s[si-1]-'0';
    br[si-1]%=m2;
    t2 = 10;
    ll t = 0;
    bool check = false;
    for(int i=si-1;i>=0;i--){

        if(s[i]>'0')check = true;

        t = (s[i]-'0')*t2+t;
        t%=m2;
        br[i] = t;
        if(check==false)br[i] = -1;

        t2*=10;
        t2%=m2;
    }

    int idx = -1;

    for(int i=0;i<si-1;i++){

        if(ar[i]==0&&br[i+1]==0){

            idx = i;
            //break;
        }
    }

    if(idx==-1){cout << "NO" << endl;return 0;}
    else cout << "YES" << endl;

    for(int i=0;i<=idx;i++){

        cout << s[i];
    }

    cout << endl;

    for(int i=idx+1;i<si;i++){

        cout << s[i];
    }

    cout << endl;

    return 0;
}
