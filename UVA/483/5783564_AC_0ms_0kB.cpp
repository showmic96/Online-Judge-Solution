#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000];
    while(gets(a)){
    int b , c , d , e , f;
    f=strlen(a);
    for(b=0;b<f;b++){
            c=b;
            for(;b<f;b++){
                if(a[b]==' '||a[b]=='\0')break;
            }

            for(d=b-1;d>=c;d--) cout << a[d] ;
            if(b<=f-1)cout << " ";

    }
    cout << endl;

    }
    return 0;
}
