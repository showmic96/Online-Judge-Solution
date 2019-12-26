// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 200+9;
vector<int>edges[MAX+9];
int level[MAX+9] , ans = 0;

string make(string ar)
{
    int si = ar.size();
    for(int i=0;i<si;i++){

        if(ar[i]>='A'&&ar[i]<='Z')ar[i] = ar[i] + 32;
    }

    return ar;
}

void bfs(int i)
{
    queue<int>current;
    current.push(i);
    level[i] = 1;

    while(!current.empty()){

        i = current.front();
        current.pop();

        int si = edges[i].size();

        for(int j=0;j<si;j++){

            if(level[edges[i][j]]==0){

                level[edges[i][j]] = level[i] + 1;

                ans = max(ans , level[i] + 1);

                current.push(edges[i][j]);
            }
        }
    }
}

int main(void)
{
    int n , c = 2;
    map<string , int>mp;
    memset(level , 0 , sizeof(level));
    mp["polycarp"] = 1;

    cin >> n;

    for(int i=0;i<n;i++){

        string ar , br , cr;
        cin >> ar >> cr >> br;

        ar = make(ar);
        br = make(br);

        //cout << ar << " " << br << endl;

        if(mp[ar]==0){

            mp[ar] = c;
            c++;
        }

        if(mp[br]==0){

            mp[br] = c;
            c++;
        }

        //cout << mp[ar] << " " << mp[br] << endl;

        edges[mp[ar]].push_back(mp[br]);
        edges[mp[br]].push_back(mp[ar]);
    }

    bfs(1);
    cout << ans << endl;

    return 0;
}
