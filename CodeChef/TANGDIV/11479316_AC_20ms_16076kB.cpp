// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , k , p;
        scanf("%d %d %d",&n , &k, &p);

        map<int, int>mp;

        for(int i=0;i<k;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            mp[in1] = 1;
        }

        bool check = true;

        for(int i=0;i<p;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            if(mp[in1]==0)check = false;
        }

        if(p>k)printf("No\n");
        else if(check==false)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
