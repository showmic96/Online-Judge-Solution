// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[1025] , br[1025];

int main(void)
{
    memset(ar , 0 , sizeof(ar));
    memset(br , 0 , sizeof(br));

    int n , k , x;
    scanf("%d %d %d",&n , &k , &x);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        ar[in]++;
    }

    for(int i=0;i<k;i++){

        for(int j=0;j<1025;j++)br[j] = ar[j];

        bool check = false;

        for(int j=0;j<1025;j++){

            int temp = ar[j]/2;
            int now = j^x;

            if(check==false){

                if(ar[j]%2){

                    br[j] = br[j] - temp - 1;
                    br[now] = br[now] + temp + 1;

                    check = true;
                }

                else{

                    br[j]-=temp;
                    br[now]+=temp;
                }
            }

            else{

                if(ar[j]%2){

                    check = false;
                }

                br[j]-=temp;
                br[now]+=temp;
            }
        }

        for(int j=0;j<1025;j++)ar[j] = br[j];
    }

    int mi = 1e9 , mx = 0;

    for(int i=0;i<1025;i++){

        if(ar[i])mi = min(mi , i);
        if(ar[i])mx = max(mx , i);
    }

    printf("%d %d\n",mx , mi);

    return 0;
}
