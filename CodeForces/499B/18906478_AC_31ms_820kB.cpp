// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    map<string,string>mp;
    map<string,string>ump;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        string ar , br;
        cin >> ar >> br;
        mp[ar] = br;
        ump[br] = ar;
    }
    for(int i=0;i<m;i++){
        string ar;
        cin >> ar;
        if(mp.find(ar)!=mp.end()){
            if(mp[ar].size()<ar.size())cout << mp[ar] << " ";
            else cout << ar << " ";
        }
        else{
            if(ump[ar].size()>ar.size())cout << ar << " ";
            else cout << ump[ar] << endl;
        }
    }
    return 0;
}
