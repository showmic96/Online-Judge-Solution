// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2*1e5 + 9;

vector<int>v , idx[MAX+9];
ll dp[MAX+9];
int n;

ll f(int i)
{
    //cout << i << endl;
    if(i>=n-1)return 0;

    if(dp[i]!=-1)return dp[i];

    ll value = 1e9;

    if(upper_bound(idx[v[i]].begin() , idx[v[i]].end() , i+1)!=idx[v[i]].end()){
        //cout << pre << endl;
        int temp = upper_bound(idx[v[i]].begin() , idx[v[i]].end() , i) - idx[v[i]].begin();
        //cout << "tmep " << i << " " << v[i] << " " << idx[v[i]][temp] << endl;
        value = min(value , f(idx[v[i]][temp])+1);
    }

    value = min(value , f(i+1)+1);

    return dp[i] = value;

}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        for(int i=0;i<=MAX;i++){

            dp[i] = -1;

            idx[i].clear();
        }

        scanf("%d",&n);
        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);

            idx[in].push_back(i);
        }

        printf("%lld\n", f(0));

    }
    return 0;
}
