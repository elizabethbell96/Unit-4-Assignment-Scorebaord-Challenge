//LIZ BELL
//04-20-2024
//A Football Scoreboard using Object Oriented Programming in C++\
//see class.h for my attempts at making the timer work 


#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
#include "class.h"
#include <thread>
#include <chrono>
using namespace std; 

int main() 
{
  Team tOne; // Create first team object
  tOne.setTeamName("Dallas Cowboys");
  tOne.setHomeStatus(true); // Set as home team 
 

  Team tTwo; // Create second team object
  tTwo.setTeamName("Green Tea Giants");


  
 /*  Here is where I tried to make the team members of a scoreboard class.
 Scoreboard s1;
  s1.home.setTeamName("Team 1");
  s1.visitor.setTeamName("Team 2"); */
  
  Scoreboard s;
  //Team tOne;
 // Team tTwo;
  string newTeamName = "";
  string newTeamCity = "";
  int newScore = 0;
  int newDown = 0;
 int newToGo = 0;
 // bool newPossession = false;
  int newTimeOuts = 0;
  int newQuarter = 0;
  string newCoachName = "";
  //bool newTeamHomeStatus = false;
  int newMin = 0;
  int newSec = 0;
  
  char userChoice = '\0';

  int homeTeamQuestion = 0;
  int possessionQuestion = 0;
  
 // thread clockThread(clockFunction, ref(s));
 
  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      (void)system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 

    cout<<BOLD << "\n"<< "1 = Update the Home Team status" << "\n"<<  endl;

    cout << BOLD << BLACK << "GAME UPDATES" << RESET<< endl;
    cout << BLACK << "2 = Update the time" << endl;
    cout << "3 = Update the quarter" << endl;
    cout << "4 = Update possession (* means in possesion, 0 mean not)" << endl;
    cout<< "5 = Update Down" << endl;
    cout << "6 = Update Yards to Go" << endl;
    
    cout <<BOLD << RED<< "\n" << "HOME TEAM UPDATES" << RESET<< endl;    
      cout << LIGHTRED<< "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team City" << endl;
      cout << "C = Update Home Team Coach" << endl;
      cout << "D = Update Home Team Score" << endl;
      cout << "E = Update Home Team Timeouts" << RESET << endl;

    
    cout <<BOLD << BLUE<<"\n" << "VISITOR TEAM UPDATES" << RESET << endl;
      cout << LIGHTBLUE << "F = Update Visitor Team Name" << endl;
      cout << "G = Update Visitor Team City" << endl;
      cout << "H = Update Visitor Team Score" << endl;
      cout << "I = Update Visitor Team Coach" << endl;
      cout << "J = Update Visitor Team Timeouts" << RESET<< endl;
    
cout << BOLD << "\n Choice: " << RESET ;
    

    
      cin >> userChoice; 
     if(userChoice == '1')
    {
      cout << BOLD <<"\n****Update Home Status Module****" << RESET <<endl; 
      cout << "\nWho is the home team? (" << RED<< "1: RED,"<<BLUE << " 2: BLUE"<<RESET<< ")  " << endl; 
      homeTeamQuestion = validateInt(homeTeamQuestion); 
 //    cin >> homeTeamQuestion; 
      if(homeTeamQuestion == 1)
      {
        tOne.setHomeStatus(true); 
        tTwo.setHomeStatus(false); 
      }
      else if(homeTeamQuestion == 2)
      {
        tOne.setHomeStatus(false); 
        tTwo.setHomeStatus(true);
      }
      else
      {
        cout << "\nInvalid Input!" << endl;
        sleep(2); 
      }
    }
       else if (userChoice == '2')
       {
         cout << BLACK <<"\n****Update Time Module****" << endl;
         cout << "\nHow any minutes are left in the game? " << RESET<< endl;
         newMin = validateInt(newMin);
         s.setMin(newMin);
         
         cout << BLACK "\nHow Many secods are left in the game? " << RESET << endl;
         newSec =validateInt(newSec);
         s.setSec(newSec);
         
       }
      else if (userChoice == '3')
      {
        cout << BLACK<< "\n****Update Quarter Module****" << endl;
        cout << "\nWhat quarter is it? "<< RESET << endl;
        newQuarter = validateInt(newQuarter);
        s.setQuarter(newQuarter);
      }
      else if (userChoice == '4')
      {
          cout << BLACK "\n****Update Possession Module****" << endl;
          cout << "\nWho has the ball? (" << RED << "1 = RED," <<BLUE<<" 2 = BLUE "<< BLACK<< ") "<< RESET<< endl;;

          possessionQuestion = validateInt(possessionQuestion);

          if (possessionQuestion == 1)
          {
              s.setPossession(true);
          }
          else if (possessionQuestion == 2)
          {
              s.setPossession(false);
          }
          else
          {
              cout << "\nInvalid Input!" << endl;
              sleep(2);
          }
      }

              // Update the possession for both teams in the Scoreboard object
    else if (userChoice == 'A' || userChoice == 'a')
    {
      cout <<RED<< "****Update Home Team Name module*** " << endl; 
      cout << LIGHTRED << "\nWhat is the name of the home team? " << RESET<< endl;
      cin >> newTeamName; 

      // Store the current home team name for comparison
      string oldHomeTeamName = tOne.getName();

      // Change the home team's name
      tOne.setTeamName(newTeamName);

      // Check if the home team's name has changed and update the scoreboard if it's the home team
      if (tOne.getName() != oldHomeTeamName && tOne.getHomeStatus()) {
        s.getHome().setTeamName(tOne.getName());
      }
    
      }
      else if(userChoice == 'B' || userChoice == 'b')
      {
        cout << RED << "\n****Update Home Team City Module****" << endl; 
        cout << LIGHTRED << "\nWhat city is the home team from? "<< RESET << endl;
        newTeamCity = validateString(newTeamCity);
        tOne.setHomeCity(newTeamCity);  //set the new score for tOne        
      }
      
        else if (userChoice == 'C' || userChoice == 'c')
        {
        cout <<RED << "\n**** Update Home Team Coach Module ****" << endl;
        cout << LIGHTRED << "Who is the home team's coach?  "<< RESET<< endl;
        newCoachName = validateString(newCoachName);
        tOne.setCoachName(newCoachName);
        }
        
      else if(userChoice == 'D' || userChoice == 'd')
      {
          cout << RED<< "\n**** Update Home Team Score Module ****" << endl; 
          cout <<  LIGHTRED<< "\nWhat is the home team's score?  " << RESET<<  endl; 
          newScore = validateInt(newScore); 
          tOne.setScore(newScore); 
      }
        else if (userChoice == 'E' || userChoice == 'e')
        {
          cout <<RED<< "\n**** Update Home Team Time Outs Module ****" << endl;
          cout << LIGHTRED "\nHow many time outs has the home team used? "<< RESET<< endl;
          newTimeOuts = validateInt(newTimeOuts);
          tOne.setTimeOuts(newTimeOuts);
        }
          else if (userChoice == 'F' || userChoice == 'f')
          {
            cout << BLUE << "\n**** Update Visitor Team Name Module ****" << endl;
            cout << LIGHTBLUE<<  "\nWhat is the name of the visitor team? "<< RESET << endl;
            newTeamName = validateString(newTeamName);
            tTwo.setTeamName(newTeamName);
          }
          else if (userChoice == 'G' || userChoice == 'g')
          {
            cout << BLUE <<"\n**** Update Visitor Team City Module ****" << endl;
            cout << LIGHTBLUE<<  "\nWhere is the visitor team from? "<< RESET << endl; 
            newTeamCity = validateString(newTeamCity);
            tTwo.setHomeCity(newTeamCity);
        
          }
          else if (userChoice == 'H' || userChoice == 'h')
          {
            cout << BLUE << "\n**** Update Visitor Team Score Module ****" << endl;
            cout << LIGHTBLUE<<  "\nWhat is the visistor team's score? "<< RESET << endl;
            newScore = validateInt(newScore);
            tTwo.setScore(newScore);
            
          }
         else if (userChoice == 'I' || userChoice == 'i')
         {
           cout << BLUE << "\n**** Update Visitor Team Coach Module ****" << endl;
           cout << LIGHTBLUE<<  "\nWho coaches the visitor team? "<< RESET <<endl;
           newCoachName = validateString(newCoachName);
           tTwo.setCoachName(newCoachName);
         }
    else if (userChoice == 'J' || userChoice == 'j')
    {
      cout << BLUE<< "\n**** Update Visitor Team Time Outs Module ****" << endl;
      cout << LIGHTBLUE<< "\nHow many time outs has the visitor team used?  " << RESET << endl;
      newTimeOuts = validateInt(newTimeOuts);
      tTwo.setTimeOuts(newTimeOuts);
    }

    else if ( userChoice == '5')
    {
      cout <<BLACK<< "\n**** Update Down Module ****" << endl;
      cout << "\nWhat is the current down? "<< RESET <<endl;
      newDown = validateInt(newDown);
      s.setDown(newDown);
    }
    else if ( userChoice == '6')
    {
      cout <<BLACK << "\n**** Update Yards to Go Module ****" << endl;
      cout << "\nHow many yards untill the next 1st down? "<< RESET << endl;
      newToGo = validateInt(newToGo);
      s.setToGo(newToGo);
      
    }
    
    s.setHome(tOne); //refresh the data in s to the new updates...
    s.setVisitor(tTwo); //refresh the data in s to the new updates...
    cout << "\033[2J\033[1;1H"; //clear screen
    
  }while(userChoice != 'X' && userChoice != 'x');


 
  return 0; 
}