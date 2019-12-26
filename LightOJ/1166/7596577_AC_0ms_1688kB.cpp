#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int t , a;
    int ar[10000] , br[10000];

    scanf("%d",&t);

    for(int i=0;i<t;i++){

        scanf("%d",&a);

        for(int j=0;j<a;j++){

            scanf("%d",&ar[j]);
        }

        int counter = 0;

        for(int j=0;j<a;j++){

            int k = j;

            while(k<a&&ar[k]!=j+1)k++;

            if(k!=j){

                counter++;
                swap(ar[j],ar[k]);
            }
        }

        printf("Case %d: %d\n", i+1 , counter);
    }

    return 0;

}
