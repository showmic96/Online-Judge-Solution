// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        char ar[3];
        cin >> ar;

        int x1 = ar[0] - 'a' + 1;
        int x2 = ar[1] - '0';

        int counter = 0;

        if(x1+2<=8&&x2+1<=8)counter++;
        if(x1+1<=8&&x2+2<=8)counter++;
        if(x1+2<=8&&x2-1>=1)counter++;
        if(x1+1<=8&&x2-2>=1)counter++;

        if(x1-2>=1&&x2+1<=8)counter++;
        if(x1-2>=1&&x2-1>=1)counter++;
        if(x1-1>=1&&x2+2<=8)counter++;
        if(x1-1>=1&&x2-2>=1)counter++;

        cout << counter << endl;
    }
    return 0;
}
