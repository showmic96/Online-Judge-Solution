// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
vector<int>edges[MAX];
int ans[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int in1 , in2;
        cin >> in1 >> in2;
        edges[in1].push_back(i);
        edges[in2].push_back(i);
    }
    int mx = 0 , tp;
    memset(ans , -1 , sizeof(ans));

    for(int i=1;i<=n;i++){
        if(edges[i].size()>mx){
            mx = edges[i].size();
            tp = i;
        }
    }
    int now = 0;
    for(int i=0;i<edges[tp].size();i++){
        ans[edges[tp][i]] = now++;
    }
    for(int i=1;i<=n-1;i++){
        if(ans[i]==-1)ans[i] = now++;
        cout << ans[i] << endl;
    }

    return 0;
}
