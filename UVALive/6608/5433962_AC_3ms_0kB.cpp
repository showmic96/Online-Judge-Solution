#include<iostream>

using namespace std;

int main(void)
{
    float a , b , c1,c2,c3,c4 , d=0 , e , f;
    cin >> a;
    for (b=0;b<a;b++){

        cin >> c1 >> c2 >> c3 >> c4;
        if ((((c1<=56&&c2<=45&&c3<=25)||((c1+c2+c3)<=125)))&&(c4<=7)) {cout << "1" << endl;d+=1;}
        else cout << "0" << endl;
    }
    cout << d << endl;
    return 0;
}
