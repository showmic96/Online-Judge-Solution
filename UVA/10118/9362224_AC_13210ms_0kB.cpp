// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[42][42][42][42];

int n;
int ar[42][4];

int f(int i1, int i2 , int i3 , int i4 ,int v, int ans , map<int,int>mp)
{
    if(v>5)return ans;

    if(i1==n&&i2==n&&i3==n&&i4==n){

        for(int i=1;i<=40;i++){

            if(mp[i]==2){

                ans++;
                mp[i] = 0;
                v-=2;
            }
        }

        return ans;
    }

    if(dp[i1][i2][i3][i4]!=-1)return dp[i1][i2][i3][i4];

    for(int i=1;i<=40;i++){

        if(mp[i]==2){

            ans++;
            mp[i] = 0;
            v-=2;
        }
    }

    int value = 0;

    if(i1<n){

        mp[ar[i1][0]]++;
        int temp =f(i1+1 , i2 , i3 , i4 , v+1 , ans , mp);
        mp[ar[i1][0]]--;

        value = max(value , temp);
    }

    if(i2<n){

        mp[ar[i2][1]]++;
        int temp =f(i1 , i2+1 , i3 , i4 , v+1 , ans , mp);
        mp[ar[i2][1]]--;
        value = max(value , temp);
    }

    if(i3<n){

        mp[ar[i3][2]]++;
        int temp =f(i1 , i2 , i3+1 , i4 , v+1 , ans , mp);
        mp[ar[i3][2]]--;
        value = max(value , temp);
    }

    if(i4<n){

        mp[ar[i4][3]]++;
        int temp =f(i1 , i2 , i3 , i4+1 , v+1 ,ans, mp);
        mp[ar[i4][3]]--;

        value = max(value , temp);
    }

    return dp[i1][i2][i3][i4] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(!n)break;
        memset(dp , -1 , sizeof(dp));
        for(int i=0;i<n;i++){

            for(int j=0;j<4;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        map<int, int>mp;

        int ans = f(0 , 0 , 0 , 0 ,0 ,0,mp);

        printf("%d\n",ans);
    }

    return 0;
}
