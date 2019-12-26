// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 222;

typedef long long ll;

vector<ll>ar[MAX+9];
ll dp[MAX+9][MAX+9];
ll n , lim;

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        ar[i].clear();
    }
}

ll f(int i , int j , int si)
{
    if(i==lim-1)return ar[i][0];
    if(dp[i][j]!=-1)return dp[i][j];

    int si2 = ar[i+1].size();
    ll value1 = 0 , value2 = 0;

    if(si<si2){

        value1 = f(i+1 , j , si2) + ar[i][j];
        value2 = f(i+1 , j+1 , si2) + ar[i][j];

    }

    else{

        if(j==0){

            value1 = f(i+1 , j , si2) + ar[i][j];
        }

        else if(j==si-1){

            value1 = f(i+1 , j-1 , si2) + ar[i][j];
        }

        else{

            value1 = f(i+1 , j , si2) + ar[i][j];
            value2 = f(i+1 , j-1 , si2) + ar[i][j];
        }
    }


    return dp[i][j] = max(value1 , value2);
}

int main(void)
{
    int t;
    scanf("%d",&t);//cin >> t;
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));
        scanf("%lld",&n);//cin >> n;
        lim = 2*n - 1;

        setUp(lim);
        int c = 0;
        for(int j=0;j<n;j++){

            for(int k=0;k<=j;k++){

                ll in;
                scanf("%lld",&in);//cin >> in;

                ar[c].push_back(in);
            }

            c++;
        }

        for(int j=n-2;j>=0;j--){

            for(int k=0;k<=j;k++){

                ll in;
                scanf("%lld",&in);//cin >> in;

                ar[c].push_back(in);
            }

            c++;
        }

        printf("Case %d: %lld\n",i+1 , f(0 , 0 ,ar[0].size()));

        //cout << f(0 , 0 ,ar[0].size()) << endl;
    }

    return 0;
}
