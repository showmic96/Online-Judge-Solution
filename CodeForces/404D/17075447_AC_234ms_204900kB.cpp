// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000005][4][4] , MOD = 1e9+7;
string ar;

ll f(int i , int last , int now)
{
    if(i==ar.size()-1){

        if(i==0){

            if(ar[i]=='0')return 1;
            if(ar[i]=='*')return 1;
            if(ar[i]=='?')return 2;
        }

        if(ar[i]!='?'){

            if(now==0&&ar[i]!='0')return 0;
            if(now==1&&ar[i]!='1')return 0;
            if(now==2&&ar[i]!='2')return 0;
            if(now==3&&ar[i]!='*')return 0;
        }

        if(last==0&&now==0)return 1;
        if(last==0&&now==1)return 0;
        if(last==1&&now==3)return 1;
        if(last==3&&now==1)return 1;
        if(last==3&&now==3)return 1;
        if(last==3&&now==2)return 0;
        if(last==1&&now==0)return 1;
        if(last==1&&now==1)return 0;
        if(last==2&&now==3)return 1;
    }

    if(dp[i][last][now]!=-1)return dp[i][last][now];
    ll value = 0;

    if(i==0){

        if(ar[i]=='?'){

            value+=f(i+1 , 0 , 1);
            value+=f(i+1 , 0 , 0);
            value+=f(i+1 , 3 , 1);
            value+=f(i+1 , 3 , 2);
            value+=f(i+1 , 3 , 3);
            value+=f(i+1 , 1 , 3);
        }
        else if(ar[i]=='0'){

            value+=f(i+1 , 0 , 1);
            value+=f(i+1 , 0 , 0);
        }
        else if(ar[i]=='1'){

            value+=f(i+1 , 1 , 3);
        }
        else if(ar[i]=='2'){

            return dp[i][last][now] = 0;
        }
        else {

            value+=f(i+1 , 3 , 1);
            value+=f(i+1 , 3 , 2);
            value+=f(i+1 , 3 , 3);
        }
    }
    else{

        if(ar[i]!='?'){

            if(now==0&&ar[i]!='0')return dp[i][last][now] = 0;
            if(now==1&&ar[i]!='1')return dp[i][last][now] = 0;
            if(now==2&&ar[i]!='2')return dp[i][last][now] = 0;
            if(now==3&&ar[i]!='*')return dp[i][last][now] = 0;
        }


        if(last==0&&now==0){

            value+=f(i+1 , 0 , 1);
            value+=f(i+1 , 0 , 0);
        }

        if(last==1&&now==0){

            value+=f(i+1 , 0 , 1);
            value+=f(i+1 , 0 , 0);
        }

        if(last==0&&now==1){

            value+=f(i+1 , 1 , 3);
        }

        if(last==1&&now==3){

            value+=f(i+1 , 3 , 1);
            value+=f(i+1 , 3 , 3);
            value+=f(i+1 , 3 , 2);
        }

        if(last==1&&now==1){

            value+=f(i+1 , 1 , 3);
        }

        if(last==3&&now==1){

            value+=f(i+1 , 1 , 0);
            value+=f(i+1 , 1 , 1);
        }

        if(last==3&&now==2){

            value+=f(i+1 , 2 , 3);
        }

        if(last==3&&now==3){

            value+=f(i+1 , 3 , 3);
            value+=f(i+1 , 3 , 1);
            value+=f(i+1 , 3 , 2);
        }

        if(last==2&&now==3){

            value+=f(i+1 , 3 , 1);
            value+=f(i+1 , 3 , 3);
            value+=f(i+1 , 3 , 2);
        }
    }

    return dp[i][last][now] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> ar;
    memset(dp , -1 , sizeof(dp));

    cout << f(0 , 0 , 0) << '\n';

    return 0;
}
