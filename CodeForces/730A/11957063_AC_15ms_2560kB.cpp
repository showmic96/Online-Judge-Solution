// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data{

    ll value , idx;

    data(ll _value , ll _idx){

        value = _value;
        idx = _idx;
    }
};

bool operator<(data A , data B)
{
    return A.value<B.value;
}

vector<data>v;
vector<string>ans;
int n;

void do_the_work()
{
    string a = "";

    for(int i=0;i<n;i++)a+='0';

    while(true){

        sort(v.begin() , v.end());
        bool check = true;
//cout << v[0].value << endl;
        for(int i=0;i<n-1;i++){

            if(v[i].value!=v[i+1].value){check = false;break;}
        }

        if(check==true)break;

        int i = n-1;
        int counter = 0;
        int temp = v[i].value;

        while(v[i].value==temp){

            i--;
            counter++;
        }

        for(int i=n-1;i>=0;i--){

            if(counter%2==0){

                v[i].value--;
                v[i-1].value--;

                if(v[i].value<0)v[i].value = 0;
                if(v[i-1].value<0)v[i-1].value = 0;

                string tt = a;

                tt[v[i].idx] = '1';
                tt[v[i-1].idx] = '1';
                ans.push_back(tt);

            }

            else if(i-2>=0&&counter%3==0){


                v[i].value--;
                v[i-1].value--;
                v[i-2].value--;

                if(v[i].value<0)v[i].value = 0;
                if(v[i-1].value<0)v[i-1].value = 0;
                if(v[i-2].value<0)v[i-2].value = 0;

                string tt = a;

                tt[v[i].idx] = '1';
                tt[v[i-1].idx] = '1';
                tt[v[i-2].idx] = '1';


                ans.push_back(tt);

            }

            else if(i-4>=0&&(v[i].value==v[i-4].value&&v[i].value==v[i-1].value&&v[i].value==v[i-2].value&&v[i].value==v[i-3].value)){

                v[i].value--;
                v[i-1].value--;
                v[i-2].value--;
                v[i-3].value--;
                v[i-4].value--;

                if(v[i].value<0)v[i].value = 0;
                if(v[i-1].value<0)v[i-1].value = 0;
                if(v[i-2].value<0)v[i-2].value = 0;
                if(v[i-3].value<0)v[i-3].value = 0;
                if(v[i-4].value<0)v[i-4].value = 0;

                string tt = a;

                tt[v[i].idx] = '1';
                tt[v[i-1].idx] = '1';
                tt[v[i-2].idx] = '1';
                tt[v[i-3].idx] = '1';
                tt[v[i-4].idx] = '1';

                ans.push_back(tt);

            }

            else if(i-3>=0&&(v[i].value==v[i-1].value&&v[i].value==v[i-2].value&&v[i].value==v[i-3].value)){

                v[i].value--;
                v[i-1].value--;
                v[i-2].value--;
                v[i-3].value--;

                if(v[i].value<0)v[i].value = 0;
                if(v[i-1].value<0)v[i-1].value = 0;
                if(v[i-2].value<0)v[i-2].value = 0;
                if(v[i-3].value<0)v[i-3].value = 0;

                string tt = a;

                tt[v[i].idx] = '1';
                tt[v[i-1].idx] = '1';
                tt[v[i-2].idx] = '1';
                tt[v[i-3].idx] = '1';

                ans.push_back(tt);

            }

            else if(i-2>=0&&(v[i].value==v[i-1].value&&v[i].value==v[i-2].value)){


                v[i].value--;
                v[i-1].value--;
                v[i-2].value--;

                if(v[i].value<0)v[i].value = 0;
                if(v[i-1].value<0)v[i-1].value = 0;
                if(v[i-2].value<0)v[i-2].value = 0;

                string tt = a;

                tt[v[i].idx] = '1';
                tt[v[i-1].idx] = '1';
                tt[v[i-2].idx] = '1';


                ans.push_back(tt);

            }

            else{

                v[i].value--;
                v[i-1].value--;

                if(v[i].value<0)v[i].value = 0;
                if(v[i-1].value<0)v[i-1].value = 0;

                string tt = a;

                tt[v[i].idx] = '1';
                tt[v[i-1].idx] = '1';
                ans.push_back(tt);
            }

            break;
        }
    }


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(data(in , i));
    }

    do_the_work();

    sort(v.begin() , v.end());

    cout << v[0].value << endl;
    cout << ans.size() << endl;

    for(int i=0;i<ans.size();i++){

        cout << ans[i] << endl;
    }

    return 0;
}
