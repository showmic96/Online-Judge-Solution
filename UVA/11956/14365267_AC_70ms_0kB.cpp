// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans[105];
char ar[100005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&ar);
        memset(ans , 0 , sizeof(ans));
        int now = 0;

        for(int i=0;i<strlen(ar);i++){

            if(ar[i]=='>'){
                now++;
                if(now==100)now = 0;
            }
            if(ar[i]=='<'){
                now--;
                if(now==-1)now = 99;
            }
            if(ar[i]=='+'){
                ans[now]++;
                if(ans[now]==256)ans[now] = 0;
            }
            if(ar[i]=='-'){
                ans[now]--;
                if(ans[now]==-1)ans[now] = 255;
            }
        }
        printf("Case %d:",++c);
        for(int i=0;i<100;i++)printf(" %02X",ans[i]);
        printf("\n");
    }
    return 0;
}
