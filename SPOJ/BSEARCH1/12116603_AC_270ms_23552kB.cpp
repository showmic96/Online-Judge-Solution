// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<int , int > mp;
unordered_map<int , int > mpp;

int main(void)
{
    int n , q;
    scanf("%d %d",&n, &q);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        if(mpp[in]==0)mp[in] = i;
        mpp[in] = 1;
    }

    while(q--){

        int in;
        scanf("%d",&in);
        if(mpp[in]==1){

            printf("%d\n",mp[in]);
        }

        else printf("-1\n");
    }

    return 0;
}
