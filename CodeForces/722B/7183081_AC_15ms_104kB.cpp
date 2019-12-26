#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char x)
{
    if(x=='a')return true;
    else if(x=='e')return true;
    else if(x=='i')return true;
    else if(x=='o')return true;
    else if(x=='u')return true;
    else if(x=='y')return true;
    return false;
}

int main(void)
{
    int a;
    cin >> a;

    int value[a];

    string ar;

    bool check = true;

    for(int j=0;j<a;j++)cin >> value[j];

    scanf("\n");

    for(int i=0;i<a;i++){

        getline(cin , ar);

        int si = ar.size();

        int counter = 0;

        for(int j=0;j<si;j++){

            if(is_vowel(ar[j])==true)counter++;
        }

        //if(counter==0)counter = 1;

        //cout << value[i] << " " << counter << endl;

        if(value[i]!=counter)check = false;
    }

    if(check==false)cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
