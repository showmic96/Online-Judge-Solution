// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 81;
string ar[MAX+9];
int n;
char in[MAX+9];
bool vis[MAX+9][MAX+9][2] , check;

void dfs(int i , int j , int l , int bw)
{
    if(i>=n||j>=n)return ;
    if(i<0||j<0)return ;

    if(bw==0){

        if(j==n-1&&ar[i][j]=='W'){
            check = true;
            return ;
        }

        else if(j==n-1&&ar[i][j]=='U'&&l>0){
            check = true;
            return ;
        }
    }

    else {

        if(i==n-1&&ar[i][j]=='B'){
            check = true;
            return ;
        }

        else if(i==n-1&&ar[i][j]=='U'&&l>0){
            check = true;
            return ;
        }
    }

    if(ar[i][j]=='U')l--;
    if(l<0)return;

    if(vis[i][j][l])return;
    vis[i][j][l] = true;

    if(bw==0){

        if(ar[i][j]=='B')return ;
    }

    if(bw==1){

        if(ar[i][j]=='W')return ;
    }

    dfs(i+1 , j , l , bw);
    dfs(i , j+1 , l , bw);
    dfs(i-1 , j , l , bw);
    dfs(i , j-1 , l , bw);
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(n==0)break;

        for(int i=0;i<n;i++){

            scanf("%s",&in);
            string temp(in);

            ar[i] = temp;
        }

        int w = 0 , b = 0;

        check = false;

        for(int i=0;i<n;i++){

            if(ar[i][0]=='W'){

                memset(vis , false , sizeof(vis));

                dfs(i , 0 , 0 , 0);

                if(check==true){

                    printf("White has a winning path.\n");
                    break;
                }
            }
        }

        if(check==false)for(int i=0;i<n;i++){

            if(ar[0][i]=='B'){

                memset(vis , false , sizeof(vis));

                dfs(0 , i , 0 , 1);

                if(check==true){

                    printf("Black has a winning path.\n");
                    break;
                }
            }
        }

        if(check==false)for(int i=0;i<n;i++){

            if(ar[i][0]=='W'){

                memset(vis , false , sizeof(vis));

                dfs(i , 0 , 1 , 0);

                if(check==true){

                    printf("White can win in one move.\n");
                    break;
                }
            }

            if(ar[i][0]=='U'){

                memset(vis , false , sizeof(vis));

                dfs(i , 0 , 0 , 0);

                if(check==true){

                    printf("White can win in one move.\n");
                    break;
                }
            }
        }

        if(check==false)for(int i=0;i<n;i++){

            if(ar[0][i]=='B'){

                memset(vis , false , sizeof(vis));

                dfs(0 , i , 1 , 1);

                if(check==true){

                    printf("Black can win in one move.\n");
                    break;
                }
            }

            if(ar[0][i]=='U'){

                memset(vis , false , sizeof(vis));

                dfs(0 , i , 0 , 1);

                if(check==true){

                    printf("Black can win in one move.\n");
                    break;
                }
            }
        }

        if(check==false)printf("There is no winning path.\n");
    }
    return 0;
}
