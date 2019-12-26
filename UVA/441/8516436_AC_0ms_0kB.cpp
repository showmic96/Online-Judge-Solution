// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int a[100] , n , ans[6];

void f(int idx , int len)
{

    if(len==6){

        cout << ans[0];

        for(int i=1;i<6;i++)cout << " " << ans[i];
        cout << endl;

        return;
    }

    if(idx>=n) return ;

    ans[len] = a[idx];
    f(idx+1 , len+1);
    f(idx+1 , len);

    return ;
}

int main(void)
{
    bool space = false;
    while(cin >> n){

        if(!n)break;

        if(space)cout << endl;
        space = true;

        for(int i=0;i<n;i++)cin >> a[i];

        f(0 , 0);
    }

    return 0;
}
