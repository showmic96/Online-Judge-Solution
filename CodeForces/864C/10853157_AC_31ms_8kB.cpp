// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    ll a , b , f , k , counter = 0 , d = 1 , p = 0;
    cin >> a >> b >> f >> k;

    ll b_fixed = b;

    bool check = true;

    while(k!=0){
    if(d==0&&p==0) d = 1;
        if(d==1){

            if(p==0){

                b-=f;
                if(b<0)check = false;

                if(k==1){

                    if(a-f>b){

                        counter++;

                        if(a-f>b_fixed)check = false;
                    }
                }

                else{

                    if(2*(a-f)>b){

                        counter++;
                        b = b_fixed;

                        d = 0;
                        p = 1;

                        b-=2*(a-f);
                        if(b<0)check = false;
                    }

                    else {

                        b-=2*(a-f);
                        d = 0;
                        p = 1;
                    }
                }

                k--;
            }
        }

        else if(d==0){

            if(k==1){

                if(b<f){counter++;b = b_fixed;}
                b-=f;
                if(b<0)check = false;
                d = 0;
                p = 0;

            }

            else{

                if(b<2*f){counter++; b = b_fixed;}

                b-=f;
                if(b<0)check = false;
                d = 0;
                p = 0;
            }

            k--;
        }
    }

    if(check==true)cout << counter << endl;
    else cout << -1 << endl;

    return 0;
}
