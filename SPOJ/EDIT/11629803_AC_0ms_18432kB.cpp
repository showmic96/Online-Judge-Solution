// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[2005];
char br[2005];
int lcs[2005][2005];

int main(void)
{

    while(scanf("%s",&ar)==1){

        int si1 = strlen(ar);
        int counter1 = 0 , counter2 = 0;

        for(int i=0;i<si1;i++){

            if(i%2==0){

                if(ar[i]>='a'&&ar[i]<='z')counter1++;
            }
            else {
                if(ar[i] >='A'&&ar[i]<='Z')counter1++;;
            }
        }

        for(int i=0;i<si1;i++){

            if(i%2==1){

                if(ar[i]>='a'&&ar[i]<='z')counter2++;
            }
            else {
                if(ar[i] >='A'&&ar[i]<='Z')counter2++;;
            }
        }

        printf("%d\n",min(counter1 , counter2));
    }
    return 0;
}
