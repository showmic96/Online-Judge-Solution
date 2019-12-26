#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , s;
    scanf("%d %d",&n , &s);
    int mx = 0;
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        mx = max(mx , in);
    }
    printf("%d\n",(mx*s+999)/1000);
    return 0;
}
