#include<iostream>

using namespace std;
int main(void)
{
    int a , b, c , d , e , f , g , h , i , j , k , l;
    cin >> a;
    for(b=0;b<a;b++){
        c=4,f=4;
        cin >> e;
        if(e==1) cout << 1 << endl;
        if(e!=1){
        for(d=1;d<e-1;d++)
        {
            c*=2;
            f+=c;
        }
        cout << f << endl;
        }
    }
    return 0;
}