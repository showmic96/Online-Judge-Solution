// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[12345];

int main(void)
{
    int n , k , in;
    cin >> n >> k;

    map<int, int>one;
    map<int, int>two;

    for(int i=0;i<n;i++){

        cin >> ar[i];
        
        if(ar[i]==1){

            one[i%k]++;
        }
        else{

            two[i%k]++;
        }
    }


    int br[k];

    for(int i=0;i<k;i++){

        if(one[i]>two[i])br[i] = 1;
        else br[i] = 2;
    }

    int d = 0 , counter = 0;

    for(int i=0;i<n;i++){

        if(d==k)d=0;
        if(ar[i]!=br[d])counter++;
        d++;
    }

    cout << counter << endl;

    return 0;
}
