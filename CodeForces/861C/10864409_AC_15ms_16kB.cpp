// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isVowel(char x)
{
    if(x=='a')return true;
    if(x=='e')return true;
    if(x=='i')return true;
    if(x=='o')return true;
    if(x=='u')return true;

    return false;
}

int main(void)
{
    string ar , temp = "";
    cin >> ar;

    int si = ar.size();

    for(int i=0;i<si;i++){

        if(i+2<si){

            if(ar[i]==ar[i+1]&&ar[i]==ar[i+2])temp+=ar[i];
            else if(isVowel(ar[i])==false&&isVowel(ar[i+1])==false&&isVowel(ar[i+2])==false){

                temp+=ar[i];
                i++;
                temp+=ar[i];
                temp+= " ";
            }
            else{

                temp+=ar[i];
            }
        }

        else{

            temp+=ar[i];
        }
    }

    cout << temp << endl;

    return 0;
}
