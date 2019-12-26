#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int ar[MAX+1] , br[MAX+1] , cr[MAX+1];

void sum(int a)
{
    int temp = 0;

    int d = 0;

    for(int i = a-1;i>=0;i--){

        temp = temp + ar[i] + br[i];

        if(temp<10){cr[d]=temp;temp=0;d++;}
        else{

            cr[d]=temp%10;
            temp=temp/10;
            d++;
        }
    }
    if(temp!=0){cr[d]=temp;d++;}

    for(int i=d-1;i>=0;i--)cout << cr[i];
    cout << endl;
}


int main(void)
{
    int a , m;
    cin >> a;

    bool space = false;

    while(a--){

        if(space)cout << endl;
        space = true;

        cin >> m;

        for(int i=0;i<m;i++){

            cin >> ar[i] >> br[i];
        }

        sum(m);

    }

    return 0;
}
