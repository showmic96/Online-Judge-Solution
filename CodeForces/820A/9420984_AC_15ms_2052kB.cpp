// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int c , v0 , v1 ,a , l;
    cin >> c >> v0 >> v1 >> a >> l;

    int counter = 0 , current = 0;

    for(int i=1;i<1000000;i++){

        //cout << current << endl;

        if(current>=c)break;
        if(v0>v1)v0 = v1;

        current+=v0;
        if(i!=1)current-=l;

        v0+=a;
        counter++;
    }

    cout << counter << endl;

    return 0;
}

