// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int n , m;
int ar[15][15] , path[15];

bool taken[15] , check;

void f(int now , int l)
{
    if(l==m){

        check = true;
        printf("(1");
        for(int i=0;i<l;i++){

            printf(",%d",path[i]);
        }

        printf(")\n");
        return;
    }

    for(int i=1;i<=n;i++){

        if(taken[i]==false&&ar[now][i]==1){

            taken[i] = true;
            path[l] = i;
            f(i , l+1);
            taken[i] = false;
        }
    }
}

int main(void)
{
    bool blank = false;
    while(scanf("%d %d",&n , &m)==2){

        if(blank)printf("\n");blank = true;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++)scanf("%d",&ar[i][j]);
        }

        memset(taken , false , sizeof(taken));

        taken[1] = true;check = false;
        f(1 , 0);

        if(check==false)printf("no walk of length %d\n",m);

        scanf("%d",&n);
    }

    return 0;
}
