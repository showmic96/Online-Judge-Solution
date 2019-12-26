// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[25][25];
vector<pair<int, int> > v;
int lim , dp[16][(1<<16)+10];

int dis(pair<int , int> A , pair<int , int> B)
{
    return max(abs(A.first-B.first) , abs(A.second-B.second));
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int Set(int n , int pos)
{
    return n|(1<<pos);
}

int f(int now , int mask)
{
    if(mask==(1<<lim)-1){

        return dis(v[0] , v[now]);
    }

    if(dp[now][mask]!=-1)return dp[now][mask];
    int value = 1e9;

    for(int i=1;i<v.size();i++){

        if(Check(mask , i)==false){

            value = min(value , f(i , Set(mask , i))+dis(v[now], v[i]));
        }
    }

    return dp[now][mask] = value;
}

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n , &m)==2){

        v.clear();
        for(int i=0;i<n;i++){

            scanf("%s",&ar[i]);
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='L')v.push_back({i , j});
            }
        }
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='#')v.push_back({i , j});
            }
        }
        lim = v.size();
        memset(dp , -1 , sizeof(dp));
        printf("%d\n",f(0 , 1));
    }
    return 0;
}
