// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[505][505];

int main(void)
{
    int w , h , n;
    while(scanf("%d %d %d",&w , &h , &n)==3){

        if(w==0&&h==0&&n==0)break;
        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<n;i++){

            int x1 , x2 , y1 , y2;
            scanf("%d %d %d %d",&x1 , &y1 , &x2 , &y2);

            for(int i1=min(x1 , x2);i1<=max(x1 , x2);i1++){

                for(int j1=min(y1 , y2);j1<=max(y1 , y2);j1++)ar[i1][j1] = 1;
            }
        }

        int counter = 0;

        for(int i=1;i<=w;i++){

            for(int j=1;j<=h;j++)if(ar[i][j]==0)counter++;
        }

        if(counter==0)printf("There is no empty spots.\n");
        else if(counter==1)printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n",counter);
    }
    return 0;
}
