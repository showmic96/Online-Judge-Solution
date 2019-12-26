// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        bool odd = false , even = false;

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            if(in&1)odd = true;
            else even = true;
        }

        if(odd&&even)printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
