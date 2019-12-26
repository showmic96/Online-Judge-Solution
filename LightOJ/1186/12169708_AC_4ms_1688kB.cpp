// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        vector<int>v1 , v2;
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);

            v1.push_back(in);
        }

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);

            v2.push_back(in);
        }

        int ans = 0;

        for(int i=0;i<n;i++){

            int temp = (v2[i]-v1[i]-1);
            ans^=temp;
        }

        printf("Case %d: ",++c);

        if(!ans)printf("black wins\n");
        else printf("white wins\n");
    }
    return 0;
}