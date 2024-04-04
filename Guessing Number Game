#include <iostream>
#include <ctime>
using namespace std;

class game {
private:
	int secretno;
	int attemptsleft;
public:
	void generateranddno()
	{
		secretno = rand() % 100 + 1;
		attemptsleft = 5;
	}

	int play() {
		int guess;
		char x;
		do
		{
		cout << "Welcome To Guessing Game" << endl;
		cout << "Enter the secret number (0-100)" << endl;
		cin >> guess;
		attemptsleft--;

		if (guess==secretno) {
			cout << "Congratulations You Won" << endl;
			cout << "Attempts Left " << attemptsleft << endl;
			return 1;
		}

		else if(guess > secretno) {
			cout << "Exceded The Secret No" << endl;
			cout << "Attempts Left " << attemptsleft << endl;
		}

		else if (guess < secretno) {
			cout << "Less Than the secret number " << endl;
			cout << "Attempts Left " << attemptsleft << endl;
		}
		} while (attemptsleft>0);
		cout << "You ran out of attempts " << endl;
		cout << "Secret Number :" << secretno << endl;
	}
};

int main() {
	srand(time(0));
	game start;
	start.generateranddno();
	start.play();

	return 0;
}
