#include<bits/stdc++.h>
using namespace std;

int ara[25];
int taka[5] = {1, 10, 100, 1000, 10000};

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m)==2)
    {
        int sum = 0 , profit = 0 , mx = 0 , ans = 0;

        for(int i=0;i<m;i++){

            sum = 0;
            mx = 0 ;
            profit = 0;
            int bud;
            scanf("%d",&bud);
            int temp = 0;
            for(int i=0;i<n;i++){

                int in;
                scanf("%d",&in);
                sum+=in;

                if(i==0)temp = in;
            }

            if(sum<=bud)profit = temp;
            sum-=temp;
            //cout << sum << endl;
            if(sum+1<=bud)mx = max(mx , 1);
            if(sum+10<=bud)mx = max(mx , 10);
            if(sum+100<=bud)mx = max(mx , 100);
            if(sum+1000<=bud)mx = max(mx , 1000);
            if(sum+10000<=bud)mx = max(mx , 10000);
            ans+=(mx-profit);
            //cout << mx << " " << profit << endl;
        }
        printf("%d\n",ans);
    }

    return 0;
}
