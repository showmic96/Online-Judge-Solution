// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int a;
    string ar;
    cin >> a;
    cin >> ar;

    for(int i=0;i<a;i++){

        if(ar[i]!='o')cout << ar[i];
        else{
            bool check = false;

            while(true){

                if(ar[i]=='o'&&ar[i+1]=='g'&&ar[i+2]=='o'){i+=2;if(check==false)cout << "***";check=true;}
                //else if(ar[i]=='o'&&ar[i+1]!='g'){break;}
                else {

                    if(check==false)cout << ar[i];
                        break;
                }

            }
        }
    }

    cout << endl;


    return 0;
}
