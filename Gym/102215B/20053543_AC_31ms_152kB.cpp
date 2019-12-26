// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar[2];
    cin >> ar[0] >> ar[1];
    vector <int> upor , nich , majh , rem;
    for(int i=0;i<ar[0].size();i++){
        if(ar[0][i]=='#'&&ar[1][i]=='#')majh.push_back(i);
        else if(ar[0][i]=='#')upor.push_back(i);
        else if(ar[1][i]=='#')nich.push_back(i);
        else rem.push_back(i);
    }
    if(upor.size()>0&&nich.size()>0&&majh.size()==0)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        string ans[2];
        ans[0] = "" , ans[1] = "";
        for(int i=0;i<upor.size();i++){
            ans[0]+=ar[0][upor[i]];
            ans[1]+=ar[1][upor[i]];
        }
        for(int i=0;i<majh.size();i++){
            ans[0]+=ar[0][majh[i]];
            ans[1]+=ar[1][majh[i]];
        }
        for(int i=0;i<nich.size();i++){
            ans[0]+=ar[0][nich[i]];
            ans[1]+=ar[1][nich[i]];
        }
        for(int i=0;i<rem.size();i++){
            ans[0]+=ar[0][rem[i]];
            ans[1]+=ar[1][rem[i]];
        }
        cout << ans[0] << endl << ans[1] << endl;
    }

    return 0;
}
