// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[105][100005];
bool visited[100005];
vector<ll>v;
int n;
ll counter;

void f(int i , int sum)
{
    if(i==n){
        if(visited[sum]==true)return ;
        counter+=sum;
        visited[sum] = true;
        return ;
    }
    if(vis[i][sum])return;
    vis[i][sum] = true;
    f(i+1 , sum+v[i]);
    f(i+1 , sum);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(vis , false , sizeof(vis));
        memset(visited , false , sizeof(visited));
        v.clear();

        scanf("%d",&n);
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        counter = 0;
        f(0 , 0);
        printf("%lld\n",counter);
    }
    return 0;
}
