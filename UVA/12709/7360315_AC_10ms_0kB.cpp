#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a , l , h , w , area , ans;
    while(cin >> a){
        if(!a)break;

        area = 0 , ans = 0;

        for(int i=0;i<a;i++){

            cin >> l >> w >> h;

            if(h==ans){

                ans = h;

                if(l*w*h>area&&ans==h)area = l*w*h;
            }
            
            if(h>ans){

                ans = h;

                area = l*w*h;
            }
        }

        cout << area << endl;
    }

    return 0;
}
