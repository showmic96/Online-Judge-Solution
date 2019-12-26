// In the name the Allah the Most Merciful.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
pair<ll , ll>dp[1005][1005];
vector<int>v1 , v2;
int n;

pair<ll , ll> f(int i , int j)
{
    if(i==n||j==n)return make_pair(0 , 0);
    if(dp[i][j].first!=-1)return dp[i][j];

    pair<ll , ll > temp;
    pair<ll , ll > t1 = f(i+1 , j);
    pair<ll , ll > t2 = f(i , j+1);
    pair<ll , ll > t3;
    t3.first = -1 , t3.second = -1;
    if(v1[i]==v2[j]){

        t3 = f(i+1 , j+1);
        t3.second += 1;
    }
    if(v1[i]>v2[j]){

        t3 = f(i+1 , j+1);
        t3.first+=200;
        t3.second+=1;
    }

    temp = t1;
    if(temp.first<t2.first){
        temp = t2;
    }
    else if(temp.first==t2.first&&temp.second<t2.second){
        temp = t2;
    }

    if(temp.first<t3.first){
        temp = t3;
    }
    else if(temp.first==t3.first&&temp.second<t3.second){
        temp = t3;
    }

    return dp[i][j] = temp;
}

int main(void)
{
    while(scanf("%d",&n)==1){
        if(n==0)break;
        v1.clear();v2.clear();
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            v1.push_back(in);
        }
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            v2.push_back(in);
        }
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){

                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }
        pair<ll , ll> ans = f(0 , 0);
        ll fin = ans.first - (n-ans.second)*200LL;

        printf("%lld\n",fin);
    }

    return 0;
}
