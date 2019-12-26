// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , in , mi = 1e9 , temp;
int ar[111];

bool is_okay()
{
    for(int i=0;i<n-1;i++){

        if(ar[i]!=ar[i+1])return false;
    }

    return true;
}

int main(void)
{
    cin >> n;

    for(int i=0;i<n;i++){

        cin >> ar[i];
    }

    while(true){

        sort(ar , ar+n);

        if(is_okay()==true)break;

        for(int i=1;i<n;i++){

            if(ar[i]!=ar[0])ar[i]-=ar[0];
        }

    }
    cout << (long long)(ar[0]*n) << endl;
    return 0;
}
