// mathTrivia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>// For standard I/O functions
#include <cmath>  
using namespace std;

void Trivia(int diff) { //trivia game function with an argument for difficulty
    int score = 0; // initialize score to 0

    double answer; // initialize answer variable

    char op; // initialize operator variable
    double r; // initialize randome number 1
    double r2;// initialize randome number 2
    char ops[4] = { '+','-','/','*' }; // create an array for operators
    srand(time(0)); //seeds the random num generator to change up my nums every excecution

    cout << "Starting level " << diff << " game \n"; // state game level to user


    for (int i = 0; i < 5; i++) { // a for loop that runs 5 times to give 5 game questions
        if (diff == 1) { // if in difficulty one
            op = ops[rand() % 2]; // choose a random index between 0 and 1 (+ or - operators)
            r = rand() % 10 + 1; // random number from 1 to 10
            r2 = rand() % 10 + 1; //  another random number from 1 to 10
        }
        else if (diff == 2) { // if level 2
            op = ops[rand() % 4];// choose a random index between 0 and 3 ( all operators)
            r = rand() % 100 + 1; // random number from 1-100
            r2 = rand() % 100 + 1; // random number from 1-100
        }
        else if (diff == 3) { //if level 3
            op = ops[rand() % 4]; // choose a random index between 0 and 3 ( all operators)
            r = rand() % 1000 + 1;// random from 1-1000
            r2 = rand() % 1000 + 1;// random from 1-1000
        }
        else {
            cout << "Invalid difficulty"; // level not found
            break; // end the loop
        }

        double userIn;
        cout << "Question " << r << op << r2 << ": "; // prompt user 
        cin >> userIn; //store user input

        switch (op) { // switch between the operators
            case '+': // if character is  +
                answer = r + r2; // find the answer
                break; // end switch

            case '-': // if  - 
                answer = r - r2; // find answer
                break; // end switch


            case '*': // if  *
                answer = r * r2; // get answer
                break; // end the switch
            case '/': // if /
                answer = r / r2; // find the answer
                answer = ceil(answer * 100) /100; // get the answer to 2 decimal points
                break; // end the switch
            default: // shouldnt get here
                cout << "?"; // print ? if we do

        }

        if (userIn == answer) { // if user input matches answer
            cout << "Correct\n"; // print correct
            score += 1; // increase score
        }
        else if (userIn != answer) { // if incorrect
            cout << "Incorrect, the answer was " << answer << "\n"; //print incorrect and the correct answer
        }



    }

    cout << "GAME OVER: Your score is " << score; // print the final score
}

int main()
{
    int diff; // initalize difficulty variable
    cout << "Welcome to the math quiz game! Choose your difficulty 1 2 or 3: "; // prompt the user
    cin >> diff; // store the user input into diff
    Trivia(diff); // run the trivia function with the given difficulty parameter


}

