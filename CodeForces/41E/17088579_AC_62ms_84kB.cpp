// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int , int> > ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i+=2){

        for(int j=2;j<=n;j+=2){

            ans.emplace_back(i , j);
        }
    }

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)cout << ans[i].first << ' ' << ans[i].second << '\n';

    return 0;
}
