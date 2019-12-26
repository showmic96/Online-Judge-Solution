#include<iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int a,c,d,e ;
    double b[10];
    for(a=0;a<10;a++)
    cin >> b[a];
    sort(b,b+10);
    cout << b[9] << endl << b[8] << endl << b[7] << endl;
    return 0;


}
