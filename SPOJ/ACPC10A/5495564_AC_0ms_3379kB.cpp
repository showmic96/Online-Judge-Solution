#include<iostream>

using namespace std;

int main(void)
{
    double a , b , c ,x=0,y,u=0;double t;
    while(cin >> a >> b >> c){
        if(a==0&&b==0&&c==0) break;
        if(b-a==c-b) cout << "AP " << c+(c-b) << endl;
        else {t=(double)c/b;

        cout << "GP "<<c*t<< endl;
        }


        }

    return 0;
}