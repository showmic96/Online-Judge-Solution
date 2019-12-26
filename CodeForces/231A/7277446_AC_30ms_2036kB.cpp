#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;

int main(void)
{
    int a;
    cin >> a;
    int ans = 0, counter , in ;
    while(a--){

        counter = 0;
        for(int i=0;i<3;i++){

            cin >> in;
            if(in==1)counter++;
        }

        if(counter>=2)ans++;
    }

    cout << ans << endl;

    return 0;
}
