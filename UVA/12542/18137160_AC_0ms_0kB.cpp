// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
bitset<MAX>bs;

void sieve()
{
    bs&=0;
    for(int i=2;i<MAX;i++){

        if(bs[i]==0){

            for(int j=2*i;j<MAX;j+=i)bs[j] = 1;
        }
    }
    bs[0] = 1;
    bs[1] = 1;
}
char ar[1005];

int main(void)
{
    sieve();
    while(scanf("%s",&ar)==1){

        if(ar[0]=='0'&&strlen(ar)==1)break;
        int si = strlen(ar) , ans = 0;

        for(int i=0;i<si;i++){

            int temp = 0;

            for(int j=i;j<si;j++){

                temp*=10;
                temp+=ar[j]-'0';
                if(temp>100000)break;
                if(bs[temp]==0)ans = max(temp , ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
