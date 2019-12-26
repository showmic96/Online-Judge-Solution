// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+9;

int n , m;
int dp[MAX][MAX];
map<pair<int , int> , int > mp;

int f(int i , int j)
{
    if(i>=n||j>=m)return 0;
    if(i==n-1&&j==m-1)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    if(mp[make_pair(i ,j)]==1)return 0;

    int value = f(i+1 , j);
    value+=f(i ,j+1);

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;

    while(t--){

        if(space)cout << endl;space = true;
        cin >> n >> m;
        mp.clear();

        scanf("\n");

        for(int i=0;i<n;i++){

            string ar;

            getline(cin , ar);

            stringstream ss(ar);

            int t1 , t2;

            ss >> t1;

            while(ss >> t2){

                mp[make_pair(t1-1 , t2-1)] = 1;
            }
        }

        memset(dp , -1 , sizeof(dp));

        cout << f(0 , 0) << endl;
    }

    return 0;
}
