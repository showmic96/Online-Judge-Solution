// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    vector<int>v;
    int cost;

}combo[105];

vector<int>v;
int n , c;
int dp[8][10][10][10][10][10][10];

int f(int i , int i1 , int i2 , int i3 , int i4 , int i5 , int i6)
{
    if(i==c){

        int ans = 0;
        ans+=v[0]*i1;
        ans+=v[1]*i2;
        ans+=v[2]*i3;
        ans+=v[3]*i4;
        ans+=v[4]*i5;
        ans+=v[5]*i6;

        return ans;
    }

    if(dp[i][i1][i2][i3][i4][i5][i6]!=-1)return dp[i][i1][i2][i3][i4][i5][i6];

    int value = f(i+1 , i1 , i2 , i3 , i4 , i5 , i6);
    if(combo[i].v[0]<=i1&&combo[i].v[1]<=i2&&combo[i].v[2]<=i3&&combo[i].v[3]<=i4&&
       combo[i].v[4]<=i5&&combo[i].v[5]<=i6){

            value = min(value , f(i , i1-combo[i].v[0] ,i2-combo[i].v[1] ,i3-combo[i].v[2] ,
                                  i4-combo[i].v[3] ,i5-combo[i].v[4] ,i6-combo[i].v[5] )+combo[i].cost);
    }
    return dp[i][i1][i2][i3][i4][i5][i6] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        v.clear();
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.emplace_back(in);
        }
        while(v.size()<6)v.emplace_back(0);
        scanf("%d",&c);
        for(int i=0;i<=c;i++)combo[i].v.clear();

        for(int i=0;i<c;i++){

            for(int j=0;j<n;j++){

                int in;
                scanf("%d",&in);
                combo[i].v.emplace_back(in);
            }
            while(combo[i].v.size()<6)combo[i].v.emplace_back(0);
            int in;
            scanf("%d",&in);
            combo[i].cost = in;
        }

        int q;
        scanf("%d",&q);

        memset(dp , -1 , sizeof(dp));
        while(q--){

            vector<int>temp;
            for(int i=0;i<n;i++){

                int in;
                scanf("%d",&in);
                temp.emplace_back(in);
            }

            while(temp.size()<6)temp.emplace_back(0);

            printf("%d\n",f(0 , temp[0] , temp[1] , temp[2] , temp[3] , temp[4] , temp[5]));
        }
    }
    return 0;
}
