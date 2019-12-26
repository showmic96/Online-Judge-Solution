// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
ll p = 31;

map<string , int>mp;

ll get_hash(string ar)
{
    ll now = 1 , hsh = 0;

    for(int i=0;i<ar.size();i++){

        hsh = hsh + now*(ar[i] - 'a');
        now*=p;
    }

    return hsh;
}

vector<string>v;
ll pw[100005];
int par[100005];

int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}

void Union(int x ,int y)
{
    int px = Find(x);
    int py = Find(y);

    par[py] = px;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c = 1;
    pw[0] = 1;
    for(int i=0;i<=100000;i++)par[i] = i;
    for(int i=1;i<=100000;i++)pw[i] = pw[i-1]*p;
    string ar;
    while(cin >> ar){

        if(ar=="--")break;
        mp[ar] = c++;
        v.emplace_back(ar);
    }

    for(int i=0;i<v.size();i++){

        ar = v[i];

        for(int j=0;j<v[i].size();j++){

            for(int k=0;k<26;k++){

                if(ar[j]-'a'==k)continue;

                string temp = ar;
                temp[j] = 'a'+k;

                if(mp.find(temp)==mp.end())continue;

                Union(mp[temp] , mp[ar]);
            }
        }
    }
    string br;
    while(cin >> ar >> br){

        if(Find(mp[ar])==Find(mp[br]))cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
