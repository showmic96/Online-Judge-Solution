// In the name of Allah the Lord of the Worlds.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int>v;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        v.clear();

        if(n&1)v.push_back(0);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        sort(v.begin() , v.end());

        int ans = 0;

        for(int i=0;i<n;i+=2){

            ans^=(v[i+1]-v[i]-1);
        }

        if(!ans)printf("Bob will win\n");
        else printf("Georgia will win\n");
    }
    return 0;
}
