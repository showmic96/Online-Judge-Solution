#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    while(a--){

        int i , j;
        cin >> i >> j;
        if(max(i,j)%min(i,j)==0)cout << min(i,j) << " " << max(i,j) << endl;
        else cout << -1 << endl;
    }
    return 0;
}
