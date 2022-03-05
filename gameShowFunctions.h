#ifndef GAMESHOWFUNCTIONS_H
#define GAMESHOWFUNCTIONS_H

#include <iostream> 
using namespace std; 

#include "gameShowTemplateFuncs.hpp"

//description: simply prints out a greeting message to the user
//pre: none
//post: greeting message is successfully outputted
void greeting();

//description: prints out the question and choices depending on which question number is inputted
//pre: questionNumber must be an int between 1 and 10 inclusive in order to display a possible question
//     (if outside of this range, question 10 will be displayed)
//post: the corresponding question and choices are succesfully displayed to the user
void printQuestion(int questionNumber);

//description: simply returns the correct answer choice based on what question number is inputted
//pre: questionNumber must be an int between 1 and 10 inclusive in order to correlate to a possible question
//     (if outside of this range, the answer choice of 4 will be returned)
//post: the correct choice (1,2,3 or 4) is returned based on the passed parameter
int getQuestionAnswer(int questionNumber);

//description: returns true if the parameter contains "lifeline", "random", or "leave"
//pre: userAnswer must be a string
//post: returns false if the parameter does not contain the EXACT above phrases ^^^
bool isValidInput(string userAnswer);

//description: returns true if the parameter contains 1,2,3, or 4
//pre: userAnswer must be an int
//post: returns false if the parameter does not contain the EXACT above ints ^^^
bool isValidInput(int userAnswer);

//description: use the two isValidInput() functions to keep the user in a loop until they make a valid input choice
//pre: userAnswer must be a string, userAnswerNumber must be an int
//post: after the end of this function, userAnswer will be either "lifeline", "random", or "leave". 
//      OR if userAnswer is 1,2,3, or 4, then userAnswerNumber will also be changed to said int using pass by reference
void errorTrap(string & userAnswer, int & userAnswerNumber);

//description: using getQuestionAnswer(), checks to see if userAnswerNumber is the correct answer choice based on the questionNumber
//pre: questionNumber must be an int [1,10], userAnswerNumber must also be an int
//post: true is returned if the userAnswerNumber correctly matches that questionNumber's answer
bool isCorrect(int questionNumber, int userAnswerNumber);

//description: if the user has at least 1 lifeline, there is an 80% chance that the correct answer will be displayed to the user based on questionNumber.
//             There is a 20% chance that a randomly selected choice from the other 3 will be displayed.
//pre: questionNumber must be an int, the static int lifeline must be 3,2, or 1 to succesfully display a lifeline
//post: a lifeline is successfully called and displayed to the user if they have lifelines
void lifeLine(int questionNumber);

//description: very simple function that returns a random int [1,4]
//pre: none
//post: successfully returns a random int [1,4]
int answerRandomly();

//description: when called, it will return true or false based only on the value of continueAsking 
//pre: continueAsking must be a bool
//post: false is returned if continueAsking is true, true is returned otherwise
bool leave(bool continueAsking);

//description: displays a final message to the user before the program terminates. The message changes based on winLoseOrLeave.
//             Their winnings are also displayed using the winnings parameter
//pre: winLoseOrLeave must be a string, specifically "win", "lose", or "leave". if it is not one of those, the simple leave message will be displayed winnings must be an int.
//post: successful final message is displayed to the user based on if they won, lost, or chose to leave
void exitMessage(string winLoseOrLeave, int winnings);

//description: changes currentMoney based on if isCorrect is true or false
//pre: currentMoney must be some numerical variable, isCorrect must be a bool
//post: double the value of currentMoney is returned if isCorrect is true, (currentMoney-100) is returned otherwise
template <typename T>
T updateMoney(T currentMoney, bool isCorrect);

#endif
