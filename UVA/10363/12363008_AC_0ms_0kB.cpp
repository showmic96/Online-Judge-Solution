// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string ar[3];
        int x1 = 0 , y1 = 0 , x , y;

        for(int i=0;i<3;i++){

            cin >> ar[i];
            for(int j=0;j<3;j++){

                if(ar[i][j]=='X')x1++;
                if(ar[i][j]=='O')y1++;
            }
        }

        if(y1>x1)cout << "no" << endl;
        else if(abs(x1-y1)>1)cout << "no" << endl;
        else{

            x = 0 , y = 0;

            for(int i=0;i<3;i++){

                if(ar[i][0]=='X'&&ar[i][1]=='X'&&ar[i][2]=='X')x++;
                if(ar[i][0]=='O'&&ar[i][1]=='O'&&ar[i][2]=='O')y++;
                if(ar[0][i]=='X'&&ar[1][i]=='X'&&ar[2][i]=='X')x++;
                if(ar[0][i]=='O'&&ar[1][i]=='O'&&ar[2][i]=='O')y++;
            }

            if(ar[0][0]=='X'&&ar[1][1]=='X'&&ar[2][2]=='X')x++;
            if(ar[0][0]=='O'&&ar[1][1]=='O'&&ar[2][2]=='O')y++;

            if(ar[0][2]=='X'&&ar[1][1]=='X'&&ar[2][0]=='X')x++;
            if(ar[0][2]=='O'&&ar[1][1]=='O'&&ar[2][0]=='O')y++;

            if(x==y&&x!=0)cout << "no" << endl;
            else if(x>y&&x1<=y1)cout << "no" << endl;
            else if(y>x&&x1!=y1)cout << "no" << endl;
            else if(abs(x-y)<=1)cout << "yes" << endl;
            else if(abs(x-y)==2){

                if(x>y){

                    int counter = 0;

                    for(int i=0;i<3;i++){

                        if(ar[i][0]=='X'&&ar[i][1]=='X'&&ar[i][2]=='X')counter++;
                    }

                    if(counter==0){

                        for(int i=0;i<3;i++){

                            if(ar[0][i]=='X'&&ar[1][i]=='X'&&ar[2][i]=='X')counter++;
                        }
                    }

                    if(counter==0){

                        if(ar[0][0]=='X'&&ar[1][1]=='X'&&ar[2][2]=='X')counter++;
                    }

                    if(counter==1)cout << "yes" << endl;
                    else cout << "no" << endl;
                }

                else{

                    int counter = 0;

                    for(int i=0;i<3;i++){

                        if(ar[i][0]=='O'&&ar[i][1]=='O'&&ar[i][2]=='O')counter++;
                    }

                    if(counter==0){

                        for(int i=0;i<3;i++){

                            if(ar[0][i]=='O'&&ar[1][i]=='O'&&ar[2][i]=='O')counter++;
                        }
                    }

                    if(counter==0){

                        if(ar[0][0]=='O'&&ar[1][1]=='O'&&ar[2][2]=='O')counter++;
                    }

                    if(counter==1)cout << "yes" << endl;
                    else cout << "no" << endl;
                }
            }

            else cout << "no" << endl;
        }
    }

    return 0;
}
