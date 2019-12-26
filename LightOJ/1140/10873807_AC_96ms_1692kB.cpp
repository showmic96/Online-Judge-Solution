// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[13][13][2][2];
int si;

string ar;

ll f(int i , int value , int smaller , int first)
{
    if(i==si){

        return value;
    }

    if(dp[i][value][smaller][first]!=-1)return dp[i][value][smaller][first];

    int lim;

    if(smaller==1)lim = 9;
    else lim = ar[i] - '0';

    ll v = 0;

    if(first==0){

        for(int j=0;j<=lim;j++){

            if(j<lim){

                v+=f(i+1 , (j==0)+value , 1 , 0);
            }

            else{
                v+=f(i+1 , (j==0)+value , smaller , 0);
            }
        }
    }

    else{

        for(int j=1;j<=lim;j++){

            if(j<lim){

                v+=f(i+1 , (j==0)+value , 1 , 0);
            }

            else{
                v+=f(i+1 , (j==0)+value , smaller , 0);
            }
        }

        v+=f(i+1 , 0 , 1 , 1);
    }

    return dp[i][value][smaller][first] = v;
}

string toString (ll n)
{
    string ar = "";

    while(n!=0){

        ar+= (n%10) + '0';
        n/=10;
    }

    return ar;
}

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));

        ll m , n;

        scanf("%lld %lld",&m, &n);

        ar = toString(m-1);

        reverse(ar.begin(), ar.end());
        int a1 = 1 , a2 = 1;
        if(ar[0]=='/')a1 = 0;
        if(n<0)a2 = 0;
        si = ar.size();
        m = f(0 , 0 , 0 , 1)+a1;

        ar = toString(n);
        reverse(ar.begin() , ar.end());

        memset(dp , -1 , sizeof(dp));
        si = ar.size();
        n = f(0 , 0 , 0 , 1)+a2;

        printf("Case %d: %lld\n",i+1,n-m);

    }
    return 0;
}
