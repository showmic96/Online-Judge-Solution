#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double h , u, d , f;

    while(cin >> h >> u >> d >> f){

        if(!h&&!u&&!d&&!f)break;

        double current_height = 0;
        int counter = 1;

        current_height+=u;

        f=(u*f/100);

        while(true){

            //cout << current_height << endl;

            if(current_height>h)break;

            current_height-=d;

            u -= f;

            if(current_height<0)break;

            if(u<0)u=0;

            current_height+=u;

            counter++;
        }

        if(current_height>=h)cout << "success on day " << counter << endl;
        else cout << "failure on day " << counter << endl;
    }
    return 0;
}
