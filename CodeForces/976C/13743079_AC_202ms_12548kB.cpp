// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    int l , r , idx;
    s(int _l , int _r , int _idx){

        l = _l;
        r = _r;
        idx = _idx;
    }
};

bool cmp(s A , s B)
{
    if(A.l==B.l){

        return A.r>B.r;
    }
    return A.l<B.l;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<s> v;

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v.push_back(s(in1 , in2 , i+1));
    }

    sort(v.begin() , v.end() , cmp);

    int x = -1 , y = -1 , l = -1 , r = -1 , idx = -1;

    for(int i=0;i<n;i++){

        int t1 = v[i].l;
        int t2 = v[i].r;

        if(t1>=l&&t2<=r){

            x = v[i].idx;
            y = idx;
        }

        if(t2>r){

            l = t1;
            r = t2;
            idx = v[i].idx;
        }
    }

    printf("%d %d\n",x , y);

    return 0;
}
