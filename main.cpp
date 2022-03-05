//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 2/28/22
//File: main.cpp
//Purpose: make "are you smarter than a comp sci" guessing game in C++ (HW 4)

#include <iostream>
#include <string>
#include "gameShowFunctions.h"

using namespace std;

int main()
{
  srand (11);   //set to 11 for grading purposes
  bool continueAsking=true;   //this boolean is turned to false when the game ends, when the user leaves, or when the user loses
  int money=100;
  int livesLeft=3;  
  int questionNum=1;
  string userInput="";  
  int userInputNumber=0; //when userInput contains an integer(1,2,3,4), this variable will be changed to said integer
  string winLoseOrLeave="";
  
  greeting();
  while( continueAsking )
  {
    userInputNumber=0;
    bool questionAnswered=false;
    printQuestion(questionNum);
    while(questionAnswered==false)
    {
      cin>>userInput;
      errorTrap(userInput,userInputNumber);
      if(userInput=="lifeline")
        lifeLine(questionNum);
      else if(userInput=="random")
        cout<<"You thought of the number "<<answerRandomly()<<". What is your answer? ";
      else if(userInput=="leave")
      {
        continueAsking=leave(continueAsking);
        winLoseOrLeave="leave";
        questionAnswered=true;
      }
      else
        questionAnswered=true;
    }
    
    if( isCorrect(questionNum, userInputNumber) && continueAsking==true)
      cout<<"Correct!"<<endl<<endl;
    else if(continueAsking==true)
    {
      livesLeft--;
      if(livesLeft==1)
        cout<<"Incorrect! You have "<<livesLeft<<" life remaining."<<endl<<endl;
      else
        cout<<"Incorrect! You have "<<livesLeft<<" lives remaining."<<endl<<endl;
    }
    if(continueAsking==true)
      money=updateMoney(money, isCorrect(questionNum, userInputNumber));
    questionNum++;     
    if(livesLeft==0)         //if you run out of lives
    {
      continueAsking=false;
      winLoseOrLeave="lose";
      money=0;  //if you lose, you automatically get $0
    }
    else if(questionNum>10)       //if you answer all the questions without losing 3 lives
    {
      continueAsking=false;
      winLoseOrLeave="win";
    }
  }
  exitMessage(winLoseOrLeave, money);
  return 0;
}
