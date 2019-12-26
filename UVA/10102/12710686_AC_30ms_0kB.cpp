// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char ar[1007][1007];
int n;

int f(int i , int j)
{
    int ans = INT_MAX;

    for(int i1=0;i1<n;i1++){

        for(int j1=0;j1<n;j1++){

            if(ar[i1][j1]=='3'){

                ans = min(ans , abs(i1-i)+abs(j1-j));
            }
        }
    }

    return ans;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        for(int i=0;i<n;i++)scanf("%s",&ar[i]);
        int ans = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]=='1')ans = max(ans , f(i , j));
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
