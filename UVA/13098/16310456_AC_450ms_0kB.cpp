// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
int ans[10000005];

int main(void)
{
    for(int i=0;i<=10000000;i++)ans[i] = 3;

    ll now = 1;

    for(ll i=2;now<=10000000;now+=i,i++){
        v.push_back(now);
        ans[now] = 1;
    }

    for(int i=0;i<v.size();i++){

        for(int j=i;j<v.size()&&v[i]+v[j]<=10000000;j++){

            ans[v[i]+v[j]] = min(ans[v[i]+v[j]] , 2);
        }
    }

    int n;
    while(scanf("%d",&n)==1){

        printf("%d\n",ans[n]);
    }

    return 0;
}
