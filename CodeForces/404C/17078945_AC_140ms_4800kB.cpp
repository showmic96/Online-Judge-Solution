// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool taken[100005];
vector<pair<int , int> > ans;
vector<int>v[100005];
int rem[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , k;
    cin >> n >> k;

    for(int i=0;i<=n;i++)rem[i] = k;

    memset(taken , false ,sizeof(taken));

    for(int i=1;i<=n;i++){

        int in;
        cin >> in;
        v[in].emplace_back(i);
    }

    if(v[0].size()!=1){

        cout << -1 << endl;
        return 0;
    }

    taken[v[0][0]] = true;

    for(int i=0;i<n;i++){

        int i1=0 , j1=0 , counter = 0;

        while(true){

            if(i1==v[i].size())break;
            if(j1==v[i+1].size())break;

            if(rem[v[i][i1]]==0){

                i1++;
                continue;
            }
            if(rem[v[i+1][j1]]==0){

                j1++;
                continue;
            }

            ans.emplace_back(v[i][i1] , v[i+1][j1]);
            taken[v[i+1][j1]] = true;
            rem[v[i][i1]]--;
            rem[v[i+1][j1]]--;
            j1++;
        }

        for(int j=0;j<v[i+1].size();j++)if(taken[v[i+1][j]]==false){

            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)cout << ans[i].first << " " << ans[i].second << '\n';

    return 0;
}
