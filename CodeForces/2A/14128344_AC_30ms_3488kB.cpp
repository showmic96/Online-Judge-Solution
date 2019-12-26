// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<pair<string , int> > v;
    map<string , int>mp , mp2;

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        string ar;int in;
        cin >> ar >> in;

        v.push_back(make_pair(ar , in));
        mp[ar]+=in;
    }

    int hi = -1e9;

    for(map<string , int>::iterator it = mp.begin();it!=mp.end();it++){

        hi = max(hi , it->second);
    }

    for(int i=0;i<n;i++){

        mp2[v[i].first]+=v[i].second;

        if(mp2[v[i].first]>=hi&&mp[v[i].first]==hi){

            cout << v[i].first << endl;
            break;
        }
    }

    return 0;
}
