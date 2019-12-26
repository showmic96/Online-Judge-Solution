// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m , lastx , lasty , si , direction;
string ar;
bool visited[55][55] , check;

void dfs(int i , int j , int k , int d)
{
    lastx = i;
    lasty = j;
    direction = d;

    if(k==si)return ;

    if(ar[k]=='L'){

        dfs(i , j , k+1 ,(d-1+4)%4);
    }

    else if(ar[k]=='R'){

        dfs(i , j , k+1 , (d+1)%4);
    }

    else{

        if(d==0){

            if(j+1>m){

                if(visited[i][j]==true)dfs(i , j , k+1 , d);
                else{

                    lastx = i;
                    lasty = j;
                    check = true;
                    visited[i][j] = true;
                    return ;
                }
            }

            else {

                dfs(i , j+1 , k+1 , d);
            }
        }

        if(d==1){

            if(i+1>n){

                if(visited[i][j]==true)dfs(i , j , k+1 , d);
                else{

                    lastx = i;
                    lasty = j;
                    check = true;
                    visited[i][j] = true;
                    return ;
                }
            }

            else {

                dfs(i+1 , j , k+1 , d);
            }
        }

        if(d==2){

            if(j-1<0){

                if(visited[i][j]==true)dfs(i , j , k+1 , d);
                else{

                    lastx = i;
                    lasty = j;
                    check = true;
                    visited[i][j] = true;
                    return ;
                }
            }

            else {

                dfs(i , j-1 , k+1 , d);
            }
        }

        if(d==3){

            if(i-1<0){

                if(visited[i][j]==true)dfs(i , j , k+1 , d);
                else{

                    lastx = i;
                    lasty = j;
                    check = true;
                    visited[i][j] = true;
                    return ;
                }
            }

            else {

                dfs(i-1 , j , k+1 , d);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int st1 , st2;
    char x;

    memset(visited , false , sizeof(visited));

    while(cin >> st1 >> st2 >> x){

        cin >> ar;

        si = ar.size();
        check = false;
        lastx = -1 , lasty = -1;

        if(x=='N')dfs(st1 , st2 , 0 , 0);
        if(x=='E')dfs(st1 , st2 , 0 , 1);
        if(x=='S')dfs(st1 , st2 , 0 , 2);
        if(x=='W')dfs(st1 , st2 , 0 , 3);

        if(direction==0)x = 'N';
        if(direction==1)x = 'E';
        if(direction==2)x = 'S';
        if(direction==3)x = 'W';

        printf("%d %d %c",lastx , lasty , x);
        if(check)printf(" LOST\n");
        else printf("\n");
    }

    return 0;
}
