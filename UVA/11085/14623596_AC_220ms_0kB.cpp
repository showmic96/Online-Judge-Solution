#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int ar[8];
bool taken[8][8];

bool possible(int i , int j)
{
    for(int i1=0;;i1++){

        if(i-i1<0)break;
        if(taken[i-i1][j]==true)return false;
    }

    for(int i1=0;;i1++){

        if(i-i1<0||j-i1<0)break;

        if(taken[i-i1][j-i1]==true)return false;
    }

    for(int i1=0;;i1++){

        if(i-i1<0)break;
        if(j+i1>7)break;

        if(taken[i-i1][j+i1]==true)return false;
    }
    return true;
}

int f(int i)
{
    if(i==8)return 0;
    int value = 1e9;

    for(int j=0;j<8;j++){

        if(possible(i , j)==true){

            taken[i][j] = true;

            if(ar[i]==j)value = min(value , f(i+1));
            else value = min(value , f(i+1)+1);

            taken[i][j] = false;
        }
    }

    return value;
}

int main(void)
{
    int c = 0;
    while(scanf("%d %d %d %d %d %d %d %d",&ar[0] , &ar[1] , &ar[2] , &ar[3] , &ar[4] , &ar[5] , &ar[6] , &ar[7])==8){

        ar[0]--;ar[1]--;ar[2]--;ar[3]--;ar[4]--;ar[5]--;ar[6]--;ar[7]--;
        memset(taken , false , sizeof(taken));
        printf("Case %d: %d\n",++c , f(0));
    }
    return 0;
}

