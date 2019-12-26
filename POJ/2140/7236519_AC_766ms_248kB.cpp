#include<iostream>
using namespace std;
typedef long long ll;

int main(void)
{
    long long a;
    cin >> a;

    int counter = 1;

    if(a==1||a==2){cout << 1 << endl;return 0;}

    /*int counter = 1;

    if(a%5==0&&a-15>=0)counter++;
    if((a-10)%4==0&&(a-10)>0)counter++;
    if(a%3==0&&a!=3)counter++;
    if(a%2==1&&a!=1)counter++;
    */

    long long sum;

    for(ll i = a/2+1;i>=1;i--){
        sum = 0;
        for(ll j = i;j>=1;j--){

            sum+=j;
            if(sum==a)counter++;

            if(sum>a)break;

        }
    }


    cout << counter << endl;

    return 0;
}
