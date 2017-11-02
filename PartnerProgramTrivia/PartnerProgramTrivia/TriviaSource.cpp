/* Author: Stewart Moon
Class: CSC 223-100
Professor: Jeffrey Howard
Due Date: 11/2/2017
Page & Problem #: Page 423, #10
Description: This program will read from a text file that contains 100 questions, and will store
each one of those questions into an array of objects.  Then the program will prompt the user for a guess
for each question and compare it to the answer.
*/

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

class Trivia {
private:
	//Declare variables
	int cashmoney;
	string guess;
	string answer;
	string question;

public:
	//Define Constructors
	//---------------------------------
	//Pre-condition:No parameter passed
	//Post-condition:Returns question
	//Description:This function returns the question
	string getquestion()
	{
		return question;
	}
	//Define member functions
	//---------------------------------
	//Pre-condition:No parameter passed
	//Post-condition:Returns answer
	//Description:This function returns the answer
	string getanswer()
	{
		return answer;
	}

	//Pre-condition:No parameter passed
	//Post-condition:Returns nothing
	//Description:This function sets the question
	void setquestion(string arg)
	{
		question = arg;
	}

	//Pre-condition:Parameter temp answer passed
	//Post-condition:Returns nothing
	//Description:this function sets the answer
	void setanswer(string arg)
	{
		answer = arg;
	}
	//Declare array of Objects
	Trivia::Trivia(int cash, string q, string a) :cashmoney(cash), question(q), answer(a) {}
	Trivia::Trivia() : cashmoney(0), question(""), answer("") {}
};

int main ()
{
	//Declare variables
	int total=0;
	string tempguess;
	string tempanswer;
	Trivia objects[100];
	string tempquestion;


	//Open input Stream
	ifstream fin;
	fin.open("Questions.txt");

	//Read the text file lines into the Array objects
	for (int i = 0; i <= 99; i++)
	{
		//Read line and store into variable until ifstream reads '?'
		getline(fin, tempquestion, '?');
		objects[i].setquestion(tempquestion);

		//Readl line and store variable until end of line
		getline(fin, tempanswer);		
		objects[i].setanswer(tempanswer);
	}
	//Create randomn  number between 0 and 99
	srand(time(NULL));

	cout << "Below is 10 questions randomnly selected between a listof 0 and 100.";
	cout << endl;
	cout << endl;
	for (int j = 0; j <= 9; j++)
	{
		int random = rand() % 100;

		//Output question from temp variable
		cout << objects[random].getquestion()<<"?";
		cout << endl;
		
		//Store user input into temp variable
		cin >> tempguess;

		if (tempguess == objects[random].getanswer())
			{
			//Create cash
			int cash = rand() % 200;
			cout << "You won: " << cash<<"$";
			total += cash;
			cout << endl;

			//Output congratulation
			cout << "Correct!!!";
			cout << endl;
			}
		else if(tempguess!= objects[random].getanswer())
		{
			cout << "Incorect!!!";
			cout << endl;
		}
	}
	//Output friendly goodbye
	cout << "Congratulations, you won: " << total<<"$";
	cout << endl;

return 0;
}


