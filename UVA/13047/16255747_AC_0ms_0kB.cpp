// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[77];

int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        scanf("%s",&ar);

        int ans = -1 , si = strlen(ar);

        for(int i=0;i<si;i++){

            if(ar[i]=='>'){

                int counter = 1;

                if(i-1>=0){

                    char x = ar[i-1];
                    if(x!='>'&&x!='<'){

                        for(int j=i-1;j>=0;j--){

                            if(ar[j]==x)counter++;
                            else break;
                        }
                    }
                }

                ans = max(ans , counter);
            }
            else if(ar[i]=='<'){

                int counter = 1;

                if(i+1<si){

                    char x = ar[i+1];
                    if(x!='>'&&x!='<'){

                        for(int j=i+1;j<si;j++){

                            if(ar[j]==x)counter++;
                            else break;
                        }
                    }
                }

                ans = max(ans , counter);
            }
        }

        printf("Case %d: %d\n",++c , ans);
    }

    return 0;
}
