// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool f(string ar)
{
    for(int i=0;i<=ar.size()/2;i++)if(ar[i]!=ar[ar.size()-i-1])return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;
    cin >> ar;

    bool check = true;

    for(int i=0;i<ar.size();i++){

        string temp = "";
        for(int j=i;j<ar.size();j++){

            temp+=ar[j];
            if(temp.size()%2==0){

                if(f(temp)==true)check = false;
            }
        }
    }

    if(check)cout << "Odd." << endl;
    else cout << "Or not." << endl;

    return 0;
}
