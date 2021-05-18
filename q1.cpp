#include<bits/stdc++.h>
using namespace std;
#define MAX_LIMIT 1000
#define CURRENT_YEAR 2021
int main()
{
        string name;
        int age;
        cout<<"What is your name?"<<endl;
        cout<<"> ";
        // using getline to input whole string until new line char occurs
        getline(cin,name);
        cout<<"Hello, "<<name<<"!"<<endl;
        cout<<"What year you were born?"<<endl;
        cout<<"> ";
        //Ensure birth year is not greater than current year
        cin>>age;
        // Not including current year
        age=CURRENT_YEAR-age-1;
        cout<<"Congratulations, you are "<<age<<" years old!"<<endl;
        return 0;
}
