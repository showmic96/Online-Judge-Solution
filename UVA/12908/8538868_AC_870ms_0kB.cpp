// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int value[101010];

void pre()
{
    value[0] = 0;
    for(int i=1;i<=101000;i++){

        value[i] = value[i-1] + i;
    }
}

int main(void)
{
    int n;

    pre();

    while(cin >> n){

        if(!n)break;
        int c = 1;
        while(value[c]<=n){
            c++;
        }

        cout << value[c] - n << " " << c << endl;
    }

    return 0;

}
