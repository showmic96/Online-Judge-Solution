// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5e5+9;
double ar[MAX] , sum[MAX];
int tot = 0;

double f(int lim)
{
    lim--;
    return ar[tot-1] - ((sum[lim]+ar[tot-1])/((double)lim+2.00));
}

int main(void)
{
    int q;
    scanf("%d",&q);
    while(q--){

        int in;
        scanf("%d",&in);
        if(in==1){

            scanf("%d",&in);
            ar[tot] = in;
            if(tot>0)sum[tot] = sum[tot-1]+ar[tot];
            else sum[tot] = ar[tot];
            tot++;
        }
        else{

            double l = 1.00, r = tot;
            for(int i=0; i<150; i++) {
                double l1 = (l*2.00+r)/3.00;
                double l2 = (l+2.00*r)/3.00;
                if(f(l1) > f(l2)) r = l2; else l = l1;
            }
            double ans = 0;
            for(int i=max(0 , (int)l-10);i<min(tot , (int)l+10);i++){
                ans = max(ans , f(i));
            }
            printf("%.14f\n",ans);
        }
    }
    return 0;
}
