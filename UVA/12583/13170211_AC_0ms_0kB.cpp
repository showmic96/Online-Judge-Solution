// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

char ar[5005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , k;
        scanf("%d %d %s",&n , &k , &ar);

        int counter = 0;

        for(int i=1;i<n;i++){

            char x = ar[i];

            for(int j=i-1;j>=max(0 , i-k);j--){

                if(ar[j]==x){

                    counter++;
                    break;
                }
            }
        }

        printf("Case %d: %d\n",++c , counter);
    }
    return 0;
}
