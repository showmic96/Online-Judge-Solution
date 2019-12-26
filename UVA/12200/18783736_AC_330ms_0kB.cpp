// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int ar[] = {20 , 1 , 18 , 4 , 13 , 6 , 10 , 15 , 2 , 17 , 3 , 19 , 7 , 16 , 8 ,
    11 , 14 , 9 , 12 , 5};
bool vis[505][505][2][105];
double dp[505][505][2][105];

double f(int i , int j , int now , int tot)
{
    if(tot>100)return 0;
    if(i==0&&now==0)return 0;
    if(j==0&&now==1)return 1;
    if(vis[i][j][now][tot]==true)return dp[i][j][now][tot];
    vis[i][j][now][tot] = true;
    double value = 0;
    if(now==0){
        for(int i1=0;i1<20;i1++){
            if(i-ar[i1]>=0)value+=f(i-ar[i1] , j , now^1 , 0)*(1.00/20.00);
            else value+=f(i , j , now^1 , tot+1)*(1.00/20.00);
        }
    }
    else{
        for(int i1=0;i1<20;i1++){
            double temp = 0;
            if(j-ar[i1]>=0)temp+=f(i , j-ar[i1] , now^1 , 0)*(1.00/3.00);
            else temp+=f(i , j , now^1 , tot+1)*(1.00/3.00);
            if(j-ar[(i1+1)%20]>=0)temp+=f(i , j-ar[(i1+1)%20] , now^1 , 0)*(1.00/3.00);
            else temp+=f(i , j , now^1 , tot+1)*(1.00/3.00);
            if(j-ar[(i1-1+20)%20]>=0)temp+=f(i , j-ar[(i1-1+20)%20] , now^1 , 0)*(1.00/3.00);
            else temp+=f(i , j , now^1 , tot+1)*(1.00/3.00);
            value = max(value , temp);
        }
    }
    return dp[i][j][now][tot] = value;
}
int main(void)
{
    memset(vis , false , sizeof(vis));
    int n;
    while(scanf("%d",&n)==1){
        if(!n)break;
        printf("%.14f %.14f\n",1-f(n , n , 0 , 0),f(n , n ,1 , 0));
    }
    return 0;
}
