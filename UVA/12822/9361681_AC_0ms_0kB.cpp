// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    string status;
    int h , m , s;

    myStruct(int _h , int _m , int _s){

        h = _h;
        m = _m;
        s = _s;
    }
};

vector<myStruct>v;
int val[] = {6 , 2 , 5 , 5, 4 , 5 , 6 , 3 , 7 , 6};

int value(int a)
{
    if(a==0)return val[0];

    int sum = 0;

    while(a!=0){

        sum+=val[a%10];
        a/=10;
    }

    return sum;
}

int main(void)
{
    int t = 0;
    string ar;

    while(getline(cin , ar)){

        //scanf("\n");
        v.clear();
        vector< pair <int , int> > score;
        string status;
        int hour , mi , sec , h = 0 , a = 0;
        char x;

        stringstream ss(ar);
        ss >> status;
        ss >> hour;
        ss >> x;
        ss >> mi;
        ss >> x;
        ss >> sec;

        score.push_back(make_pair(0 , 0));

        while(getline(cin , ar)){

            stringstream s(ar);
            string status_temp;
            int hour_temp , mi_temp , sec_temp;
            char x_temp;

            s >> status_temp;
            s >> hour_temp;
            s >> x;
            s >> mi_temp;
            s >> x;
            s >> sec_temp;

            v.push_back(myStruct(hour_temp , mi_temp , sec_temp));

            if(status_temp=="END")break;

            string who;
            int t;

            s >> who;
            s >> t;

            if(who=="home")h+=t;
            else a+=t;

            score.push_back(make_pair(h , a));
        }

        ll ans = 0;

        int si = v.size();

        for(int i=0;i<si;i++){

            int counter = 0;

            while(true){

                if(hour==v[i].h&&mi==v[i].m&&sec==v[i].s){

                    ans+=(counter*value(score[i].first));
                    ans+=(counter*value(score[i].second));
                    break;
                }

                sec++;

                if(sec==60){sec=0;mi++;}
                if(mi==60){mi = 0;hour++;}

                counter++;
            }
        }

        printf("Case %d: %lld\n",++t , ans);
    }
    return 0;
}
