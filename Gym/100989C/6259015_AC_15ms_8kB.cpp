#include<iostream>
//typedef long long ll;
using namespace std;

int main(void)
{
    long long a;
    long long in1 , in2, sum=0;
    cin >> a;
    for(long long b=0;b<a;b++){
        cin >> in1 >> in2;
        sum+=(in2-in1);
    }
    cout << sum << endl;

    return 0;
}
