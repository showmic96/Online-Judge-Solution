#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(void)
{
    ll l , z , i , m , l_temp , temp;

    int case_ = 0;
    map<ll,int>maping;

    while(cin >> z >> i >> m >> l){

        if(!z&&!i&&!m&&!l)break;

        maping.clear();

        l_temp = l;

        int counter = 1;

        l = (ll)((z*l+i)%m);

        maping[l]=1;

        while(true){

            l = (ll)((z*l+i)%m);
            if(maping[l]==1)break;
            else maping[l]=1;
           // cout << l << endl;
            counter++;
        }
        printf("Case %d: ",++case_);
        cout << counter << endl;
    }

    return 0;
}
