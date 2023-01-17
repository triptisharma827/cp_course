#include<bits/stdc++.h>
using namespace std;
// pass by value 
void laxmi_chit_fund_scheme(int money){
    money = money *2;
}
// pass by addresss 
void laxmi_chit_fund_scheme(int *wallet){
    *wallet = *wallet *2;
}
// pass by reference 
void laxmi_chit_fund_scheme(int &money){
    money = money *2;
}
void atm_balance_scheme(int money){
    cout<<"You have left "<<money<<"rupees"<<endl;
}

int main(int argc, char **argv){
    int money =10;

    // laxmi_chit_fund_scheme(money);
    atm_balance_scheme(money);

    laxmi_chit_fund_scheme(&money);
    atm_balance_scheme(money);

    laxmi_chit_fund_scheme(&money);
    atm_balance_scheme(money);
    return 0;
}