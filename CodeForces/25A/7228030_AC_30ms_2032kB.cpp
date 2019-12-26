#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    int a , in;
    cin >> a;
    int ar[a];

    int odd =0 , even = 0;

    for(int i=0;i<a;i++){
        cin >> ar[i];

        if(ar[i]%2==0)even++;
        else odd++;
    }

    if(even==1){

        for(int i=0;i<a;i++){

            if(ar[i]%2==0)cout << i+1 << endl;
        }
    }

    else {

        for(int i=0;i<a;i++){

            if(ar[i]%2==1)cout << i+1 << endl;
        }
    }

    return 0;
}
