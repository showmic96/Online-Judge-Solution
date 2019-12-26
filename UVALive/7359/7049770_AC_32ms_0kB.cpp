#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(void)
{
    int a;
    cin >> a;
    int case_ ;
    ll input;

    while(a--){

        cin >> case_ >> input;

        cout << case_ << " " << input*(input+1)/2 << " " << input*input << " " << input*(input+1) << endl;
    }
    return 0;
}
