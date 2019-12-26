#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        int b;
        cin >> b;
        int n; cin >> n;
        for(int j=0;j<b;j++){

            int c , d , e , f;
            cin >> c >> d >>e >> f;
            if(c==e&&d==f){cout << 0 << endl;continue;}
            if(c>n||d>n||e>n||f>n){cout << "no move" << endl;continue;}
            //cout << c << endl << d << endl << e << endl << f << endl ;
            if(((c+d)%2==0&&(e+f)%2==0)||((c+d)%2!=0&&(e+f)%2!=0)){
                if(abs(c-e)==abs(d-f))cout << 1 << endl;
            else cout << 2 << endl;

            }
            else cout << "no move" << endl;
        }
    }
    return 0;
}
//((c+d)%2==0&&(e+f)%2==0)||
