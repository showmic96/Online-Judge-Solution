#include<iostream>

using namespace std;

int main(void)
{
    int a,b;
    while(cin >>a >>b){
        int  c=0 , d , e , f;
        if(b%a==0&&a!=1)
        cout << b/a << endl;
        else {
                d=b/(b-a);
        cout << d+1 << endl;

        }
    }
    return 0;
}
