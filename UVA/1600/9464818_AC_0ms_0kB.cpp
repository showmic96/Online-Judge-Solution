// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int INF = 123456;

int n , m , k , ans;
int ar[21][21] , level[21][21][21];

void setUp()
{
    for(int i=0;i<21;i++){

        for(int j=0;j<21;j++){

            for(int k=0;k<21;k++){

                level[i][j][k] = INF;
            }
        }
    }
}

bool valid(int i , int j , int c)
{
    if(i<0||j<0)return false;
    if(i>=n||j>=m||c>k)return false;

    return true;
}

void bfs(int i, int j , int c)
{
    queue<int>current;

    current.push(i);
    current.push(j);
    current.push(c);

    level[i][j][c] = 0;

    while(!current.empty()){

        i = current.front();
        current.pop();
        j = current.front();
        current.pop();
        c = current.front();
        current.pop();

        //if(ar[i][j]==0)c = 0;

        //cout << i << " " << j << " " << c << " " << level[i][j][c] << endl;

        if(i==n-1&&j==m-1){

            ans = min(ans , level[i][j][c]);
        }

        if(valid(i+1 , j , c+ar[i+1][j])==true){

            int temp = c+ar[i+1][j];
            if(ar[i+1][j]==0)temp = 0;

            if(level[i+1][j][temp]>level[i][j][c]+1){

                level[i+1][j][temp]=level[i][j][c] + 1;

                current.push(i+1);
                current.push(j);
                current.push(temp);
            }
        }

        if(valid(i-1 , j , c+ar[i-1][j])==true){

            int temp = c+ar[i-1][j];
            if(ar[i-1][j]==0)temp = 0;

            if(level[i-1][j][temp]>level[i][j][c]+1){

                level[i-1][j][temp]=level[i][j][c] + 1;

                current.push(i-1);
                current.push(j);
                current.push(temp);
            }
        }

        if(valid(i , j+1 , c+ar[i][j+1])==true){

                int temp = c+ar[i][j+1];
                if(ar[i][j+1]==0)temp = 0;

            if(level[i][j+1][temp]>level[i][j][c]+1){

                level[i][j+1][temp]=level[i][j][c] + 1;

                current.push(i);
                current.push(j+1);
                current.push(temp);

            }
        }

        if(valid(i , j-1 , c+ar[i][j-1])==true){

            int temp = c+ar[i][j-1];
            if(ar[i][j-1]==0)temp = 0;

            if(level[i][j-1][temp]>level[i][j][c]+1){

                level[i][j-1][temp]=level[i][j][c] + 1;

                current.push(i);
                current.push(j-1);
                current.push(temp);
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        setUp();

        scanf("%d %d %d",&n , &m , &k);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        ans = INF;

        bfs(0 , 0 , ar[0][0]);

        if(ans==INF)ans=-1;

        printf("%d\n",ans);
    }
    return 0;
}
