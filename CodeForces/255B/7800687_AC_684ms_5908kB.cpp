// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar ;
    cin >> ar;

    int si = ar.size() , x_counter = 0 , y_counter = 0;

    for(int i=0;i<si;i++){

        if(ar[i]=='x')x_counter++;
        else y_counter++;
    }

    if(x_counter>y_counter)for(int i=0;i<x_counter-y_counter;i++)cout << 'x';
    else for(int i=0;i<y_counter-x_counter;i++)cout << 'y';
    cout << endl;

    return 0;
}
