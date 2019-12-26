// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a , b, n;
    cin >> a >> b >> n;

    for(int i=0;i<=9;i++){

        if(((a*10)+i)%b==0){

            cout << a*10 + i ;

            for(int j=0;j<n-1;j++)cout << 0;

            cout << endl;
            break;
        }

        if(i==9){
            cout << -1 << endl;
        }
    }

    return 0;
}


