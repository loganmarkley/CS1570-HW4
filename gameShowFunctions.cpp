#include "gameShowFunctions.h"

#include <iostream>
#include <string>
using namespace std;


void greeting()
{
  cout<<endl<<"Welcome to Are you Smarter than a Comp Sci! Ready to play?\n     (please give responses in all lowercase :D)"<<endl<<endl;
  return;
}

void printQuestion(int questionNumber)
{
  if(questionNumber==1)
  {
    cout<<"Question 1: Which of these is the best show of all time?"<<endl;
    cout<<"1 - Breaking Bad\n2 - Game of Thrones\n3 - Attack on Titan\n4 - Avatar: The Last Airbender"<<endl;
  }
  else if(questionNumber==2)
  {
    cout<<"Question 2: Which of these is the best basketball player of all time?"<<endl;
    cout<<"1 - Michael Jordan\n2 - Lebron James\n3 - Wilt Chamberlain\n4 - Kobe Bryant"<<endl;
  }
  else if(questionNumber==3)
  {
    cout<<"Question 3: Which of these is the best movie of all time?"<<endl;
    cout<<"1 - Spider-man: No Way Home\n2 - Avengers: Endgame\n3 - Avengers: Infinity War\n4 - Titanic"<<endl;
  }
  else if(questionNumber==4)
  {
    cout<<"Question 4: Which of these is the best pet of all time?"<<endl;
    cout<<"1 - Cats\n2 - Dogs\n3 - Hamsters\n4 - Fish"<<endl;
  }
  else if(questionNumber==5)
  {
    cout<<"Question 5: What year did Leonardo Dicaprio win an Oscar?"<<endl;
    cout<<"1 - 2021\n2 - 2016\n3 - 2018\n4 - 2015"<<endl;
  }
  else if(questionNumber==6)
  {
    cout<<"Question 6: What was the first fruit eaten on the moon?"<<endl;
    cout<<"1 - Mango\n2 - Orange\n3 - Apple\n4 - Peach"<<endl;
  }
  else if(questionNumber==7)
  {
    cout<<"Question 7: What year was the first car invented?"<<endl;
    cout<<"1 - 1884\n2 - 1875\n3 - 1902\n4 - 1886"<<endl;
  }
  else if(questionNumber==8)
  {
    cout<<"Question 8: Which country is the leader in steel production?"<<endl;
    cout<<"1 - United States\n2 - China\n3 - Russia\n4 - United Kingdom"<<endl;
  }
  else if(questionNumber==9)
  {
    cout<<"Question 9: What was the name of the supercontinent that existed long ago?"<<endl;
    cout<<"1 - Manlea\n2 - Ranthea\n3 - Pangea\n4 - Ganmea"<<endl;
  }
  else
  {
    cout<<"Question 10: What planet is the farthest from Earth?"<<endl;
    cout<<"1 - Neptune\n2 - Jupiter\n3 - Uranus\n4 - Saturn"<<endl;
  }
  cout<<endl;
  return;
}

int getQuestionAnswer(int questionNumber)
{
  int answer=0;
  if(questionNumber==3 || questionNumber==10)
    answer=1;
  else if(questionNumber==2 || questionNumber==4 || questionNumber==5 || questionNumber==8)
    answer=2;
  else if(questionNumber==1 || questionNumber==9)
    answer=3;
  else
    answer=4;
  return answer;
}

bool isValidInput(string userAnswer)
{
  return (userAnswer=="lifeline" || userAnswer=="random" || userAnswer=="leave"); 
}

bool isValidInput(int userAnswer)
{
  return (userAnswer==1 || userAnswer==2 || userAnswer==3 || userAnswer==4);
}

void errorTrap(string & userAnswer, int & userAnswerNumber)
{
  bool validInput=false;
    while(validInput==false) //this entire while loop is for input error trapping
    {
      bool isInt=false;
      if(userAnswer.length()==1)
      {
        if( isdigit(userAnswer.at(0)) )  
        {
          userAnswerNumber=userAnswer.at(0)-48; //the -48 is to convert the ascii value of the character to the actual integer value
          isInt=true;
        }
      }
      if(isInt)
        validInput=isValidInput(userAnswerNumber);
      else
        validInput=isValidInput(userAnswer);
      if(validInput==false)
      {
        cout<<"Invalid input!! Please try again: ";
        cin>>userAnswer;
      }
    } 
  return;
}

bool isCorrect(int questionNumber, int userAnswerNumber)
{
  int answer=getQuestionAnswer(questionNumber);
  return (answer==userAnswerNumber);
}

void lifeLine(int questionNumber)
{
  static int lifeLines = 3;  //this static int will needs to be initiliazed once, and it will go down
  
  if(lifeLines>=1)
  {
    lifeLines--;
    int answer=getQuestionAnswer(questionNumber);
    int random=rand() % 10 + 1;  //generates random int from 1-10
    if(random==10 || random == 9)  //2 out of 10 chance for it to be random
    {
      int returnedAnswer=answer;
      while(returnedAnswer==answer)   //gets random answers until it is not the right answer.
        returnedAnswer=answerRandomly();
      cout<<"Your friend said the answer is "<<returnedAnswer<<". What is your answer? ";
    }
    else
      cout<<"Your friend said the answer is "<<answer<<". What is your answer? ";
  }
  else
    cout<<"You dont have any lifelines left!!! What is your answer? ";
  return;
}

int answerRandomly()
{
  int random=0;
  random=rand() % (4-1+1) +1;    //following the formula rand() % (max - min + 1) + min       1 to 4
  return random;
}

bool leave(bool continueAsking)
{
  if(continueAsking)
    return false;
  else
    return true;
}

void exitMessage(string winLoseOrLeave, int winnings)
{
  if(winLoseOrLeave=="win")
    cout<<"Congratulations! You won $"<<winnings<<"! Thanks for playing!";
  else if(winLoseOrLeave=="lose")
    cout<<"You lost, and walked away with $"<<winnings<<".";
  else if(winnings<0 && winLoseOrLeave=="leave")
    cout<<"You walked out with -$"<<-winnings<<".";
  else
    cout<<"You walked out with $"<<winnings<<".";
  cout<<endl<<endl;
  return;
}
