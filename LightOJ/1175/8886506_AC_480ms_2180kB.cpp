// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 234;
char ar[MAX][MAX];
int level_fire[MAX][MAX];
int level[MAX][MAX];
int n , m , ans;

void setUp()
{
    for(int i=0;i<MAX;i++){

        for(int j=0;j<MAX;j++){

            level[i][j] = 0;
            level_fire[i][j] = 777777;
        }
    }
}

void bfs1(int i , int j)
{
    queue<int>current;
    current.push(i);
    current.push(j);
    level_fire[i][j] = 0;

    while(!current.empty()){

        i = current.front();
        current.pop();
        j = current.front();
        current.pop();

        if(i+1<n){

            if(level_fire[i+1][j]>level_fire[i][j]+1&&ar[i+1][j]!='#'){
                level_fire[i+1][j] = level_fire[i][j]+1;
                current.push(i+1);
                current.push(j);

            }
        }

        if(j+1<m){

            if(level_fire[i][j+1]>level_fire[i][j]+1&&ar[i][j+1]!='#'){
                level_fire[i][j+1] = level_fire[i][j]+1;
                current.push(i);
                current.push(j+1);

            }
        }


        if(i-1>=0){

            if(level_fire[i-1][j]>level_fire[i][j]+1&&ar[i-1][j]!='#'){
                level_fire[i-1][j] = level_fire[i][j]+1;
                current.push(i-1);
                current.push(j);

            }
        }


        if(j-1>=0){

            if(level_fire[i][j-1]>level_fire[i][j]+1&&ar[i][j-1]!='#'){
                level_fire[i][j-1] = level_fire[i][j]+1;
                current.push(i);
                current.push(j-1);

            }
        }
    }
}

void bfs2(int i , int j)
{
    queue<int>current;
    current.push(i);
    current.push(j);

    while(!current.empty()){

        i = current.front();
        current.pop();
        j = current.front();
        current.pop();

        if(i+1<n){

            if(level[i+1][j]==0&&ar[i+1][j]!='#'){

                level[i+1][j] = level[i][j]+1;
                if(level_fire[i+1][j]>level[i+1][j]){
                    current.push(i+1);
                    current.push(j);
                }

            }
        }
        else ans = min(ans , level[i][j]);

        if(j+1<m){

            if(level[i][j+1]==0&&ar[i][j+1]!='#'){
                level[i][j+1] = level[i][j]+1;
                if(level_fire[i][j+1]>level[i][j+1]){
                    current.push(i);
                    current.push(j+1);
                }

            }
        }
        else ans = min(ans , level[i][j]);


        if(i-1>=0){

            if(level[i-1][j]==0&&ar[i-1][j]!='#'){
                level[i-1][j] = level[i][j]+1;
                if(level_fire[i-1][j]>level[i-1][j]){
                    current.push(i-1);
                    current.push(j);
                }

            }
        }
        else ans = min(ans , level[i][j]);


        if(j-1>=0){

            if(level[i][j-1]==0&&ar[i][j-1]!='#'){
                level[i][j-1] = level[i][j]+1;
                if(level_fire[i][j-1]>level[i][j-1]){
                    current.push(i);
                    current.push(j-1);
                }

            }
        }

        else ans = min(ans , level[i][j]);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        setUp();
        ans = 123456;

        scanf("%d %d",&n , &m);

        for(int j=0;j<n;j++)cin >> ar[j];

        for(int j=0;j<n;j++){

            for(int k=0;k<m;k++){

                if(ar[j][k]=='F')bfs1(j , k );
            }
        }

        for(int j=0;j<n;j++){

            for(int k=0;k<m;k++){

                if(ar[j][k]=='J')bfs2(j , k );
            }
        }

        if(ans==123456)printf("Case %d: IMPOSSIBLE\n",i+1);
        else printf("Case %d: %d\n",i+1 , ans+1);
    }

    return 0;
}
