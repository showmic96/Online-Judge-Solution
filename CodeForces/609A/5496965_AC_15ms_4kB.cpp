#include<iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int a , b , c, d ,e ,f,g=0,i,j,k=0;
    cin >> a >> b;
    int z[a];
    for(c=0;c<a;c++){
            cin >> z[c];

    }
    sort(z,z+a);
    k=0;
    for(d=a-1;d>=0;d--){g+=z[d];
    if(g<b) k+=1;
    if(g>=b) break;}
    cout << k+1 << endl;

    return 0;
}