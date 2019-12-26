#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int a , b , c, d;
    cin >> a;
    long long ans;

    while(a--){

        cin >> b;

        int ar[b];

        for(int i=0;i<b;i++){

            cin >> ar[i];
        }

        sort(ar , ar+b);

        ans = 0;

        for(int i=b-1,  j=1;i>=0;i--,j++){

            if(j==3){ans+=ar[i];j=0;continue;}


        }

        cout << ans << endl;
    }

    return 0;
}
