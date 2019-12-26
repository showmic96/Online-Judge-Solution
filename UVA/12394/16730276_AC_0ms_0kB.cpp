// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v[10005];
string ar[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int k , n;
    while(cin >> k >> n){

        if(n==0&&k==0)break;

        for(int i=0;i<=n;i++)v[i].clear();

        for(int i=0;i<n;i++){

            cin >> ar[i+1];

            for(int j=0;j<k;j++){

                int in;
                cin >> in;
                v[in].push_back(i+1);
            }
        }

        int ans = 0;

        for(int i=1;i<=n;i++){

            if(v[i].size()!=k){

                ans++;
                continue;
            }

            sort(v[i].begin() , v[i].end());

            for(int j=0;j<v[i].size();j++){

                if(j+1<v[i].size())if(v[i][j]==v[i][j+1]){

                    ans++;
                    break;
                }

                if(ar[i]==ar[v[i][j]]){

                    ans++;
                    break;
                }
            }
        }

        if(ans==0)cout << "NO PROBLEMS FOUND" << endl;
        else if(ans==1)cout << "1 PROBLEM FOUND" << endl;
        else cout << ans << " PROBLEMS FOUND" << endl;
    }

    return 0;
}
