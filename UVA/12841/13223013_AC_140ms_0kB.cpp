// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int n , m , s , e;
map<char , int> mp;
map<int , char>rev;

vector<int>edges[20];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}
int Set(int n , int pos)
{
    return n|(1<<pos);
}

int dp[17][(1<<15)+5];
int path[17][(1<<15)+5];

int f(int i , int mask)
{

    if(i==e&&mask==(1<<n)-1){

        return 1;
    }

    if(dp[i][mask]!=-1)return dp[i][mask];

    int value = 0;

    int si = edges[i].size();
    int next = 100000;

    for(int j=0;j<si;j++){

        int v = edges[i][j];

        if(Check(mask , v)==false){

            int temp = f(v , Set(mask , v));

            if(temp){

                value = 1;

                if(next==100000)next = v;
                else if(rev[next+1]>rev[v+1]){

                    next = v;
                }
            }
        }
    }

    path[i][mask] = next;
    return dp[i][mask] = value;
}

void path_print(int i , int mask)
{
    cout << rev[i+1];

    if(i==e){

        cout << endl;
        return ;
    }

    int v = path[i][mask];

    path_print(v , Set(mask , v));
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){

        mp.clear();
        rev.clear();

        memset(dp , -1 , sizeof(dp));

        cin >> n >> m;
        vector<char>input;
        for(int i=0;i<n;i++){

            char x;
            cin >> x;

            input.push_back(x);
        }

        char x1 = input[0];
        char x2 = input[n-1];

        for(int i=0;i<n;i++){

            char x = input[i];

            mp[x] = i;
            rev[i+1] = x;
            edges[i].clear();
        }

        for(int i=0;i<m;i++){

            char u , v;
            cin >> u >> v;

            edges[mp[u]].push_back(mp[v]);
            edges[mp[v]].push_back(mp[u]);
        }

        printf("Case %d: ",++c);

        s = mp[x1];
        e = mp[x2];

        if(f(s , 1)==0)cout << "impossible" << endl;
        else{

            path_print(s , 1);
        }
    }

    return 0;
}
