#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isRepeated(int a)
{
    int ar[10];
    int d = 0;
    bool check = false;

    while(a!=0){

        ar[d] = a%10;
        d++;
        a/=10;
    }

    sort(ar , ar+d);

    for(int i=0;i<d-1;i++){

        if(ar[i]==ar[i+1])check=true;
    }

    return check;
}

int main(void)
{
    int a, b;

    while(cin >> a >> b){

        int counter = 0;
        for(;a<=b;a++){

            if(isRepeated(a)==false)counter++;
        }

        cout << counter << endl;
    }

    return 0;
}
