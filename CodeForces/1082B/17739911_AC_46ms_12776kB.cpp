// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , dp[100005][4][2][2];
string ar;

int f(int i , int now , int s1 , int s2)
{
    if(i==n){

        if(s1==s2)return 0;
        return -1e9;
    }
    if(dp[i][now][s1][s2]!=-1)return dp[i][now][s1][s2];
    int value = -1e9;
    if(now==0){
        value = max(value , f(i+1 , now , s1 , s2));
        if(ar[i]=='S'){

            value = max(value , f(i+1 , now+1 , s1 , 1)+1);
            value = max(value , f(i+1 , now , s1 , 1));
        }
        if(ar[i]=='G'){

            value = max(value , f(i+1, now+1 , s1 , s2)+1);
            value = max(value , f(i+1 , now , 1 , s2));
        }
    }
    if(now==1){

        if(ar[i]=='G'){
            value = max(value , f(i+1 , now , s1 , s2)+1);
            value = max(value , f(i+1 , now+1 , s1 , s2)+1);
            value = max(value , f(i+1 , now+1 , 1 , s2));
        }
        else {

            if(s2==0){
                value = max(value , f(i+1 , now , s1 , 1)+1);
                value = max(value , f(i+1 , now+1 , s1 , 1)+1);
            }
            value = max(value , f(i+1 , now+1 , s1 , s2));
        }
    }

    if(now==2){

        if(ar[i]=='S'){
            value = max(value , f(i+1, now , s1 , s2));
            value = max(value , f(i+1 , now , s1 , 1));
        }
        else{

            value = max(value , f(i+1 , now , s1 , s2));
            value = max(value , f(i+1 , now , 1 , s2));
        }
    }

    return dp[i][now][s1][s2] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> ar;
    memset(dp , -1 , sizeof(dp));
    cout << f(0 , 0 , 0 , 0) << endl;

    return 0;
}
