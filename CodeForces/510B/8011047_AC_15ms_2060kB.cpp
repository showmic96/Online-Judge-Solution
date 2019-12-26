// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 55;
char ar[MAX+10][MAX+10];
bool isVisited[MAX+10][MAX+10] , check;
int n , m;
char X;

void bfs(int i , int j)
{

    queue<int>current;
    current.push(i);
    current.push(j);
    isVisited[i][j] = true;

    int p = 1;

    while(!current.empty()){


        //cout << "YES" << endl;

        int t1 = current.front();
        current.pop();
        int t2 = current.front();
        current.pop();
        //cout << ar[0];
        //cout << t1 << " " << t2 << endl;

        if(!p)if(isVisited[t1][t2]==true){check=true;break;}
        p = 0;

        isVisited[t1][t2]=true;

        if(t2-1>=0){

            if(isVisited[t1][t2-1]==true);

            else if(ar[t1][t2-1]==X){

                    current.push(t1);
                    current.push(t2-1);

            }
        }

        if(t1-1>=0){

            if(isVisited[t1-1][t2]==true);
            else if(ar[t1-1][t2]==X){

                    current.push(t1-1);
                    current.push(t2);
            }
        }


        if(t1+1<n){

            if(isVisited[t1+1][t2]==true);

            else if(ar[t1+1][t2]==X){

                    current.push(t1+1);
                    current.push(t2);
            }
        }


        if(t2+1<m){

            if(isVisited[t1][t2+1]==true);

            else if(ar[t1][t2+1]==X){

                    current.push(t1);
                    current.push(t2+1);
                }
        }
    }
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    memset(isVisited , false , sizeof(isVisited));
    check=false;

    cin >> n >> m;
    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(isVisited[i][j]==false){

                X = ar[i][j];
                bfs(i , j);
            }

            if(check==true)break;
        }

        if(check==true)break;
    }

    if(check==true)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
