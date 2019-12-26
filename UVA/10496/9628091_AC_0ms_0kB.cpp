// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[(1<<11)+10][21][21];
int n , lim;
int in1 , in2;
vector<pair<int , int> > v;

bool Check(int n  , int pos)
{
    return (n&(1<<pos));
}

int Set(int n , int pos)
{
    return (n|(1<<pos));
}

int dis(pair<int , int > p , int x , int y)
{
    return abs(p.first - x) + abs(p.second - y);
}

int f(int mask , int i1 , int j1)
{
    if(mask==lim)return dis(make_pair(in1 , in2) , i1 , j1);

    if(dp[mask][i1][j1]!=-1)return dp[mask][i1][j1];

    int value = 123456789;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){

            value = min(value , f(Set(mask , i) , v[i].first , v[i].second)+dis(v[i] , i1 , j1));
        }
    }

    return dp[mask][i1][j1] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%d %d",&in1 , &in2);
        scanf("%d %d",&in1 , &in2);

        scanf("%d",&n);
        memset(dp , -1 , sizeof(dp));
        lim = (1<<(n));
        lim--;
        //cout << lim << endl;
        for(int i=0;i<n;i++){

            int x , y;
            scanf("%d %d",&x , &y);
            v.push_back(make_pair(x , y));
        }

        printf("The shortest path has length %d\n",f(0 , in1 , in2));
    }
    return 0;
}
