#include<bits/stdc++.h>
using namespace std;

int ar[10010];

int main(void)
{
    int a , ans , b;

    cin >> a;
    cin >> ans;

    for(int i=0; i<a-1; i++)cin >> ar[i];

    sort(ar , ar+a-1 ,greater<int>());

    int counter = 0;

    while(true)
    {

        if(ans>ar[0])break;

        for(int i=0; i<a-1; i++)
        {

            if(ans<=ar[i])
            {
                if(i!=0){

                    if(ar[i]<=ar[i-1])break;
                }
                ans++;
                ar[i]--;
                counter++;
            }

        }

    }
    cout << counter << endl;

    return 0;

}
