#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    string ar;
    getline(cin , ar);

    int si = ar.size();

    for(int i=0;i<si;i++){

        if(ar[i]>='A'&&ar[i]<='Z')ar[i] = ar[i] + 32;

        if(ar[i]=='a')cout << "@";
        else if(ar[i]=='b')cout << "8";
        else if(ar[i]=='c')cout << "(";
        else if(ar[i]=='d')cout << "|)";
        else if(ar[i]=='e')cout << "3";
        else if(ar[i]=='f')cout << "#";
        else if(ar[i]=='g')cout << "6";
        else if(ar[i]=='h')cout << "[-]";
        else if(ar[i]=='i')cout << "|";
        else if(ar[i]=='j')cout << "_|";
        else if(ar[i]=='k')cout << "|<";
        else if(ar[i]=='l')cout << "1";
        else if(ar[i]=='m')cout << "[]\\/[]";
        else if(ar[i]=='n')cout << "[]\\[]";
        else if(ar[i]=='o')cout << "0";
        else if(ar[i]=='p')cout << "|D";
        else if(ar[i]=='q')cout << "(,)";
        else if(ar[i]=='r')cout << "|Z";
        else if(ar[i]=='s')cout << "$";
        else if(ar[i]=='t')cout << "']['";
        else if(ar[i]=='u')cout << "|_|";
        else if(ar[i]=='v')cout << "\\/";
        else if(ar[i]=='w')cout << "\\/\\/";
        else if(ar[i]=='x')cout << "}{";
        else if(ar[i]=='y')cout << "`/";
        else if(ar[i]=='z')cout << "2";
        else cout << ar[i];
    }

    cout << endl;

    return 0;
}
