//Dr. Tyson McMillan a Soccer Scoreboard using 
//Object Oriented Programming in C++
//Updates 4-21-2021 - Dr_T, 12-01-2022 :STUDENT: TYPE YOUR NAME
//Dr_T teaching Object Oriented Scoreboard in C++ 

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 


//COLORS
#define RED "\033[31m"
#define ORANGE "\033[33m"
#define YELLOW "\033[93m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define RESET "\x1b[0m" 


class Team 
{
  private:
    string name;
    string coachName;
    string homeCity;
    bool homeStatus; 
    int score;
    int timeOuts;
  public:
      Team() //default constructor 
      {
        name = "DefaultTeamName";
        coachName = "DefaultCoachName";
        homeCity = "DefaultCity";
        homeStatus = false; // false = home, true = away
        score = 0;
        timeOuts = 0;
      }
//SETTERS
      void setTeamName(string tN) { name = tN; }
      void setCoachName(string cN) { coachName = cN; }
      void setHomeCity(string hC) { homeCity = hC; }
      void setHomeStatus(bool hS) { homeStatus = hS; }    
      void setScore(int s) { score = s; }  
      void setTimeOuts(int tO) { timeOuts = tO; }

//GETTERS
      string getName() const { return name; }
      string getCoachName() const { return coachName; }
      string getHomeCity() const { return homeCity; }
      bool getHomeStatus() const { return homeStatus; }  
      int getScore() const { return score; }
      int getTimeOuts() const { return timeOuts; }

};

class Scoreboard
{
  private:
    int down;
    int toGo;
    int quarter;
    int homeScore;
    int awayScore;
    bool possession;
    int sec;
    int min;
    
    Team home;
    Team visitor;

  public: 
    Scoreboard()
    {
    down = 0;
    toGo = 0;
    quarter = 1;
    homeScore = 0;
    awayScore = 0;
    possession = false;
    sec = 0;
    min = 0;

    home = Team();
    visitor = Team(); 
    }  
//SETTERS
    void setDown(int d) { down = d; }
    void setToGo(int tG) { toGo = tG; }
    void setQuarter(int q) { quarter = q; }  
    void setHomeScore(int hS) { homeScore = hS; }
    void setAwayScore(int aS) { awayScore = aS; }  
    void setPossession(bool p) { possession = p; }
    void setSec(int s) { sec = s; }  
    void setMin(int m) { min = m; }

    void setHome (Team hSet) {home = hSet;}
    void setVisitor (Team vSet) {visitor = vSet;}

//GETTERS
    int getDown() const { return down; }
    int getToGo() const { return toGo; }
    int getQuarter() const { return quarter; }
    int getHomeScore() const { return homeScore; }
    int getAwayScore() const { return awayScore; }
    bool getPossession() const { return possession; }
    int getSec() const { return sec; }
    int getMin() const { return min; }

    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }

    void showScorebard()

    {


      cout << home.getName() << "\t\t" << visitor.getName() << endl;
      cout << "\t\t\t" << min << ":" << sec << endl;
      
      

   
      
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t" << visitor.getScore() << endl; 
      cout << score << home.getCoachName() << reset << "\t\t" << visitor.getCoachName() << endl; 
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;

       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }

       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      (void)system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Status" << endl; 
      cout << "D = Update Visting Team Coach" << endl; 
      cout << "E = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
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
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data

  }while(userChoice != "E" && userChoice != "e");

  /* Expand this program; Dr. T Challenges
    1. Expand the program to update the Visting Team's Name and Score
    2. Add color to Enhance the program
    3. Validate all input using the Input_Validation_Extended.h header
    4. Change the Scoreboard Title to something fun.
    5. Upload this to Canvas in the Participation Extra Credit Item 15
  */

  return 0; 
}