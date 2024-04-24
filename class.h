#include <iostream>

#ifndef CLASS_H
#define CLASS_H

#include <string>
using namespace std;

/*attempts at making the timer work
void Scoreboard::incrementTime() {
    sec++; // Increment seconds
    if (sec >= 60) {
        sec = 0;
        min++; // Increment minutes and handle rollover
    }
}

void clockFunction(Scoreboard &s) {
    while (true) {
        // Update the clock every second
        this_thread::sleep_for(chrono::seconds(1));
        // Increment seconds and handle minute rollover
        s.incrementTime();
    }
}
*/

//COLORS
#define RED "\033[31m"
#define LIGHTRED "\033[91m" 
#define BLUE "\033[34m"
#define LIGHTBLUE "\033[94m"
#define RESET "\x1b[0m" 
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define WHITEBACKGROUND "\x1b[47m"
#define ITALIC "\x1b[3m"
#define BLACK "\033[30m"

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
        name = "Default Team Name";
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

  //  Team home;
 //   Team visitor;

  public:
void incrementTime();
Team home;
Team visitor;

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

    void showScoreboard()

{


  cout << BOLD << RED <<UNDERLINE << home.getName() <<RESET << "\t\t\t" <<BOLD << BLUE << UNDERLINE << visitor.getName() << RESET << endl;
  cout << "\t" << LIGHTRED << ITALIC << home.getHomeCity() << RESET << "\t\t"<< ITALIC<<BOLD << BLACK << WHITEBACKGROUND << min << ":" << sec  << RESET << "\t\t" << LIGHTBLUE<< visitor.getHomeCity() <<  endl;
  cout << "\t\t" << BOLD << LIGHTRED<< home.getScore() << "\t\t\t\t\t\t" << LIGHTBLUE << visitor.getScore() << RESET << endl;
  cout << "\t\t\t\t" << RED << (getPossession()  ? "*" : "0") << "  " << RESET<< BOLD <<"QTR " << getQuarter() << "  " << BLUE << (getPossession() ? "0" : "*") << RESET << endl;

  cout << "\t " << BLACK << down << " DOWN"<< "\t\t\t\t\t" << "TOGO " << toGo << endl;  
  cout <<LIGHTRED << "\t\tTO " << home.getTimeOuts() << "\t\t\t\t\t" << LIGHTBLUE<< "TO " << visitor.getTimeOuts() << RESET << endl;
  cout << LIGHTRED << ITALIC << "Coach:" << home.getCoachName() << "\t\t\t" << LIGHTBLUE<< "Coach:" << visitor.getCoachName()<< RESET << endl;









  for(int i = 0; i < 47; i++) { cout << "-"; } cout << endl;

   //proces to show the home team status
   cout <<BOLD << "HOME TEAM STATUS-->  " << RESET; 
   if(home.getHomeStatus() == true)
   {
     cout << RED << "RED: " << home.getName() << "*"; 
   }
   else if(visitor.getHomeStatus() == true)
   {
     cout <<BLUE << "BLUE: " << visitor.getName() << "*"; 
   }
   else
   {
     cout << "Error: "; 
   }

   cout  << RESET <<endl; 
}
};

#endif