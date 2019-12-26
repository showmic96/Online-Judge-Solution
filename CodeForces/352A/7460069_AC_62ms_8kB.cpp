// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a , in , f_counter = 0 , z_counter=0;
    cin >> a;

    while(a--){

        cin >> in;
        if(in==5)f_counter++;
        if(in==0)z_counter++;
    }

    if(z_counter==0){cout << -1 << endl;}
    else if(f_counter/9>0){
        int lim = (f_counter/9)*9;
        for(int i=0;i<lim;i++)cout << 5;
        for(int i=0;i<z_counter;i++)cout << 0;
        cout << endl;
    }
    else cout << 0 << endl;

    return 0;
}
