// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5+9;

int one[MAX+9], zero[MAX+9];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(one , 0 , sizeof(one));
    memset(zero , 0 , sizeof(zero));

    string ar , br;
    cin >> ar >> br;

    int si = br.size();

    for(int i=1;i<=si;i++){

        if(br[i-1]=='1')one[i] = 1;
        else zero[i] = 1;

        one[i] = one[i-1]+one[i];
        zero[i] = zero[i-1]+zero[i];
    }

    ll ans = 0;

    int dif = br.size()-ar.size();

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='1'){

            ans+=zero[i+dif+1]-zero[i];
        }

        else{

            ans+=one[i+dif+1]-one[i];
        }
    }

    cout << ans << endl;

    return 0;
}
