// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point{

    double left , right;

    point(double _left , double _right){

        left = _left;
        right = _right;
    }
};

bool operator<(point A , point B)
{
    return A.left<B.left;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        double l , w;
        scanf("%lf %lf",&l , &w);

        vector<point>v;

        for(int i=0;i<n;i++){

            double x , r;
            scanf("%lf %lf",&x , &r);

            double temp = sqrt(r*r-w*w/4.0);

            if(r<=w/2)continue;

            v.push_back(point(x-temp , x+temp));
        }

        sort(v.begin() , v.end());

        double last = 0;
        int si = v.size() , counter = 0;

        for(int i=0;i<si;i++){

            if(last>=l)break;

            if(v[i].left<=last){

                double temp = last;

                while(v[i].left<=last){

                    temp = max(temp , v[i].right);
                    i++;
                    if(i>=si)break;
                }

                last = temp;

                i--;
                counter++;
            }

        }

        if(last<l)counter = -1;

        printf("%d\n",counter);
    }
    return 0;
}
