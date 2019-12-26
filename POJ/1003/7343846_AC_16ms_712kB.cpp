#include<iostream>
using namespace std;

int main(void)
{
    double a , b , c;

    while(cin >> a){

        if(!a)break;

        b = 0;
        int counter = 0;
        for(int i=2;;i++){
            counter++;
            b+=(double)(1.00/i);
            if(b>=a)break;
        }

        cout <<counter << " card(s)" << endl;
    }

    return 0;
}
