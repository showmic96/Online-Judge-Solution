#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

using namespace std;

int main(void)
{
    long long a=0 , f, c ,d ,e,g,k=0;
    char b[50];
    cin >> e;
    for(g=0;g<e;g++){
            cout << "Case " << g+1 <<":" << endl;
            k=0;a=0;
    cin >> c;
    for(d=0;d<c;d++){
    cin >> b;
    if(b[0]=='d')
    {   cin >> f ;
        a+=f;
    }
    else
    {   if(k==0){k=1;}
        cout << a << endl;
    }
    }
    }

    return 0;
}
