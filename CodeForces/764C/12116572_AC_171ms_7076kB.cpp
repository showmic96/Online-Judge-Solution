// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+9;

vector<int>edges[MAX+9];
vector<int>v;
bool check;

void dfs(int u , int p , int c)
{
    if(v[u-1]!=c)check = false;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        if(edges[u][i]!=p){

            dfs(edges[u][i] , u , c);
        }
    }
}

void f(int node)
{
    int si = edges[node].size();

    for(int i=0;i<si;i++){

        dfs(edges[node][i] , node , v[edges[node][i]-1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    int first = -1 , second = -1;

    for(int i=1;i<=n;i++){

        int si = edges[i].size();

        for(int j=0;j<si;j++){

            if(v[i-1]!=v[edges[i][j]-1]){

                first = i;
                second = edges[i][j];
            }
        }
    }

    if(first==-1)cout << "YES" << endl << 1 << endl;
    else {

        check = true;

        f(first);

        if(check==true){

            cout << "YES" << endl << first << endl;
            return 0;
        }

        check = true;

        f(second);

        if(check==true)cout << "YES" << endl << second << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
