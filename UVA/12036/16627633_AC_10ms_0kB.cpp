// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[105];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                int in;
                scanf("%d",&in);
                ar[in]++;
            }
        }

        bool check = true;

        for(int i=0;i<=100;i++)if(ar[i]>n)check = false;
        if(check)printf("Case %d: yes\n",++c);
        else printf("Case %d: no\n",++c);
    }
    return 0;
}
