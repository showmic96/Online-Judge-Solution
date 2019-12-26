// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+10;

struct myStruct{

    int solved_problem , penalty[15] , team_number , penalty_total , index;

}data[MAX];

bool cmp(struct myStruct A , struct myStruct B)
{

    if(A.solved_problem==B.solved_problem){

        if(A.penalty_total==B.penalty_total){

            return A.team_number < B.team_number;
        }

        else return A.penalty_total < B.penalty_total;
    }

    else return A.solved_problem > B.solved_problem;
}

void setUp()
{

    for(int i=0;i<MAX;i++){

        data[i].solved_problem = 0;
        memset(data[i].penalty, 0, sizeof(data[i].penalty));
        data[i].team_number = i;
        data[i].penalty_total = 0;
    }
}

int main(void)
{
    //freopen("input.txt" , "r" , stdin);

    int t;
    cin >> t;
    getchar();
    string ar;
    getline(cin , ar);

    bool space = false;
    map<int ,int>mp;
    map<pair<int, int> ,int>mp2;

    while(t--){

        mp.clear();
        mp2.clear();
        if(space)cout << endl;space = true;
        setUp();

        int counter = 0 , team_counter = 0;
        //scanf("\n");

        data[0].solved_problem = 1e9;

        while(getline(cin , ar)){

            if(ar=="")break;

            stringstream ss(ar);

            int data1 , data2 , data3;
            char indicator;

            ss >> data1;
            ss >> data2;
            ss >> data3;
            ss >> indicator;

            //cout << data1 << " " << data2 << " " << data3 << " " << indicator << endl;

            if(mp[data1]==0){mp[data1]= ++team_counter;data[mp[data1]].team_number = data1;}


            if(indicator=='C'){

                if(mp2[make_pair(mp[data1],data2)]==1)continue;
                mp2[make_pair(mp[data1],data2)]=1;
                //cout << mp2[make_pair(mp[data1],data2)] << endl;

                data[mp[data1]].solved_problem++;
                data[mp[data1]].penalty_total+=data3;
                data[mp[data1]].penalty_total+=data[mp[data1]].penalty[data2];

            }

            if(indicator=='I'){

                data[mp[data1]].penalty[data2]+=20;

            }

            counter++;
        }

        //cout << team_counter << endl;

        sort(data , data+team_counter+1 , cmp);

        for(int i=1;i<=team_counter;i++){

            //if(data[i].solved_problem==0)break;

            cout << data[i].team_number << " " << data[i].solved_problem << " " << data[i].penalty_total << endl;
        }
    }

    return 0;
}
