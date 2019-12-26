// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5;

ll dp[MAX+9];
string ar;
int si;

ll f(int i)
{
    if(i==si)return 1;
    if(i>si)return 0;

    if(dp[i]!=-1)return dp[i];

    if(ar[i]=='0')return 0;

    ll v = f(i+1);

    if(i+1<si){

        string temp = "";
        temp+=ar[i];
        temp+=ar[i+1];

        stringstream ss(temp);

        int t;

        ss >> t;

        if(t<=26)v+=f(i+2);
    }

    return dp[i] = v;
}

int main(void)
{
    while(cin >> ar){

        if(ar=="0")break;
        memset(dp , -1 , sizeof(dp));

        si = ar.size();

        cout << f(0) << endl;
    }

    return 0;
}
