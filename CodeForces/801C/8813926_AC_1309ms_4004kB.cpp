// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;
int n;
double p , need = 0;

struct myStruct{

    double a , b;

}data[123456];

bool is_it(double s)
{
    double p_temp = p*s;
    for(int i=0;i<n;i++){

        p_temp -= max(0.0 , data[i].a*s-data[i].b);
    }
    //cout << p_temp << " " << s << endl;
    if(p_temp<0)return false;
    return true;
}

int main(void)
{

    cin >> n >> p;

    for(int i=0;i<n;i++){

        cin >> data[i].a >> data[i].b;
        need+=data[i].a;
    }

    if(need<=p){

        cout << -1 << endl;
    }

    else{

        int t = 1234;

        double hi = 1e12 , low = 0 , mid;


        while(t--){

            mid = (hi+low)/2;

            if(is_it(mid)==true){

                low = mid;
            }

            else hi = mid;
        }

        printf("%.14f\n",mid);
    }

    return 0;
}
