// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[6][6];
bool taken[6][6];
int n , counter = 0;

bool possible(int i , int j)
{
    if(ar[i][j]=='X')return false;

    for(int i1=i;i1>=0;i1--){

        if(ar[i1][j]=='X')break;
        if(taken[i1][j]==true)return false;
    }

    for(int j1=j;j1>=0;j1--){

        if(ar[i][j1]=='X')break;
        if(taken[i][j1]==true)return false;
    }
    return true;
}

void f(int i , int j , int c)
{
    if(j==n){

        j = 0;
        i++;
    }
    if(i==n){

        counter = max(counter , c);
        return ;
    }

    if(possible(i , j)==true){

        taken[i][j]=true;
        f(i , j+1 , c+1);
        taken[i][j] = false;
    }

    f(i , j+1 , c);
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(n==0)break;

        for(int i=0;i<n;i++)scanf("%s",&ar[i]);
        memset(taken , false , sizeof(taken));
        counter = 0;
        f(0 , 0 , 0);

        printf("%d\n",counter);
    }

    return 0;
}
