// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

vector<int>ar;
int n;

int dp[100005][4][2][4];

int f(int i , int sum , int j , int last)
{
    if(i==n-1)return 0;

    int value = 0 , temp_sum = sum , last_temp = last;

    if(j==0){

        value = max(value , f(i+1 , temp_sum , j , 2));
    }

    if(temp_sum==3)temp_sum = -1;
    if(last_temp==3)last_temp = -1;

    if(ar[i]!=0)if(ar[i]==temp_sum)return 0;
    if(ar[i]!=-1&&ar[i]!=0&&ar[i]!=1)return 0;
    if(ar[i]==last_temp)return 0;

    if(ar[i]!=0)last_temp = ar[i];

    if(last_temp==-1)last_temp = 3;

    if(dp[i][sum][j][last]!=-1)return dp[i][sum][j][last];

    if(ar[i]==-1)temp_sum = 3;
    else temp_sum = ar[i];

    if(j==0){

        value = max(value , f(i+1 , temp_sum , 1 , last_temp)+1);
    }

    else{

        value = max(f(i+1 , temp_sum , 1 , last_temp)+1,value);
    }

    return dp[i][sum][j][last] = value;
}

int main(void)
{
    scanf("%d",&n);

    int temp;
    scanf("%d",&temp);

    for(int i=1;i<n;i++){

        int in;
        scanf("%d",&in);
//cout << temp - in << endl;
        ar.push_back(temp-in);
        temp = in;
    }

    memset(dp , -1 , sizeof(dp));

    printf("%d\n",f(0 , 0 , 0 , 2)+1);

    return 0;
}
