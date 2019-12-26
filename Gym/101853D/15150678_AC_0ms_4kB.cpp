// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n , zero = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            
            int in;
            scanf("%d",&in);
            if(in==0)zero++;
        }
        printf("%d\n",n-zero);
    }
    return 0;
}