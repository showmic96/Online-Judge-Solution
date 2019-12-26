// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1005;

struct node{
    int u , v , w;
    node(int ut , int vt , int wt){
        u = ut;
        v = vt;
        w = wt;
    }
};

bool cmp(node A , node B)
{
    return A.w < B.w;
}

int par[MAX];
vector<node>v;
vector<int>ans;
bool inMST[MAX];

int Find(int x)
{
    if(x==par[x])return x;
    return par[x] = Find(par[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);
    par[py] = px;
}

void Kruskal(int n , int j)
{
    int temp = 0 , counter = 0;
    bool check = false;
    for(int i=0;i<=n;i++)par[i] = i;
    for(int i=0;i<v.size();i++){
        if(i==j)continue;
        if(Find(v[i].u)==Find(v[i].v)){
            continue;
        }
        Union(v[i].u , v[i].v);
        temp+=v[i].w;
        counter++;
    }
    if(counter==n-1)ans.push_back(temp);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){
        v.clear();
        int n , m;
        cin >> n >> m;
        for(int i=0;i<=n;i++)par[i] = i;
        while(m--){
            int in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;
            v.push_back(node(in1 , in2 , in3));
        }
        sort(v.begin() , v.end() , cmp);
        int counter = 0;
        memset(inMST , false , sizeof(inMST));
        for(int i=0;i<v.size();i++){
            if(Find(v[i].u)==Find(v[i].v)){
                continue;
            }
            Union(v[i].u , v[i].v);
            inMST[i] = true;
            counter++;
        }
        ans.clear();
        cout << "Case #" << ++c << " : ";
        if(counter!=n-1){
            cout << "No way" << endl;
        }
        else{
            for(int i=0;i<v.size();i++){
                if(inMST[i]==true)Kruskal(n , i);
            }
            if(ans.size()==0){
                cout << "No second way" << endl;
            }
            else{
                sort(ans.begin() , ans.end());
                cout << ans[0] << endl;
            }
        }
    }
    return 0;
}
