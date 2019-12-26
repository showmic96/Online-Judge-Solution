// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a;
    cin >> a;

    if(a%2==1)cout << -1 << endl;
    else {

        for(int i=0;i<a;i+=2){

            cout << i+2 << " " << i+1;
            if(i!=a-1)cout << " ";
        }
        cout << endl;
    }

    return 0;
}
