// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int fr[10];

void f(int x)
{
    int ar[10];
    memset(ar , 0 , sizeof(ar));
    while(x){

        ar[x%10]++;
        x/=10;
    }

    int mx = 0;

    for(int i=0;i<10;i++)mx = max(mx , ar[i]);
    for(int i=0;i<10;i++)if(ar[i]==mx)fr[i]++;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(fr , 0 , sizeof(fr));
        int a , b, n;
        scanf("%d %d %d",&a , &b , &n);

        for(int i=1;;i++){

            int temp = a*i*i+b*i;
            if(temp>n)break;
            f(temp);
        }

        int mx = 0 , ans = -1;

        for(int i=0;i<=9;i++){

            if(fr[i]>mx){

                mx = fr[i];
                ans = i;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
