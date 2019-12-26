// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char x[55];
bool taken[55];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(taken , false , sizeof(taken));
        scanf("%s",&x);

        int si = strlen(x);

        for(int i=0;i<si;i++){

            if(x[i]=='D'){

                taken[i] = true;
                //taken[i-1] = true;
            }
            if(x[i]=='B'){

                taken[i] = true;
                if(i-1>=0)taken[i-1] = true;
                if(i-2>=0)taken[i-2] = true;
            }
            if(x[i]=='S'){

                taken[i] = true;
                taken[i+1] = true;
                if(i-1>=0)taken[i-1] = true;
            }
        }

        int counter = 0;
        for(int i=0;i<si;i++)if(taken[i]==false)counter++;
        printf("Case %d: %d\n",++c , counter);
    }

    return 0;
}
