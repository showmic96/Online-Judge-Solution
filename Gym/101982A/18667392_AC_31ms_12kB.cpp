// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char ar[1005] , br[1005];

int main(void)
{
    int k , tot = 0;
    scanf("%d %s %s",&k , &ar , &br);
    for(int i=0;i<strlen(ar);i++){
        if(ar[i]==br[i])tot++;
    }
    printf("%d\n",min(tot , k)+min(strlen(ar)-tot , strlen(ar)-k));
    return 0;
}
