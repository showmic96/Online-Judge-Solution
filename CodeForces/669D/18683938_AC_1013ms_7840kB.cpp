// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>

typedef long long ll;

int ans[2000005];

int main(void)
{
    int n , q , odd = 0 , even = 0 , cur = 0;
    scanf("%d %d",&n , &q);
    for(int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
        if(t==1){
            int temp;
            scanf("%d",&temp);
            odd+=temp;
            even+=temp;
            if(temp%2)cur^=1;
        }
        else{
            if(cur==0)odd++ , even--;
            else odd-- , even++;
            cur^=1;
        }
        odd = (odd+n)%n;
        even = (even+n)%n;
    }

    for(int i=0;i<n;i++){

        if(i%2==0){
            ans[(i+odd)%n] = i+1;
        }
        else ans[(i+even)%n] = i+1;
    }
    for(int i=0;i<n;i++)printf("%d ",ans[i]);

    return 0;
}
