#include<iostream>
using std::cout;
using std::cin;

/*******************************************
 *This program demosntrate the use of randNum using seed
 *The user is given 3 chances to guess the lucky number
 *
 *
 *******************************************/

void Prompt() {
	cout << "================Console Guessing Game==============" << '\n';
	cout << "	Welcome so a simple Guessing Game" << '\n';
	cout << "You are given 3 chances to Guess the Lucky Number" << '\n';
	cout << "==================Good Luck!!======================" << '\n';
}

int luckyNumGen(){
	srand(time(0)); // seed generate 1 to 100 randomly
	
	return (rand() % 100) + 1;
}

int  main() {
	

	int choice = 0;
	int numOfTries = 3;
	int numOfHints= 2;

	Prompt();

	
	int luckyNum = luckyNumGen();// generate one lucky number
	bool isGuessed = false;
	do{	
		//char ans = '\0';
		//cout << "\nDo you want a hint? Press \"Y\" to proceed otherwise \"N\": ";
		//cin >> ans;
		cout<< "\nInput a number of your choice: ";
		cin >> choice;				
		
	        if(choice == luckyNum) {
                        isGuessed = true;
                        break;
                }else{
                   numOfTries--;
                   cout << "You guessed it Wrong"<< "--> You still have (" << numOfTries << ") number of tries left" << '\n';
                }



		if(numOfTries >=  1 && choice != luckyNum) {
			 char ans = '\0';
                	cout << "\nDo you want a hint? Press \"Y\" to proceed otherwise \"N\": ";
                	cin >> ans;
			switch(ans){
			
				case 'Y':
					if(numOfHints >= 2) {
                                		cout<< "HINT: "  << "The number is " << (luckyNum % 2 == 0 ? "Even" : "Odd") << '\n';
						
					 } else {
						cout<< "HINT: "<< (luckyNum >= 50 ? "The lucky number is greater than 50 " : "The lucky number is less than 50")  << '\n' ;
					 }
			       		numOfHints--;
					cout << "--> Your hints left is (" << numOfHints <<")\n ";	
				break;
				case 'N':
					cout << "->>>>(HAVE FUN GUESSING)<<<<----" <<  '\n';
				break;
				default:
					cout << '\n' << "ERROR: Not a valid input " << '\n';

			}
		}

		
	}while(numOfTries > 0 && numOfTries <= 3);
		
	
	if(isGuessed) {
	   cout << '\n' << "CONGRATULATIONS YOU GUESSED THE LUCKY NUMBER" << '\n';

	}
	

	if(numOfTries == 0 && !isGuessed)  {
	   cout << "\n======================GameOver=============== " << '\n';
	  cout <<  "==============The Lucky Number is " << luckyNum << "========" << '\n'; 
	}
		


}
