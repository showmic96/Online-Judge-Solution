#include<bits/stdc++.h>
using namespace std;

const int MAX = 19910;

struct Edge{

    string u ,v;
    int w;
};

bool operator<(Edge A , Edge B)
{
    return A.w > B.w;
}

map<string , string>parent;
vector<Edge>edges;

string Find(string x)
{
    if(parent[x]==x)return x;

    return parent[x] = Find(parent[x]);
}

void Union(string x, string y)
{
    parent[y]=x;
}

int Kruskal(string from , string to)
{
    sort(edges.begin(),edges.end());

    int si = edges.size();

    int ans = 1e9;

    for(int i=0;i<si;i++){

        string p = Find(edges[i].u) , q = Find(edges[i].v);

        if(p!=q){

            Union(p, q);

            if(ans>edges[i].w)ans=edges[i].w;
        }

        if(parent[from]==parent[to])break;
    }

    return ans;
}

int main(void)
{
    int a , b , c , counter = 0;

    string ar , br , from , to;

    Edge temp;

    while(cin >> a >> b){

        if(!a&&!b)break;

        edges.clear();
        parent.clear();

        while(b--){

            cin >> ar >> br >> c;

            parent[ar]=ar;
            parent[br]=br;

            temp = {ar,br,c};

            edges.push_back(temp);
        }

        int value;

        cin >> from >> to >> value;

        //value++;

        printf("Scenario #%d\n",++counter);

        int ans= Kruskal(from , to);

        cout <<  "Minimum Number of Trips = ";

        ans--;

        if(value%ans==0)cout << value/ans << endl;
        else cout << value/ans +1 << endl;



        cout << endl;

    }

    return 0;
}
