// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 200005;
struct s{
    ll u , v , w;
    s(ll _u , ll _v , ll _w){
        u = _u;
        v = _v;
        w = _w;
    }
};
bool cmp(s A , s B)
{
    return A.w<B.w;
}
ll par[MAX] , lvl[MAX];
vector<s>edges;
vector<pair<ll , ll > > v;
multiset<ll>st;
ll ans[MAX];

int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}

void Union(int x , int y)
{
    int u = Find(x);
    int v = Find(y);
    if(lvl[u]<lvl[v])swap(u , v);
    if(v==u)return ;
    par[v] = u;
    lvl[u]+=lvl[v];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;
    for(int i=0;i<n;i++)st.insert(1);
    for(int i=1;i<=n;i++){
        par[i] = i;
        lvl[i] = 1;
    }
    for(int i=0;i<n-1;i++){
        ll in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;
        edges.push_back(s(in1 , in2 , in3));
    }
    sort(edges.begin() , edges.end() , cmp);
    for(int i=0;i<m;i++){
        ll in;
        cin >> in;
        v.push_back({in , i});
    }
    sort(v.begin() , v.end());
    int j = 0;
    ll fin = 0;
    for(int i=0;i<m;i++){
        while(j<n-1&&v[i].first>=edges[j].w){
            ll t1 = lvl[Find(edges[j].u)];
            ll t2 = lvl[Find(edges[j].v)];
            if(Find(edges[j].u)==Find(edges[j].v)){j++;continue;}
            fin-=t1*(t1-1)/2LL;
            fin-=t2*(t2-1)/2LL;
            Union(edges[j].u , edges[j].v);
            ll t = lvl[Find(edges[j].u)];
            fin+=t*(t-1)/2LL;
            j++;
        }
        ans[v[i].second] = fin;
    }
    for(int i=0;i<m;i++){
        if(i)cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
