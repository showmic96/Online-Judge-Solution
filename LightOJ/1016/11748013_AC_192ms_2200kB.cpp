// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , w;
        scanf("%d %d",&n , &w);
        vector<int>v;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            v.push_back(in2);
        }

        sort(v.begin() , v.end());
        int counter = 1 , last = v[0]+w;

        for(int i=0;i<n;i++){

            if(v[i]<=last)continue;

            counter++;
            last = v[i]+w;
        }

        printf("Case %d: %d\n",++c , counter);
    }
    return 0;
}
