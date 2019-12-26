// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d", &n , &m);
        int ans = 0;

        for(int i=0;i<n;i++){

            int counter = 0;

            for(int j=0;j<m;j++){

                int in;
                scanf("%d",&in);
                counter+=in;
            }

            ans^=counter;
        }

        if(ans)printf("Case %d: Alice\n", ++c);
        else printf("Case %d: Bob\n", ++c);
    }
    return 0;
}
