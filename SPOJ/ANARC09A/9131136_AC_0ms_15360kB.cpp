// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar;
    int c = 0;
    while(cin >> ar){

        if(ar[0]=='-')break;

        int si = ar.size();
        stack<char>st;
        int counter = 0;

        for(int i=0;i<si;i++){

            if(ar[i]=='}'){

                if(st.empty()==true){st.push('{');counter++;}
                else if(st.top()=='{')st.pop();
            }

            if(ar[i]=='{'){

                st.push('{');
            }
        }

        counter+=st.size()/2;

        cout << ++c << ". " << counter << endl;
    }
    return 0;
}
