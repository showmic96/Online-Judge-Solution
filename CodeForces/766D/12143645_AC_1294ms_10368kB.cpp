// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5+9;

int parent[MAX+9];

int Find(int x)
{
    if(parent[x]==x)return x;
    return parent[x] = Find(parent[x]);
}

map<string, int>mp;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m , q;
    cin >> n >> m >> q;

    for(int i=0;i<=2*n;i++)parent[i] = i;

    for(int i=0;i<n;i++){

        string ar;
        cin >> ar;

        mp[ar] = i+1;
    }

    for(int i=0;i<m;i++){

        int in1;
        string in2 , in3;

        cin >> in1 >> in2 >> in3;

        if(in1==1){

            int px = Find(mp[in2]);
            int py = Find(mp[in3]+n);

            if(px==py){

                cout << "NO" << endl;
            }

            else{

                cout << "YES" << endl;

                py = Find(mp[in3]);

                parent[py] = px;
                parent[Find(mp[in3]+n)] = Find(mp[in2]+n);
            }
        }

        else{

            int px = Find(mp[in2]);
            int py = Find(mp[in3]);

            if(px==py){

                cout << "NO" << endl;
            }

            else{

                cout << "YES" << endl;

                parent[px] = Find(mp[in3]+n);
                parent[py] = Find(mp[in2]+n);
            }
        }
    }

    while(q--){

        string ar , br;
        cin >> ar >> br;

        int px = Find(mp[ar]);
        int py = Find(mp[br]);

        if(px==py)cout << 1 << endl;
        else if(px==Find(mp[br]+n))cout << 2 << endl;
        else cout << 3 << endl;
    }

    return 0;
}
