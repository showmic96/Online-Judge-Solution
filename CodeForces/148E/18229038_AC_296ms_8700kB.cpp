// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
int n , m , lim , ar[105][105];
int dp1[105][105][105];
int dp2[105][10005];

int f1(int i , int j , int rem)
{
    if(i==j&&rem==1)return v[i];
    if(rem==0)return 0;
    if(i>j)return -1e9;
    if(dp1[i][j][rem]!=-1)return dp1[i][j][rem];
    int value = -1e9;
    value = max(value , f1(i+1 , j , rem-1)+v[i]);
    value = max(value , f1(i , j-1 , rem-1)+v[j]);
    return dp1[i][j][rem] = value;
}

int f2(int i , int tot)
{
    if(tot==m)return 0;
    if(i==n)return 0;
    if(dp2[i][tot]!=-1)return dp2[i][tot];
    int value = -1e9;

    for(int j=0;j<=100;j++){

        if(tot+j<=m)value = max(value , f2(i+1 , tot+j)+ar[i][j]);
        else break;
    }

    return dp2[i][tot] = value;
}

int main(void)
{
    scanf("%d %d",&n , &m);
    for(int i=0;i<n;i++){

        v.clear();
        scanf("%d",&lim);
        for(int j=0;j<lim;j++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }
        memset(dp1 , -1 , sizeof(dp1));
        for(int j=1;j<=lim;j++){

            ar[i][j] = f1(0 , lim-1 , j);
        }
    }
    memset(dp2 , -1 , sizeof(dp2));
    printf("%d\n",f2(0 , 0));
    return 0;
}
