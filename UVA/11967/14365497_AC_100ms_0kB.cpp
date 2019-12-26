// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll> > v1 , v2;
map<pair<ll , ll> , int>x , y;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);

        v1.clear();v2.clear();
        x.clear();y.clear();

        for(int i=0;i<n;i++){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);
            if(i%2==0){

                x[make_pair(in1 , in2)] = 1;
                v1.push_back(make_pair(in1 , in2));
            }
            else{

                y[make_pair(in1 , in2)] = 1;
                v2.push_back(make_pair(in1 , in2));
            }
        }

        bool c1 = false, c2 = false;

        for(int i=0;i<v1.size();i++){

            if(c1==true)break;

            ll t1 = v1[i].first;
            ll t2 = v1[i].second;

            bool check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1+i , t2+i))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1-i , t2-i))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1+i , t2-i))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1-i , t2+i))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1+i , t2))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1-i , t2))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1 , t2+i))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(x.find(make_pair(t1 , t2-i))==x.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c1 = true;
                break;
            }
        }

        for(int i=0;i<v2.size();i++){

            if(c2==true)break;

            ll t1 = v2[i].first;
            ll t2 = v2[i].second;

            bool check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1+i , t2+i))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1-i , t2-i))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1+i , t2-i))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1-i , t2+i))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1+i , t2))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1-i , t2))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1 , t2+i))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }

            check = true;
            for(int i=1;i<k;i++){

                if(y.find(make_pair(t1 , t2-i))==y.end()){

                    check = false;
                    break;
                }
            }
            if(check==true){

                c2 = true;
                break;
            }
        }

        if(c1==true&&c2==true)printf("Case %d: error\n",++c);
        else if(c1==true)printf("Case %d: crosses\n",++c);
        else if(c2==true)printf("Case %d: noughts\n",++c);
        else printf("Case %d: none\n",++c);
    }
    return 0;
}
