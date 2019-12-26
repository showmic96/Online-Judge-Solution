// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
char x[1005];
int mp[26] , dp[1005][1005][2];
string s;

int f(int i , int j , int now)
{
    if(i==j){

        if(mp[s[i]-'A']==1)return 1;
        return 0;
    }
    if(i>j)return 0;

    if(dp[i][j][now]!=-1)return dp[i][j][now];

    int value = 0;

    if(now==1){

        if(s[i]!=s[j])return -1e9;
        if(mp[s[i]-'A']==0)return -1e9;

        value = f(i+1 , j-1 , 1)+2;
    }

    else{

        value = f(i , j , 1);
        value = max(value , f(i+1 , j , now));
        value = max(value , f(i , j-1 , now));
    }

    return dp[i][j][now] = value;
}

int main(void)
{
    memset(mp , 0 , sizeof(mp));

    for(int i=0;i<11;i++){

        mp[ar[i]-'A'] = 1;
    }

    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%s",&x);
        string ss(x);
        s = ss;

        printf("%d\n",f(0 , s.size()-1 , 0));
    }
    return 0;
}
