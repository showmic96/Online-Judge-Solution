// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[1000005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(ar , 0 , sizeof(ar));

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ar[in]++;
        }

        bool check = true;

        for(int i=0;i<n;i++){

            if(ar[i]>0&&ar[n-i-1]>0){

                int temp = n-i;

                if(ar[temp]>0&&ar[n-temp-1]>0){

                    ar[i]--;
                }

                else{

                    ar[n-i-1]--;
                }
            }

            else if(ar[i]>0){

                ar[i]--;
            }

            else if(ar[n-i-1]>0){

                ar[n-i-1]--;
            }

            else{

                check = false;
                break;
            }
        }

        if(check==true)printf("Case %d: yes\n",++c);
        else printf("Case %d: no\n",++c);

    }
    return 0;
}
