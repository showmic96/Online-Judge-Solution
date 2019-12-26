// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<ll>n1 , n2;

ll p(int n)
{
    ll temp = 1;

    for(int i=1;i<=n;i++){

        temp*=2;
    }
    return temp;
}

void make_decimal(ll x , ll y)
{
    n1.clear();
    n2.clear();

    if(x<y)swap(x , y);

    while(x!=0){

        n1.push_back(x%2);
        x/=2;
    }

    while(y!=0){

        n2.push_back(y%2);
        y/=2;
    }

    int si = n1.size();

    while(n2.size()!=si)n2.push_back(0);

    reverse(n1.begin() , n1.end());
    reverse(n2.begin() , n2.end());
}

void print(vector<ll>v)
{
    int si = v.size();
    ll temp = 0;

    for(ll i=0;i<si;i++){

        temp+=p(si-i-1)*v[i];
    }

    printf("%lld",temp);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll in1 , in2;

        scanf("%lld %lld",&in1 ,&in2);

        make_decimal(in1 ,in2);

        vector<ll>a1 , a2;

        bool check = false;

        int si = n1.size();

        for(int i=0;i<si;i++){

            if(n1[i]!=n2[i]){

                check = true;
            }

            if(check==true)a1.push_back(0);
            else a1.push_back(n1[i]&n2[i]);
        }

        check = false;

        for(int i=0;i<si;i++){

            if(n1[i]!=n2[i]){

                check = true;
            }

            if(check==true)a2.push_back(1);
            else a2.push_back(n1[i]|n2[i]);
        }

        printf("Case %d: ",++c);
        print(a2);
        printf(" ");
        print(a1);
        printf("\n");

    }
    return 0;
}
