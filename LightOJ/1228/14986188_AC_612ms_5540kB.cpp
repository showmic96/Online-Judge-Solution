// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , k , q;
int dp[15][(1<<12)+10][16];
vector<int>v[15];

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int f(int last , int mask , int rem)
{
    if(rem<0)return 0;
    if(mask==(1<<n)-1){
        return 1;
    }

    if(dp[last][mask][rem]!=-1)return dp[last][mask][rem];
    int value = 0;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){

            bool c = false;
            for(int j=0;j<v[i].size();j++){

                if(v[i][j]==last)c = true;
            }

            if(c==true)value+=f(i , Set(mask , i) , rem-1);
            else value+=f(i , Set(mask , i) , rem);
        }
    }
    return dp[last][mask][rem] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));
        scanf("%d %d %d",&n , &k , &q);
        for(int i=0;i<n;i++){

            int si;
            scanf("%d",&si);
            v[i].clear();

            for(int j=0;j<si;j++){

                int in;
                scanf("%d",&in);
                v[i].push_back(in-1);
            }
        }

        printf("Case %d:\n",++c);

        while(q--){

            int in;
            scanf("%d",&in);
            if(k!=0)printf("%d\n",f(13 , 0 , min(13 , in/k)));
            else printf("%d\n",f(13 , 0 , 13));
        }
    }
    return 0;
}
