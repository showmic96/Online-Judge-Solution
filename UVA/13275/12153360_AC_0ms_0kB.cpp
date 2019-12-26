// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}


int main(void)
{
    int t , c = 1;
    cin >> t;

    while(t--){

        int in1 , in2 , in3 , in4;
        cin >> in1 >> in2 >> in3 >> in4;

        if(in2==2&&in1==29){

            int counter = 0;
            for(int i=in3+1;i<=in4;i++){

                if(isLeapYear(i)==true)counter++;
            }

            cout << "Case " << c++ << ": " << counter << endl;
        }
        else {

            cout << "Case " << c++ << ": " << in4-in3 << endl;
        }
    }

    return 0;
}
