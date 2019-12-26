#include<iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    long long int a;
    while(cin >> a){
        if(a==-1)break;
        long long d=0,e=0,g=0,h;
       long long int b[a],c;
        for(c=0;c<a;c++){
            cin >> b[c];d+=b[c];
        }
        h=d/a;
        float f;
        f=(float)d/a;
        if(f!=h) cout << "-1" << endl;
      //  d=d/a;
        else{
            for(c=0;c<a;c++)
                if(b[c]>h)g+=(b[c]-h);
            cout << g << endl;
        }
    }
    return 0;
}