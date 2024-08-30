// #include<iostream>
// #include<cstdlib>
// #include<time.h>
// using namespace std;
// class guess{
//     public:
    
//      int num;
    
//     void input(){
//          string name;
//          cout<<" enter the name of the player";
//          cin>> name;
//          cout<<endl<<" enter your number";
//          cin>>num;
//     }
//      void run(){
//          srand( time(0));
//      srand(12);
//          int  random=((rand()%2)+1);
//          cout<<random; 
   
//        for( int i=0;i<6;i++){
//           if(num == random){
//           cout<<endl<<"   congratulation you win the game";

         
//         }
//         else if( num>random){
//             cout<<" your number is higher then actual number,guess again";
            
            
//         }
//         else if (num<random){
//              cout<<" your number is lower then actual number,guess again";
//         }

//        }


      
        

//      }
    

// };
//  int main(){

//      guess a;
    
//      a.input();
//      a.run();
//  }

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Guess {
public:
    int num;
  
      
    
    void input() {
        string name;
        cout << "Enter the name of the player: ";
        cin >> name;
        cout << endl << "Enter your number: ";
        cin >> num;
    }
    

    void run() {
        
          srand((time(0))); // Seed the random number generator
        // srand(13);
    int random = ((rand() % 100) + 1); // Generate a random number between 1 and 2
        
        bool guessedCorrectly = false;

        for (int i = 0; i < 5; i++) {
            if (num == random) {
                cout << endl << "Congratulations! You win the game." << endl;
                guessedCorrectly = true;
                break;
            } else if (num > random) {
                cout << "Your number is higher than the actual number. Guess again: ";
            } else {
                cout << "Your number is lower than the actual number. Guess again: ";
            }
            // Take another input for next guess
            cin >> num;
        }
        
        if (!guessedCorrectly) {
            cout << endl << "Sorry, you've used all attempts. The correct number was " << random << "." << endl;
        }
    }
};

int main() {
    Guess a;
    a.input();
    a.run();
    return 0;
}