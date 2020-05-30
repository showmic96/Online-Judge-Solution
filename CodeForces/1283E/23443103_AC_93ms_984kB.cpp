// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[200005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v)cin >> x;
    sort(v.begin() , v.end());
    memset(vis , false , sizeof(vis));
    int ans = 0;
    for(int i=0;i<n;i++){
        if(vis[v[i]-1]==false){
            ans++;
            vis[v[i]-1] = true;
        }
        else if(vis[v[i]]==false){
            ans++;
            vis[v[i]] = true;
        }
        else if(vis[v[i]+1]==false){
            ans++;
            vis[v[i]+1] = true;
        }
    }
    int t1 = ans;
    ans = 0;
    memset(vis , false , sizeof(vis));
    for(int i=0;i<n;i++){
        if(vis[v[i]-1]==true){

        }
        else if(vis[v[i]]==true){

        }
        else if(vis[v[i]+1]==true){

        }
        else{
            ans++;
            vis[v[i]+1] = true;
        }
    }
    cout << ans << " " << t1 << endl;
    return 0;
}
