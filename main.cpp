#include <iostream>
#include<conio.h> //to include getch function (hold the screen untill user press any key)
#include<string>
using namespace std;

/*Mini project- ATM
    -Check balance
    -Cash withdraw
    -User details
    -Update Mobile No.  */


 class atm_machine{
 private:
     long int accountNo;
     string accHolderName;
     int pin;
     double accBalance;
     string mobileNo;

 public:
     //This function set data into the private variables
     void setdata(long int accountNo_1,string accHolderName_1, int pin_1, double accBalance_1, string mobileNo_1){
     accountNo=accountNo_1;
     accHolderName=accHolderName_1;
     pin=pin_1;
     accBalance=accBalance_1;
     mobileNo=mobileNo_1;
     }

 //This function is used to get the account no
 long int getAccountNo(){
 return accountNo;
 }

 //This function is used to get account holder's name
 string getAccHolderName(){
 return accHolderName;
 }

 //This function is used to get the pin of the account no
 int getPin(){
 return pin;
 }

 //This function is used to get the account balance
 double getACCBalance(){
 return accBalance;
 }

 //This function is used to return mobile number of the account holder
 string getMobileNo(){
 return mobileNo;
 }

 //This function is used to update the existing mobile no
 void updateMobileNo(string prevMobNo, string newMobNo){
 if(mobileNo==prevMobNo){
    mobileNo=newMobNo;
    cout<<"Mobile Number SucessfullY Updated."<<endl;
    _getch();
 }
 else {
    cout<<"Existing Mobile Number is Incorrect."<<endl;
    _getch();
 }
 }

 //This function is used to withdraw money from ATM
 void cashWithdraw(int withdrawAmount){
 if (accBalance>=withdrawAmount && accBalance>0){
    accBalance=accBalance-withdrawAmount;
    cout<<"Transaction Completed. Please Collect your Cash!"<<endl;
    cout<<"Your Available Balance is = "<<accBalance<<endl;
    _getch();
 }
 else {
    cout<<"Invalid Input or Insufficient balance."<<endl;
    _getch();
 }
  }

 };

int main()
{
    int choice=0;
    int enterPin;
    long int enterAccNO;

    system("cls"); //function to clear the screen

    atm_machine user1; //creating object

    user1.setdata(123456,"Chamantha",1111,50000.50,"0770000000");

    do{
        system("cls");
        cout<<" ********** Wecome to ATM ********** "<<endl;
        cout<<endl;
        cout<<"Enter your Account Number :  ";
        cin>>enterAccNO;
        cout<<endl;
        cout<<"Enter Your Pin : "<<endl;
        cin>>enterPin;
        cout<<endl;

        //Check validity of Entered Values
        if ((enterAccNO==user1.getAccountNo())&&(enterPin==user1.getPin())){

             do{
                system("cls");
                int amount;
                string newNo, oldNo;
                //User Interface
                cout<<" ********** Welcome to ATM ********** "<<endl;
                cout<<" Select Option... "<<endl;
                cout<<" 1. Check Balance"<<endl;
                cout<<" 2. Cash Withdraw"<<endl;
                cout<<" 3. Show User Details"<<endl;
                cout<<" 4. Update Mobile Number"<<endl;
                cout<<" 5. Exit"<<endl;

                cin>>choice;

                switch(choice){

            case 1:
                cout<<"Your Account Balance is : "<<user1.getACCBalance()<<endl;
                _getch();
                break;

            case 2:
                 cout<<"Enter the amount : ";
                 cin>>amount;
                 cout<<endl;
                 user1.cashWithdraw(amount);

            case 3:
                cout<<" ******** User Details ******** "<<endl;
                cout<<" Account No : " <<user1.getAccountNo()<<endl;
                cout<<" Account Holder's Name : " <<user1.getAccHolderName()<<endl;
                cout<<" Account Balance : " <<user1.getACCBalance()<<endl;
                cout<<" Account Holders TP : " <<user1.getMobileNo()<<endl;
                _getch();
                break;

            case 4:
                cout<<"Enter your Old Mobile No : " ;
                cin>>oldNo;
                cout<<endl;
                cout<<"Enter your New Mobile No : " ;
                cin>>newNo;
                cout<<endl;
                user1.updateMobileNo(oldNo,newNo);
                break;

            case 5:
                exit(0);

            default:
                cout<<" Enter Valid Data !";
                }



             }while(1);
        }


    }
while(1); //Due to this condition this will always true and run the function again and again
    return 0;
}
