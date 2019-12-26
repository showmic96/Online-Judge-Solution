#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


map<string,string>where_double;
map<string,int>counter;
map<string,int>is_clear_once;
string ar , br ,cr , dr;
string name[1010];
int hi = 0 , d = 0;

void show()
{
    sort(name,name+d);
    for(int i = hi ; i>=0;i--){

        for(int j = 0; j<d;j++){

            if(counter[name[j]]==i)cout << name[j] << " " << i<< endl;
        }
    }

    counter.clear();
    where_double.clear();
    is_clear_once.clear();

    for(int i=0;i<d;i++)name[i]="";
    hi = 0 , d=0;

}


int main(void)
{
    bool check =false;
    while(getline(cin , ar)){

        if(ar[0]=='0')break;
        if(ar[0]=='1')show();

        if(ar[0]>='A'&&ar[0]<='Z'){

            br = ar;
            name[d]=ar;
            d++;
        }

        else if(ar[0]>='a'&&ar[0]<='z'){

            if(where_double[ar]==""){
                //cout << "yse" << endl;
                where_double[ar] = br;
                counter[br]++;
                if(hi<counter[br])hi=counter[br];

            }
            else if(where_double[ar]==br){

            }

            else {

                if(!is_clear_once[ar]){counter[where_double[ar]]--;is_clear_once[ar]=1;}
            }
        }
    }

    return 0;
}
