// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

char ar[2005] , br[2005];

int main(void)
{
    scanf("%s %s" , &ar , &br);

    int si1 = strlen(ar);
    int si2 = strlen(br);

    int mx = 0 , counter = 0;

    for(int i=-2000;i<=2000;i++){

        counter = 0;

        for(int j=0;j<si2;j++){

            if(j+i>=0&&j+i<si1)if(br[j]==ar[j+i]){

                counter++;
            }
        }

        mx = max(mx , counter);
    }

    printf("%d\n",si2-mx);


    return 0;
}
