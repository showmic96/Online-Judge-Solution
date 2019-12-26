#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a , b , c , d=0 , e , f,mx=0 , mn , in;
    cin >>a>>b;
    long long ar[a];
    for(c=0;c<a;c++) cin >> ar[c];
    for(c=0;c<a;c++){
        if(ar[c]%b==0) ar[c]=ar[c]/b;
        else if(ar[c]>b) ar[c]=(ar[c]/b)+1;
        else ar[c]=1;
    }
    for(c=0;c<a;c++){
        if(mx<=ar[c]) {mx=ar[c];in=c;}
    }
    cout << in+1 << endl;



    return 0;
}
