// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar , br="" , cr="";

    getline(cin , ar);

    br = ar;

    int si = ar.size() , counter1 = 0 , counter2 = 0;

    for(int i=0;i<si-1;i++){

        if(ar[i]==ar[i+1]&&ar[i+1]+7<='z'){ar[i+1]=ar[i+1]+7;if(i+2<si)if(ar[i+1]==ar[i+2])ar[i+1]=ar[i+1]-1;counter1++;}
        else if(ar[i]==ar[i+1]){ar[i+1]=ar[i+1]-7;if(i+2<si)if(ar[i+1]==ar[i+2])ar[i+1]=ar[i+1]+1;counter2++;}

    }

    cout << ar << endl;
    return 0;
}