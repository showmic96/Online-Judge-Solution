// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    string name;
    int point;

}data[123456];

bool cmp(struct myStruct A , struct myStruct B)
{
    if(A.point==B.point){
            //cout << "YES" << endl;
            int si = min(A.name.size() , B.name.size());

            for(int i=0;i<si;i++){

                if(A.name[i]!=B.name[i]){

                    if(A.name[i]>B.name[i])return false;
                    return true;
                }
            }

            return A.name < B.name;
    }

    return A.point > B.point;
}

string make(string ar)
{
    string temp = "";
    int si = ar.size();

    for(int i=0;i<si-2;i++)temp+=ar[i];

    return temp;
}

int main(void)
{
    map<string , int>mp;
    string name;
    cin >> name;
    int t;
    cin >> t;
    scanf("\n");

    int c = 1;

    mp[name] = c++;
    data[1].name = name;
    data[1].point = 0;

    while(t--){

        string in , first , last , wd , nn;

        getline(cin , in);
        stringstream ss(in);

        ss >> first;
        ss >> wd;
        ss >> nn;
        if(nn=="on")ss >> last;
        else last = nn;
        ss >> nn;
        //cout << last << endl;
        last = make(last);
        //cout << last << endl;

        //if(first!=name && last!=name)continue;

        if(mp[first]==0){mp[first] = c; data[c].name = first;data[c].point = 0;c++;}
        if(mp[last]==0){mp[last] = c;data[c].name = last;data[c].point = 0;c++;}
        if(first!=name&&last!=name)continue;
        if(wd=="likes"){

            data[mp[first]].point+=5;
            data[mp[last]].point+=5;
        }

        if(wd=="posted"){

            data[mp[first]].point+=15;
            data[mp[last]].point+=15;
        }

        if(wd=="commented"){

            data[mp[first]].point+=10;
            data[mp[last]].point+=10;
        }

    }

    sort(data+2 , data+c , cmp);
    for(int i=2;i<c;i++)cout << data[i].name << endl;
    return 0;
}
