#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    long long a , b , c=0 , d , e , f,a1=1,a2=1,a3=1,b1=0,b2=0,b3=0;
    cin >> a;
    long long as[a],as1[a],as2[a],as3[a];
    for(b=0;b<a;b++){ cin >> as[b];if(as[b]<0)c++;}
    sort(as,as+a);
    if(c%2!=0&&c>2){
        cout << 1 << " " <<as[0] <<endl;
        cout << c-1 ;
        for(b=1;b<c;b++) cout <<" " << as[b];
        cout << endl << a-c;
        for(;b<a;b++) cout << " " << as[b];
        cout << endl;
    }
    else if(c==1){
        cout << 1 << " " <<as[0] <<endl;
        cout << a-2 ;
        for(b=2;b<a;b++) cout <<" " << as[b];
        cout << endl << 1;
        cout << " " << as[1];
        cout << endl;
    }
    else {
        cout << 1 << " " <<as[0] <<endl;
        cout << a-3 ;
        for(b=2;b<a;b++)if(as[b]!=0) cout <<" " << as[b];
        cout << endl << 2 << " " << as[1];
        cout << " " << as[c];
        cout << endl;
    }
    return 0;
}
