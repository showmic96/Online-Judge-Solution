// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;

int parent[MAX];

int Find(int x)
{
    if(parent[x]==x)return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    parent[Find(y)] = Find(x);
}

int main(void)
{
    int a , b , ans = 0;

    while(cin >> a){
        ans = 0;
        cin >> b;
        for(int i=1;i<=MAX;i++)parent[i] = i;

        if(Find(parent[a])==Find(parent[b]))ans++;
        else Union(a , b);

        while(cin >> a){

            if(a==-1)break;

            cin >> b;

            if(Find(parent[a])==Find(parent[b]))ans++;
            else Union(a , b);
        }


        cout << ans << endl;
    }

    return 0;
}
