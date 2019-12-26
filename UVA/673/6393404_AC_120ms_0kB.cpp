#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    string ar;
    scanf("\n");
    while(a--){


        stack<char>input;
        getline(cin , ar);
        bool check = true;
        if(ar.compare("n")==0){cout << "Yes"<< endl;continue;}
        if(ar.size()==1||ar.size()%2!=0){cout << "No"<< endl;continue;}
        for(int i=0;i<ar.size();i++){

            if(ar[i]=='('||ar[i]=='[')input.push(ar[i]);
            else if(ar[i]==')'&&input.empty()==false&&input.top()=='('){input.pop();}
            //else if(ar[i]=='}'&&input.empty()==false&&input.top()=='{'){input.pop();}
            else if(ar[i]==']'&&input.empty()==false&&input.top()=='['){input.pop();}
            else {check=false;break;}
            }

        if(check==true&&input.empty()==true)cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
