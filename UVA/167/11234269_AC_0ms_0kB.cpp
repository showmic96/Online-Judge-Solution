// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[9][9];
int counter;

bool taken[9][9];

bool possible(int i , int j)
{
    for(int i1=i;i1>=0;i1--){

        if(taken[i1][j]==true)return false;
    }

    for(int i1=0;;i1++){

        if(i-i1<0||j-i1<0)break;

        if(taken[i-i1][j-i1]==true)return false;
    }

    for(int i1=0;;i1++){

        if(i-i1<0||j+i1>=8)break;

        if(taken[i-i1][j+i1]==true)return false;
    }
}

void f(int i , int j , int n , int v)
{
    if(n==8){

        counter = max(counter , v);
        return ;
    }
    if(i>=8||j>=8){
        return ;
    }

    for(int i1=0;i1<8;i1++){

        if(possible(i , i1)==true){

            taken[i][i1] = true;

            f(i+1 , 0 , n+1 , v+ar[i][i1]);

            taken[i][i1] = false;
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        memset(taken , false , sizeof(taken));

        for(int i=0;i<8;i++){

            for(int j=0;j<8;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        counter = 0;
        f(0 , 0 , 0 , 0);

        printf("%5d\n",counter);
    }

    return 0;
}
