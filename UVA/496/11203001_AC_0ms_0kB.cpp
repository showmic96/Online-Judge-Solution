// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ar;
    while(getline(cin , ar)){

        string br;
        getline(cin , br);

        set<int>st1 , st2;

        stringstream ss(ar);

        int in;

        while(ss >> in){

            st1.insert(in);
        }

        stringstream s(br);

        while(s >> in){

            st2.insert(in);
        }

        bool check1 = true, check2 = true , check3 = true;

        for(set<int>::iterator it = st1.begin();it!=st1.end();it++){

            if(st2.find(*it)!=st2.end()){

                check3 = false;
            }
            else{
                check1 = false;
            }
        }

        for(set<int>::iterator it = st2.begin();it!=st2.end();it++){

            if(st1.find(*it)!=st1.end()){

                check3 = false;
            }
            else{
                check2 = false;
            }
        }

        if(check1==true&&check2==true)printf("A equals B\n");
        else if(check1==true&&check2==false)printf("A is a proper subset of B\n");
        else if(check1==false&&check2==true)printf("B is a proper subset of A\n");
        else if(check1==false&&check2==false){

            check1 = true, check2 = true;

            for(set<int>::iterator it = st1.begin();it!=st1.end();it++){

                if(st2.find(*it)==st2.end()){

                    check3 = false;
                }
                else{
                    check1 = false;
                }
            }

            for(set<int>::iterator it = st2.begin();it!=st2.end();it++){

                if(st1.find(*it)==st1.end()){

                    check3 = false;
                }
                else{
                    check2 = false;
                }
            }

            if(check1==true&&check2==true)printf("A and B are disjoint\n");
            else printf("I'm confused!\n");
        }
    }

    return 0;
}
