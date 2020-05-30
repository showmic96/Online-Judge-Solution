// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v[25] , pos[27];
bool dp[(1<<22)+10][26][2];
bool vis[(1<<22)+10][26][2];
int n;
string ar;

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int Set(int n , int pos)
{
    return n|(1<<pos);
}

int f(int mask , int last , int player)
{
    if(vis[mask][last][player]==true)return dp[mask][last][player];
    vis[mask][last][player]=true;
    int value = player^1;
    if(mask==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                value = max(value , f(Set(mask , i) , v[i][j] , player^1));
                if(value==1)return dp[mask][last][player] = value;
            }
        }
    }
    else{
        for(int i=0;i<pos[last].size();i++){
            if(Check(mask , pos[last][i])==false){
                int t = pos[last][i];
                for(int j=0;j<v[t].size();j++){
                    if(player==0){
                        value = min(value , f(Set(mask , t) , v[t][j] , player^1));
                        if(value==0)return dp[mask][last][player] = value;
                    }
                    else{
                        value = max(value , f(Set(mask , t) , v[t][j] , player^1));
                        if(value==1)return dp[mask][last][player] = value;
                    }
                }
            }
        }
    }
    return dp[mask][last][player] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++)v[i].clear();
        for(int i=0;i<26;i++)pos[i].clear();
        for(int i=0;i<n;i++){
            cin >> ar;
            pos[ar[0]-'a'].push_back(i);
            int fr[26];
            memset(fr , 0 , sizeof(fr));
            for(int j=0;j<ar.size();j++){
                fr[ar[j]-'a'] = 1;
            }
            for(int j=0;j<26;j++)if(fr[j]==1)v[i].push_back(j);
        }
        memset(vis , false ,sizeof(vis));
        int ans = f(0 , 0 , 1);
        cout << "Case " << ++c << ": ";
        if(ans==1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}