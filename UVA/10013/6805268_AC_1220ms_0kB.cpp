#include<bits/stdc++.h>
using namespace std;

int ar[1000001] , br[1000001];
int cr[1000001];

void show_sum(long a)
{
    //cout << "YES";



    int temp = 0 , d=0;
    for(int i=a-1;i>=0;i--){

        if(ar[i]+br[i]+temp<10){

            cr[d]=ar[i]+br[i]+temp;
            temp = 0;
            d++;
        }

        else{
            cr[d]=(ar[i]+br[i]+temp)%10;
            temp = (ar[i]+br[i]+temp)/10;
            d++;
        }
    }

    for(int i = d-1;i>=0;i--)cout << cr[i];
    cout << endl;

}


int main(void)
{
    long int a;

    cin >> a;
    int t=0;
    while(a--){

        if(t==1)cout << endl;t=1;
        long int b;

        cin >> b;

        long int in1 , in2 , d=0;

        while(b--){

            cin >> ar[d] >> br[d];
            d++;
        }
        //cout << "yes";
        show_sum(d);

    }
    return 0;
}
