#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string ar;
        int n;
        cin >> n;
        cin >> ar;

        bool check1 = false , check2 = false , check3 = false;

        for(int i=0;i<ar.size();i++){

            if(ar[i]=='Y')check1 = true;
            if(ar[i]=='N')check2 = true;
            if(ar[i]=='I')check3 = true;
        }

        if(check3==true)cout << "INDIAN" << endl;
        else if(check1==false&&check3==false)cout << "NOT SURE" << endl;
        else if(check1==true&&check2==true&&check3==false)cout << "NOT INDIAN" << endl;
        else if(check1==true&&check2==false)cout << "NOT INDIAN" << endl;
    }

    return 0;
}
