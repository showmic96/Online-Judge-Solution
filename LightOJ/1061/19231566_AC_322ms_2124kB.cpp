// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[9][(1<<8)+10];
int board[8][8] , ans , cnt = 0;
char ar[10][10];
vector<pair<int , int> > v , temp[1005];

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}
bool possible(int x , int y)
{
    for(int i=1;i<8;i++){
        if(x-i>=0&&board[x-i][y]==1)return false;
        if(x-i>=0&&y-i>=0&&board[x-i][y-i]==1)return false;
        if(x-i>=0&&y+i<8&&board[x-i][y+i]==1)return false;
    }
    return true;
}
int dis(pair<int , int>x , pair<int , int>y)
{
    if(x.first==y.first&&y.second==x.second)return 0;
    if(x.first==y.first||x.second==y.second||(abs(x.first-y.first)==abs(x.second-y.second)))return 1;
    return 2;
}
int f(int i , int mask , int now)
{
    if(i==8)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int value = 1e7;
    for(int j=0;j<8;j++){
        if(Check(mask , j)==false){
            value = min(value , f(i+1 , Set(mask , j) , now)+dis(v[j] , temp[now][i]));
        }
    }
    return dp[i][mask] = value;
}
void gen(int i , int j)
{
    if(i==8){
        for(int i1=0;i1<8;i1++){
            for(int j1=0;j1<8;j1++){
                if(board[i1][j1]==1)temp[cnt].push_back(make_pair(i1 , j1));
            }
        }
        cnt++;
        return ;
    }
    for(int j1=0;j1<8;j1++){
        if(possible(i , j1)==true){
            board[i][j1] = 1;
            gen(i+1 , 0);
            board[i][j1] = 0;
        }
    }
    return ;
}

int main(void)
{
    memset(board , 0 , sizeof(board));
    gen(0 , 0);
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<8;i++)scanf("%s",&ar[i]);
        v.clear();
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(ar[i][j]=='q')v.push_back(make_pair(i , j));
            }
        }
        int ans = 1e7;
        for(int i=0;i<cnt;i++){
            memset(dp , -1 , sizeof(dp));
            ans = min(ans , f(0 , 0 , i));
        }
        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
