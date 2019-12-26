// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[5005];
int br[5005];

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ar[in] = i;
        }

        int counter = 0;

        for(int i=0;i<n;i++){

            scanf("%d",&br[i]);

            for(int j=0;j<i;j++){

                if(ar[br[j]]>ar[br[i]])counter++;
            }
        }

        printf("%d\n",counter);
    }
    return 0;
}
