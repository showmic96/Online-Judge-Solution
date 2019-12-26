// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , m;
    int mp[21];

    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;

        memset(mp , 0 , sizeof(mp));

        while(m--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            if(in2<0){

                mp[-in2]=1;
            }
        }

        int counter = 0;

        for(int i=1;i<=n;i++){

            if(mp[i]==0)counter++;
        }

        printf("%d\n",counter);
    }

    return 0;
}
