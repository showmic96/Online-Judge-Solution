// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string ar[55];
int n , m , counter;
bool visited[55][55] , vis[55][55];
vector<pair<int , int> > store;
void dfs(int i , int j)
{
    if(i<0||j<0)return ;
    if(i>=n||j>=m)return ;
    if(ar[i][j]=='.')return ;
    if(visited[i][j])return ;
    if(ar[i][j]=='X'){

        store.push_back(make_pair(i , j));
    }

    visited[i][j] = true;

    dfs(i+1 , j);
    dfs(i-1 , j);
    dfs(i , j+1);
    dfs(i , j-1);
}

void f(int i , int j)
{
    if(i<0||j<0)return ;
    if(i>=n||j>=m)return ;
    if(ar[i][j]!='X')return ;
    if(vis[i][j])return ;

    vis[i][j] = true;

    f(i+1 , j);
    f(i-1 , j);
    f(i , j+1);
    f(i , j-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t , c = 0;
    while(cin >> m >> n){

        if(!n&&!m)break;
        for(int i=0;i<n;i++)cin >> ar[i];

        memset(visited , false , sizeof(visited));
        memset(vis , false , sizeof(vis));

        vector<int>v;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='*'||ar[i][j]=='X'){

                    if(visited[i][j]==false){

                        counter = 0;
                        store.clear();
                        dfs(i , j);

                        int si = store.size();

                        for(int i1=0;i1<si;i1++){

                            int t1 = store[i1].first;
                            int t2 = store[i1].second;

                            if(vis[t1][t2])continue;
                            counter++;

                            f(t1 , t2);
                        }

                        if(counter>0)v.push_back(counter);
                    }
                }
            }
        }

        sort(v.begin() , v.end());

        cout << "Throw " << ++c << endl;
        int si = v.size();
        for(int i=0;i<si;i++){

            if(i>0)cout << " ";
            cout << v[i];
        }
        cout << endl << endl;
    }

    return 0;
}
