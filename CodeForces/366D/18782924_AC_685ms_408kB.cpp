// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1005;
struct s{
    int v , l , r;
    s(int _v , int _l , int _r){
        v = _v;
        l = _l;
        r = _r;
    }
};
vector<s>edges[MAX];
set<int>st;
bool vis[MAX];
bool bfs(int n , int l , int r)
{
    memset(vis ,false , sizeof(vis));
    vis[1] = true;
    queue<int>current;
    current.push(1);
    while(!current.empty()){
        int u = current.front();
        current.pop();
        if(u==n)return true;
        for(auto it:edges[u]){
            int tl = it.l;
            int tr = it.r;
            int v = it.v;
            if(vis[v]==false&&tl<=l&&tr>=r){
                vis[v] = true;
                current.push(v);
            }
        }
    }
    return false;
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){
        int in1 , in2 , in3 , in4;
        scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);
        edges[in1].push_back(s(in2 , in3 , in4));
        edges[in2].push_back(s(in1 , in3 , in4));
        st.insert(in3);
    }
    int ans = -1;
    for(auto it:st){
        int low = it , hi = 1e6 , mid , t = 40;
        while(t--){
            mid = (hi+low)/2;
            if(bfs(n , it , mid)==true){
                low = mid+1;
                ans = max(ans , mid-it+1);
            }
            else hi = mid-1;
        }
    }
    if(ans<=0)printf("Nice work, Dima!\n");
    else printf("%d\n",ans);
    return 0;
}
