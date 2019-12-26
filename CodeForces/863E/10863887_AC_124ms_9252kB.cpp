// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data{

    ll l , r , idx;

    data(ll _l , ll _r , ll _idx){

        l = _l;
        r = _r;
        idx = _idx;
    }
};

bool operator<(data A , data B)
{
    if(A.l==B.l){

        return A.r > B.r;
    }

    return A.l<B.l;
}

vector<data>v;

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);
        v.push_back(data(in1 , in2 , i+1));
    }

    sort(v.begin() , v.end());

    ll ans = -1 , l=-1 , r = -1 , counter = 0;
    vector<ll>check;

    for(int i=0;i<n;i++){

        if(v[i].l>=l&&v[i].r<=r){

            ans = v[i].idx;
            break;
        }

        else if(v[i].l<=r+1){

            int i1 = i;

            while(v[i1].l<=r+1){

                counter++;
                check.push_back(v[i1].r);
                i1++;
                if(i1==n)break;
            }

            l = v[i].l;
            r = max(r, v[i].r);

        }

        else {

            l = v[i].l;
            r = max(r, v[i].r);
            counter = 0;
            check.clear();
        }

        if(counter>1){

            if(check[0]<check[1]){

                ans = v[i].idx;
            }
            else{

                ans = v[i+1].idx;
            }
            break;
        }

        counter = 0;
        check.clear();
    }

    printf("%lld\n",ans);

    return 0;
}
