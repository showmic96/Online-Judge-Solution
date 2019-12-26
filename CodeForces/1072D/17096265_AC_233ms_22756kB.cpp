// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

int dp[2005][2005];
string ar[2005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , k;
    cin >> n >> k;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(i!=0)dp[i][j] = min(dp[i][j] , dp[i-1][j]);
            if(j!=0)dp[i][j] = min(dp[i][j] , dp[i][j-1]);

            if(ar[i][j]!='a')dp[i][j]++;
        }
    }

    int mx = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(dp[i][j]<=k)mx = max(mx , i+j+1);
        }
    }

    vector<pair<int , int> > v;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(dp[i][j]<=k&&i+j+1==mx){

                v.push_back(make_pair(i , j));
            }
        }
    }

    string ans(mx , 'a');
    if(v.size()==0){

        ans+=ar[0][0];
        v.push_back(make_pair(0 , 0));
        mx = 1;
    }

    while(mx!=2*n-1){

        vector<pair<int , int> > temp;
        int mi = 29;

        for(int i=0;i<v.size();i++){

            int nx = v[i].first;
            int ny = v[i].second;

            if(nx+1<n){

                int t = ar[nx+1][ny]-'a';
                if(t<mi){
                    temp.clear();
                    temp.push_back(make_pair(nx+1, ny));
                    mi = t;
                }
                else if(t==mi){

                    temp.push_back(make_pair(nx+1 , ny));
                }
            }

            if(ny+1<n){

                int t = ar[nx][ny+1]-'a';
                if(t<mi){
                    temp.clear();
                    temp.push_back(make_pair(nx, ny+1));
                    mi = t;
                }
                else if(t==mi){

                    temp.push_back(make_pair(nx , ny+1));
                }
            }
        }

        ans+='a'+mi;
        v = temp;
        sort(v.begin() , v.end());
        v.erase(unique(v.begin() , v.end()) , v.end());
        mx++;
    }

    cout << ans << '\n';

    return 0;
}
