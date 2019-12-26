// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    double g , s , b;

    myStruct(double a, double d, double c){

        g = a;
        s = d;
        b = c;
    }
};

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;

        myStruct canada(0 , 0 , 0);
        vector<myStruct>v;

        for(int i=0;i<n;i++){

            string ar;
            int g , s , b;

            cin >> ar >> g >> s >> b;

            if(ar=="Canada"){

                canada.g = g;
                canada.s = s;
                canada.b = b;
            }

            else{

                v.push_back(myStruct(g , s , b));
            }
        }

        bool check = false;

        for(int i=0;i<111;i++){

            for(int j=0;j<111;j++){

                for(int k=0;k<111;k++){

                    double _i = i , _j = j , _k = k;
                    double v_canada = _i*canada.g+_j*canada.s+_k*canada.b;
                    double v_mx = 0;

                    for(int l=0;l<n-1;l++){

                        double temp = v[l].g*_i+v[l].s*_j+v[l].b*_k;
                        v_mx = max(v_mx , temp);
                    }

                    if(v_mx<v_canada)check = true;
                }
            }
        }

        if(check==true)cout << "Canada wins!" << endl;
        else cout << "Canada cannot win." << endl;
    }
    return 0;
}
