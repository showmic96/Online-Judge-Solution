// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>a , b , c , d;

bool overflow , zero;

vector<int> multiply (vector<int>v)
{
    ll temp = v[0];
    int si =v.size();

    for(int i=1;i<si;i++){

        temp*=2;
        temp+=v[i];
    }

    temp*=2;

    if(temp>2147483647){overflow = true;return v;}
    if(temp==0){zero=true;return v;}

    v.clear();

    while(temp!=0){

        v.push_back(temp%2);
        temp/=2;
    }

    while(v.size()!=si)v.push_back(0);
    reverse(v.begin(),v.end());

    return v;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){

        if(space)cout << endl;space = true;

        string ar , br;
        cin >> ar >> br;
        cout << ar << " " << br << endl;

        a.clear();
        b.clear();
        c.clear();
        d.clear();

        int si = ar.size();

        for(int i=0;i<si;i++){

            a.push_back(ar[i]-'0');
            b.push_back(br[i]-'0');
            c.push_back(0);
            d.push_back(0);
        }

        while(true){

            for(int i=0;i<si;i++){

                if(a[i]!=b[i])c[i] = 1;
                else c[i] = 0;
            }

            for(int i=0;i<si;i++){

                if(a[i]==b[i]&&a[i]==1)d[i] = 1;
                else d[i] = 0;
            }

            zero = false;
            overflow = false;

            d = multiply(d);

            for(int i=0;i<si;i++)cout << c[i];
            cout << " ";

            if(zero==true||overflow==true){

                if(overflow==true)cout << "overflow" << endl;

                else{

                    for(int i=0;i<si;i++)cout << d[i];
                    cout << endl;
                }

                break;
            }

            else{

                for(int i=0;i<si;i++)cout << d[i];
                cout << endl;
            }

            a = c;
            b = d;

        }
    }
    return 0;
}
