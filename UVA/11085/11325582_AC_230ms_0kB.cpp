// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[9];
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

ll f(int i , int j , int n)
{
    if(n==8){

        return 0;
    }
    if(i>=8||j>=8){
        return 1e9;
    }

    ll value = 1e9;

    for(int i1=0;i1<8;i1++){

        if(possible(i , i1)==true){

            taken[i][i1] = true;

            value = min(value , f(i+1 , 0 , n+1) + min(1 , abs(ar[i]-i1-1)));

            taken[i][i1] = false;
        }
    }

    return value;
}

int main(void)
{
    int c = 0;
    while(scanf("%d %d %d %d %d %d %d %d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4],&ar[5],&ar[6],&ar[7])==8){

        memset(taken , false , sizeof(taken));

        printf("Case %d: %lld\n",++c , f(0 , 0 , 0));
    }

    return 0;
}
