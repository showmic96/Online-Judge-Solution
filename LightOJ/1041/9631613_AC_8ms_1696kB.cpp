// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , v , w;

    node(int ut , int vt , int wt){

        u = ut;
        v = vt;
        w = wt;
    }
};

bool operator < (node A , node B)
{
    return A.w < B.w;
}

vector<node>v;

int parent[55];

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    parent[py] = px;
}

void Kruskal(int n)
{
    for(int i=0;i<=n;i++)parent[i] = i;

    int si = v.size();

    int ans = 0 , counter = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans+=v[i].w;
        Union(v[i].u , v[i].v);
        counter++;
    }

    //cout << n << " " << counter << endl;

    if(counter==n-1){

        printf("%d\n",ans);
    }

    else{

        printf("Impossible\n");
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();

        int n;
        scanf("%d",&n);
        int counter = 1;
        map<string, int>mp;

        for(int i=0;i<n;i++){
            string ar , br;
            int w;
            cin >> ar >> br >> w;

            if(mp[ar]==0){

                mp[ar] = counter++;
            }

            if(mp[br]==0){

                mp[br] = counter++;
            }

            v.push_back(node(mp[ar] , mp[br] , w));
        }

        sort(v.begin() , v.end());
        //cout << counter << endl;
        printf("Case %d: ",++c);
        Kruskal(counter-1);
    }
    return 0;
}
