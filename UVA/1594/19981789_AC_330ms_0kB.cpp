// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int ar[20] , br[20];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&ar[i]);
        int counter = 0;
        while(counter<1005){
            counter++;
            bool check = true;
            for(int i=0;i<n;i++){
                if(ar[i]!=0)check = false;
            }
            if(check)break;
            for(int i=0;i<n;i++)br[i] = abs(br[i]-ar[(i+1)%n]);
            for(int i=0;i<n;i++)ar[i] = br[i];
        }
        if(counter==1005)printf("LOOP\n");
        else printf("ZERO\n");
    }
    return 0;
}
