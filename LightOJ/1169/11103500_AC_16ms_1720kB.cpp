// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1005][2][2];

vector<int>l , r , lr , rl;
int n;

ll f(int i , int now , int first)
{
    //cout << i << " " << now << " " << first << endl;
    if(i==n-1){

        if(now==0)return l[i];
        else return r[i];
    }

    if(dp[i][now][first]!=-1)return dp[i][now][first];

    ll value = 1e9;

    if(first==0){

        value = f(i+1 , 0 , 1) + l[i];
        value = min(value , f(i+1 , 1 , 1)+l[i]+lr[i]);
        value = min(value , f(i+1 , 1 , 1)+r[i]);
        value = min(value , f(i+1 , 0 , 1)+r[i]+rl[i]);
    }

    else{

        if(now==0){

            value = f(i+1 , 0 , 1) + l[i];
            value = min(value , f(i+1 , 1 , 1) + l[i] + lr[i]);
        }

        else{

            value = f(i+1 , 1 , 1) + r[i];
            value = min(value , f(i+1 , 0 , 1) + r[i] + rl[i]);
        }
    }

    return dp[i][now][first] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));
        l.clear();
        r.clear();
        lr.clear();
        rl.clear();

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            l.push_back(in);
        }

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            r.push_back(in);
        }

        for(int i=0;i<n-1;i++){

            int in;
            scanf("%d",&in);
            lr.push_back(in);
        }

        for(int i=0;i<n-1;i++){

            int in;
            scanf("%d",&in);
            rl.push_back(in);
        }

        printf("Case %d: %lld\n",++c , f(0 , 0 , 0));
    }

    return 0;
}
