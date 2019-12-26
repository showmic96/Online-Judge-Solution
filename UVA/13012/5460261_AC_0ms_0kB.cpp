#include<iostream>

using namespace std;

int main(void)
{
    int a;
    while(cin >>a){
        int b , c=0 , d , e , f;
        for(b=0;b<5;b++){
            cin >> d;
            if(d==a) c+=1;
        }
        cout << c << endl;
    }
    return 0;
}