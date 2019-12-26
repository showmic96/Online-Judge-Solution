#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
int a , b , c , d ;long long i ;
cin >> a;
for(b=0;b<a;b++){
        i=0;
    cin >> c;
    int e[c],f[c];
    for(d=0;d<c;d++){
        cin >> e[d];
    }
    for(d=0;d<c;d++){
        cin >> f[d];
    }
    sort (e,e+c);
    sort (f,f+c);
    for(d=0;d<c;d++){
        i+=e[d]*f[d];

    }
    cout << i << endl;
}
return 0;

}