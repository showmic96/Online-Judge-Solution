// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l[100005] , r[100005];
int last[26] , st[26];
char ar[100005];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&ar);

        int si = strlen(ar);
        for(int i=0;i<=si;i++){

            l[i] = 0;
            r[i] = 0;
        }

        memset(st , 0 , sizeof(st));
        memset(last , -1 , sizeof(last));

        int counter = 0;

        for(int i=0;i<si;i++){

            if(st[ar[i]-'A']==0)counter++;
            st[ar[i]-'A'] = 1;
            l[i] = counter;
        }

        memset(st , 0 , sizeof(st));
        counter = 0;

        for(int i=si-1;i>=0;i--){

            if(st[ar[i]-'A']==0)counter++;
            st[ar[i]-'A'] = 1;
            r[i] = counter;
        }

        ll ans = 0;

        for(int i=1;i<si-1;i++){

            if(last[ar[i]-'A']!=-1){

                ans+=(l[i-1]-l[last[ar[i]-'A']-1])*r[i+1];
                last[ar[i]-'A'] = i;
            }
            else{

                ans+=l[i-1]*r[i+1];
                last[ar[i]-'A'] = i;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
