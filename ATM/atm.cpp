#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

/* Mini Project - ATM
  -> Check balance
  -> Cash withdraw
  -> User details
  -> Update Mobile No.
*/

class atm {
    private:                            //private member variables.
        long int accountNum;
        string userName;
        int PIN;
        double balance;
        string mobNum;
    
    public:                            //public members functions.
        void setData(long int accountNumA, string userNameA, int pin, double balanceA, string mobNumA) {
            accountNum = accountNumA;
            userName = userNameA;
            PIN = pin;
            balance = balanceA;
            mobNum = mobNumA;
        }
        long int getAccountNum() {
            return accountNum;
        }
        string getUserName() {
            return userName;
        }
        int getPIN() {
            return PIN;
        }
        double getBalance() {
            return balance;
        }
        string getMobNum() {
            return mobNum;
        }
        void setMobNum(string prevNum, string newNum) {
            if(prevNum == mobNum){
                mobNum = newNum;
                cout << endl << "Mobile Number Updated Successfully";
                _getch();
            } else {
                cout << endl << "Invalid Credentials";
                _getch();
            }
        }
        void cashWithdraw(int amountA) {
            if(amountA > 0 && amountA < balance){
                balance -= amountA;
                cout << endl << "Please Collect Your Cash";
                cout << endl << "Available Balance: " << balance;
                _getch();
            } else {
                cout << endl << "Invalid Credentials OR Insufficient Balance";
                _getch();
            }
        }
};

int main() {
    int choice = 0, enterPIN = 0;
    long int enterAccountNum = 0;
    //system("cls");  //Automatically clear the screen.

    //creating instance of the class.
    atm user1;
    user1.setData(123456, "Archana", 111, 45678.89, "9999911111");
    do {
        system("cls");
        cout << endl << "*********** Welcome to Virtual ATM *************" << endl;
        cout << endl << "Enter Your Account Number: "; 
        cin >> enterAccountNum;

        cout << endl << "Enter PIN: ";
        cin >> enterPIN;

       if((enterAccountNum == user1.getAccountNum()) && (enterPIN == user1.getPIN())){
            do {                                //User Interface of the ATM
                int amount = 0, choice = 0;
                string oldMob, newMob;
               // system("cls");

                cout << endl << "********* Welcome to Virtual ATM *********" << endl;
                cout << endl << "Select an option: ";
                cout << endl << "1. Check Balance: ";
                cout << endl << "2. Cash Withdrawal";
                cout << endl << "3. Show User Details";
                cout << endl << "4. Update Mobile Number";
                cout << endl << "5. Exit";
                cout << "\n\n";
                cin >> choice;

                switch(choice) {
                    case 1:
                        cout << endl << "Your Bank balance is: " << user1.getBalance();
                        _getch();
                        break;

                    case 2:
                        cout << endl << "Enter the amount: ";
                        cin >> amount;
                        user1.cashWithdraw(amount);
                        break;

                    case 3:
                        cout << endl << "************* User Details are: **************";
                        cout << endl << "-> Account Number: " << user1.getAccountNum();
                        cout << endl << "-> Name: " << user1.getUserName();
                        cout << endl << "-> Balance: " << user1.getBalance();
                        cout << endl << "-> Mobile Number: " << user1.getMobNum();
                        _getch();
                        break;

                    case 4:
                        cout << endl << "Enter Old Mobile Number: ";
                        cin >> oldMob;
                        cout << endl << "Enter New Mobile Number: ";
                        cin >> newMob;

                        user1.setMobNum(oldMob, newMob);
                        break;
                    
                    case 5:
                        exit(0);

                    default: 
                        cout << endl << "Enter a Valid Option";
                }
            } while(1);
        }
    } while(1);

    return 0;
}