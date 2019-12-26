#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        double r;

        scanf("%d %lf",&n , &r);

        double counter = 0;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            if(in>=50)counter++;
        }

        counter = 1.00*counter/(double)n;

        if(counter>=r)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
