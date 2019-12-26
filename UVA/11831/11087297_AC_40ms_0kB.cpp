// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , l;

string ar[110];
string br;
int counter = 0;

bool possible(int i , int j)
{
    if(i<0||j<0)return false;
    if(i>=n||j>=m)return false;
    if(ar[i][j]=='#')return false;
    return true;
}

void dfs(int i , int j , int k , int d)
{

    if(ar[i][j]=='*')counter++ , ar[i][j] = '.';
    if(k==l)return ;


    if(br[k]=='D'){

        dfs(i , j , k+1 , (d+1)%4);
    }

    else if(br[k]=='E'){

        dfs(i , j , k+1 , (d-1+4)%4);
    }
    else{

        if(d==0){

            if(possible(i-1 , j)==true){

                dfs(i-1 , j , k+1 , d);
            }
            else dfs(i , j , k+1 , d);
        }

        else if(d==1){

            if(possible(i , j+1)==true){

                dfs(i , j+1 , k+1 , d);
            }
            else dfs(i , j , k+1 , d);
        }

        else if(d==2){

            if(possible(i+1 , j)==true){

                dfs(i+1 , j , k+1 , d);
            }
            else dfs(i , j , k+1 , d);
        }

        else{

            if(possible(i , j-1)==true){

                dfs(i , j-1 , k+1 , d);
            }
            else dfs(i , j , k+1 , d);
        }
    }
}

int main(void)
{
    while(scanf("%d %d %d",&n, &m , &l)==3){

        if(n==0&&m==0&&l==0)break;
        counter = 0;

        for(int i=0;i<n;i++)cin >> ar[i];

        cin >> br;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='N'){

                    dfs(i , j , 0 , 0);
                }

                if(ar[i][j]=='S'){

                    dfs(i , j , 0 , 2);
                }

                if(ar[i][j]=='L'){

                    dfs(i , j , 0 , 1);
                }

                if(ar[i][j]=='O'){

                    dfs(i , j , 0 , 3);
                }
            }
        }

        printf("%d\n", counter);
    }

    return 0;
}
