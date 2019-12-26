// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a , b, k;

ll dp[10][83][83][2];

int si;

string ar;

string toString (ll n)
{
    string ar = "";

    while(n!=0){

        ar+= (n%10) + '0';
        n/=10;
    }

    reverse(ar.begin() , ar.end());

    //if(ar.size()==0)ar="0";

    return ar;
}

ll f(int i , int value , int sum , int smaller)
{
    //cout << i << " " << value << " " << sum << " " << smaller << endl;
    if(i==si){

        if(value==0&&sum==0)return 1;
        return 0;
    }

    if(dp[i][value][sum][smaller]!=-1)return dp[i][value][sum][smaller];

    int lim = 9;

    if(smaller==0)lim = ar[i]-'0';

    ll v = 0;

    for(int j=0;j<=lim;j++){

        if(j<lim)
            v+=f(i+1 , (value*10+j)%k , (sum+j)%k , 1);

        else v+=f(i+1 , (value*10+j)%k , (sum+j)%k , smaller);
    }

    return dp[i][value][sum][smaller] = v;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        scanf("%lld %lld %lld",&a , &b , &k);

        if(a>b)swap(a , b);

        memset(dp , -1 , sizeof(dp));

        if(k>81)printf("Case %d: 0\n",i+1);
        else{

            ar = toString(a-1);
            si = ar.size();
            ll m = f(0 , 0 , 0 , 0);
//cout << ar << endl;
            memset(dp , -1 , sizeof(dp));

            ar = toString(b);
            si = ar.size();//cout << ar << endl;
            ll n = f(0 , 0 , 0 , 0);
            //cout << n << " " << m << endl;
            printf("Case %d: %lld\n",i+1, n-m);
        }
    }

    return 0;
}
