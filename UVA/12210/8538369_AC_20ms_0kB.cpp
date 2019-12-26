// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , m , c = 0;
    while(cin >> n >> m){

        if(!n&&!m)break;

        int mi = 1e9;

        for(int i =0;i<n;i++){

            int in;
            cin >> in;

            mi = min(in , mi);
        }

        for(int i=0;i<m;i++){

            int in;
            cin >> in;
        }

        printf("Case %d: ",++c);

        if(n>m){

            cout << n-m << " " << mi << endl;
        }

        else cout << 0 << endl;
    }
    return 0;
}
