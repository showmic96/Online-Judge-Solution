#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    long long int a , b , c , counter;

    while(cin >> a >> b >> c){

        counter = 0;

        while(abs(b-c)>=1){

            if(b%2==1)b=b/2+1;
            else b = b/2;

            if(c%2==1)c=c/2+1;
            else c = c/2;

            counter++;
        }

        if(counter>a)counter=a;
        cout << counter << endl;


    }

    return 0;
}
