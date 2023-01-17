#include<bits/stdc++.h>
using namespace std;

bool is_adult(int age){
    if(age < 18){
        return true;
    }
    return false;
}
int main(int argc, char **argv){
    int age;
    string name;
    cout<<"Enter name ";
    cin>>name;
    cout<<"Enter age ";
    cin>>age;
    cout<<"hi "<<name<<", you are "<<age<<" years old"<<endl;


    if(is_adult(age)){
        cout<<"you are eligible for drinking in bar "<<endl;
    }
    else{
        cout<<"please come back in "<<21-age<<" years"<<endl;
    }
}