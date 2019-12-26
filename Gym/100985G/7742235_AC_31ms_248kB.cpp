// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    string ar;
    int counter = 0;
    cin >> ar;

    int si = ar.size();

    bool check = true;

    for(int i=0;i<si;i++){

        if(ar[i]=='A')counter++;
        else counter--;
        if(counter<0)check=false;
    }
    if(counter>0)check=false;

    if(check==true)cout << "Sim" << endl;
    else cout << "Nao" << endl;

    return 0;
}
