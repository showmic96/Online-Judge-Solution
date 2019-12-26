#include<iostream>
#include<map>
#include<string.h>
#include<stdio.h>

using namespace std;

int current , p;

bool check ;

void print()
{
    if(check==true)cout << " ";
    for(int i=current;i<p;i++){
        cout << "  ";
    }
    current = p+1;
    //if(current==26)cout << "*";
    cout << "*";


}

int main(void)
{

    map<char,int>maping;

    int a = 4 , hi = 0 , si;
    char ar[750];

    while(a--){

        memset(ar , '\0' , sizeof(ar));

        gets(ar);


        si = strlen(ar);

        for(int i=0;i<si;i++){

            if(ar[i]>='A'&&ar[i]<='Z')maping[ar[i]]++;

            if(maping[ar[i]]>hi)hi = maping[ar[i]];
        }



    }



    for(int i = hi ;i >=1;i--){

            current = 0;
            check = false;
            for(int j =0;j <25;j++){
                if(maping['A'+j]>=i){p = j;print();check=true;}
                //else cout << "  ";
            }

            if(maping['Z']>=i){p=25;print();};
            cout << endl;
        }

        for(int i=0;i<25;i++)cout << (char)('A'+i) << " ";
        cout << "Z";
        cout << endl;

    return 0;
}
