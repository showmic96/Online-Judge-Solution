// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string ar[1005];
int n , m;
int level[1005][1005];

bool valid(int i , int j)
{
    if(i<0||j<0)return false;
    if(i>=n||j>=m)return false;
    if(level[i][j]!=0)return false;
    if(ar[i][j]=='T')return false;

    return true;
}

void bfs(int i, int j)
{
    queue<int>current;

    current.push(i);
    current.push(j);

    while(!current.empty()){

        i = current.front();current.pop();
        j = current.front();current.pop();

        if(valid(i+1 , j)==true){

            level[i+1][j] = level[i][j]+1;
            current.push(i+1);
            current.push(j);
        }

        if(valid(i-1 , j)==true){

            level[i-1][j] = level[i][j]+1;
            current.push(i-1);
            current.push(j);
        }

        if(valid(i , j+1)==true){

            level[i][j+1] = level[i][j]+1;
            current.push(i);
            current.push(j+1);
        }

        if(valid(i , j-1)==true){

            level[i][j-1] = level[i][j]+1;
            current.push(i);
            current.push(j-1);
        }
    }
}

int main(void)
{
    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            level[i][j] = 0;
        }
    }

    int i1 , j1;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='E'){

                bfs(i , j);
            }

            if(ar[i][j]=='S'){

                i1 = i;
                j1 = j;
            }
        }
    }

    int lim = level[i1][j1];
    int ans = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]>='1'&&ar[i][j]<='9'){

                if(level[i][j]<=lim){

                    if(level[i][j]!=0)ans+=ar[i][j] - '0';
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
