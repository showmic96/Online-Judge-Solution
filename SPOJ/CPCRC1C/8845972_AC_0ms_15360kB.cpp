// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>ar;
int si;

ll dp[22][1234][2];

ll f(int i , int value , int smaller)
{
    if(i==si)return value;

    if(dp[i][value][smaller]!=-1)return dp[i][value][smaller];
    int lim ;

    if(smaller==1){

        lim = 9;
    }

    else lim = ar[i];

    ll v = 0;

    for(int j=0;j<=lim;j++){

        if(j<lim)v+=f(i+1 , value+j ,1);
        else v+=f(i+1 , value+j , smaller);
    }

    return dp[i][value][smaller] = v;
}

void make_ar(ll a)
{

    ar.clear();

    if(a==0)ar.push_back(0);

    while(a!=0){

        ar.push_back(a%10);
        a/=10;
    }

    reverse(ar.begin() , ar.end());
    si = ar.size();

    //for(int i=0;i<si;i++)cout << ar[i];
    //cout << endl;
}

int main(void)
{
    ll a , b;
    while(cin >> a >> b){

        if(a==-1&&b==-1)return 0;

        make_ar(a-1);

        memset(dp , -1 , sizeof(dp));

        ll value1 = f(0 , 0 , 0);

        memset(dp , -1 , sizeof(dp));

        make_ar(b);

        ll value2 = f(0 , 0 , 0);

        cout << value2 - value1 << endl;
    }
    return 0;
}
