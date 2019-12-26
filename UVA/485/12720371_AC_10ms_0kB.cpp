// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

string add(string a , string b)
{
    if(a.size()<b.size())swap(a , b);
    if(a.size()==b.size()&&a<b)swap(a , b);
    string temp = "";
    int last = 0;

    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());

    int si = a.size();

    for(int i=0;i<si;i++){

        int t1 = a[i]-'0';
        int t2 = 0;
        if(b.size()>i)t2 = b[i]-'0';

        last = last+t1+t2;
        temp+='0'+(last%10);
        last/=10;
    }

    while(last){

        temp+='0'+(last%10);
        last/=10;
    }

    reverse(temp.begin() , temp.end());

    return temp;
}

int main(void)
{

    vector<string>v , temp;

    v.push_back("0");
    v.push_back("1");
    v.push_back("0");

    string mx = "" , cur="";
    for(int i=0;i<60;i++)mx+="9";
    printf("1\n");

    while(true){

        temp.clear();

        if(mx.size()<cur.size())break;

        temp.push_back("0");

        int si = v.size();

        for(int i=1;i<si;i++){

            string t = add(v[i] , v[i-1]);

            temp.push_back(t);

            if(t.size()>cur.size()){

                cur = t;
            }
        }

        temp.push_back("0");
        v = temp;

        si = v.size();

        for(int i=1;i<si-1;i++){

            int ss = v[i].size();
            if(i>1)printf(" ");
            for(int j=0;j<ss;j++)printf("%c",v[i][j]);
        }

        printf("\n");
    }

    return 0;
}
