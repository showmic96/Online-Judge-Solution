// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int ar[5];
    while(scanf("%d %d %d %d %d",&ar[0] , &ar[1] , &ar[2] , &ar[3] , &ar[4])==5){

        bool check = true;

        for(int i=0;i<5;i++){

            int in;
            scanf("%d",&in);
            ar[i]+=in;
            if(ar[i]!=1)check = false;
        }

        if(check)printf("Y\n");
        else printf("N\n");
    }

    return 0;
}
