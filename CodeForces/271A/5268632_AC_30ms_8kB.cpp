#include<iostream>
#include<string>
//#include<string.h>
using namespace std;
int main(void)
{
    int i ,k ;
    int a[10];
    cin >> k;
    for(i=k+1; ;i++ )
    {
        a[0]=i/1000; a[1]=i%1000;
        a[2]=a[1]/100;a[3]=a[1]%100;
        a[4]=a[3]/10;a[5]=a[3]%10;
        if (a[0]!=a[2]&&a[0]!=a[4]&&a[0]!=a[5]&&a[2]!=a[4]&&a[2]!=a[5]&&a[4]!=a[5])/*&&a[3]!=a[4]&&a[4]!=a[5])*/ break ;


    }
    cout << i;

    return 0;

}
