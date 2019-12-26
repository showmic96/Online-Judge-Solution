// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

int n , m , a[100];

void f(int idx , int one)
{
    if(one==m){

        cout << a[0];

        for(int i=1;i<n;i++){
            cout << a[i];
        }

        cout << endl;

        return ;
    }

    if(idx>=n)return ;

    f(idx+1 , one);

    a[idx] = 1;

    f(idx+1 , one+1);

    a[idx] = 0;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){

        if(space)cout << endl;
        space = true;
        cin >> n >> m;

        memset(a , 0 , sizeof(a));

        f(0 , 0);
    }
    return 0;
}
