// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char ar[32][32][32];
int level[32][32][32];
int n , m , o;

bool valid(int i , int j , int k)
{
    if(i<0||j<0||k<0)return false;
    if(i>=n||j>=m||k>=o)return false;
    if(ar[i][j][k]=='#')return false;
    if(level[i][j][k]!=0)return false;

    return true;
}

void bfs(int i , int j , int k)
{

    queue<int>current;
    current.push(i);
    current.push(j);
    current.push(k);

    while(!current.empty()){

        i = current.front();current.pop();
        j = current.front();current.pop();
        k = current.front();current.pop();

        if(valid(i+1 , j , k)==true){

            level[i+1][j][k] = level[i][j][k]+1;
            current.push(i+1);
            current.push(j);
            current.push(k);
        }

        if(valid(i-1 , j , k)==true){

            level[i-1][j][k] = level[i][j][k]+1;
            current.push(i-1);
            current.push(j);
            current.push(k);
        }

        if(valid(i , j+1 , k)==true){

            level[i][j+1][k] = level[i][j][k]+1;
            current.push(i);
            current.push(j+1);
            current.push(k);
        }

        if(valid(i , j-1 , k)==true){

            level[i][j-1][k] = level[i][j][k]+1;
            current.push(i);
            current.push(j-1);
            current.push(k);
        }

        if(valid(i , j , k+1)==true){

            level[i][j][k+1] = level[i][j][k]+1;
            current.push(i);
            current.push(j);
            current.push(k+1);
        }

        if(valid(i , j , k-1)==true){

            level[i][j][k-1] = level[i][j][k]+1;
            current.push(i);
            current.push(j);
            current.push(k-1);
        }

    }
}

int main(void)
{

    while(cin >> n >> m >> o){

        if(!n&&!m&&!o)break;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                cin >> ar[i][j];
            }
        }

        memset(level , 0 , sizeof(level));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                for(int k=0;k<o;k++){

                    if(ar[i][j][k]=='S')bfs(i , j , k);
                }
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                for(int k=0;k<o;k++){

                    if(ar[i][j][k]=='E'){

                        if(level[i][j][k]==0)printf("Trapped!\n");
                        else printf("Escaped in %d minute(s).\n",level[i][j][k]);
                    }
                }
            }
        }
    }

    return 0;
}
