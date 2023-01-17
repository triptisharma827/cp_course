#include<bits/stdc++.h>
using namespace std;

string grade_my_assignment(int marks){
    switch (marks/10){
    case 9:
        return "A";
        break;
    case 8:
        return "B";
        break;
    case 7:
        return "C";
        break;
    case 6:
        return "D";
        break;
    case 5:  
        return "E";
        break;
    case 4:
        return "F";
        break;
    case 3:
        return "G";
        break;
   
    default:
        return "H";
        break;
    }
    
}

int main(int argc, char **argv){
    int marks=100;

    cout<<grade_my_assignment(marks)<<endl;

    return 0;

}