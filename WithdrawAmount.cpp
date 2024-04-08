#include <iostream>
using namespace std;

class BankAccount 
{
private:
	string accountid ;
	int balance;

public:
	BankAccount() {
		accountid = "PK92430012311";
		balance = 50000;
	}

	string getAcntId() {
		return accountid;
	}

	int getbalance() {
		return balance;
	}

	void balanceInquiry() {
		cout << "Account Id: " << getAcntId()<<"\t"<<getbalance()<<endl;
	}
};

class CurrentAccount:public BankAccount {
private:
	int amount;
public:
	void getinput() {
		cout << "Enter the amount to withdraw from current account : " << endl;
		cin >> amount;
	}

	void withdraw()
	{
		if (getbalance() - amount > 5000) {
			cout << "Remaining balance: " << getbalance() - amount << endl;
		}
		else {
			cout << "Balance is less than 5000 cannot withdraw" << endl;
		}
	}
};

class savingAccount:public BankAccount {
private:
	int amount;
public:
	void getinput() {
		cout << "Enter the amount to withdraw from saving acount: " << endl;
		cin >> amount;
	}

	void withdraw()
	{
		if (getbalance() - amount > 10000) {
			cout << "Remaining balance: " << getbalance() - amount << endl;
		}
		else {
			cout << "Cannot withdraw" << endl;
		}
	}
};

int main() {
	CurrentAccount Cacnt;
	savingAccount Sacnt;

	Cacnt.getAcntId();
	Cacnt.getbalance();
	Cacnt.balanceInquiry();
	Cacnt.getinput();
	Cacnt.withdraw();
	Sacnt.getAcntId();
	Sacnt.getbalance();
	Sacnt.balanceInquiry();
	Sacnt.getinput();
	Sacnt.withdraw();

	return 0;
}
