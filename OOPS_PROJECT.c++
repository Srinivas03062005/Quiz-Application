// QUIZ APPLICATION
#include <iostream>
#include <cstdlib> // rand(),srand()
#include <ctime>  // time()
#include <unistd.h> // sleep()
using namespace std;
void shuffleQuestions(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int randIndex = rand() % size; // it gives a number in a range 0 - 5
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
}
/*
                                                              TIME 

     The time() function in C is designed to return the current time in
     seconds since (January 1, 1970, 00:00:00 UTC).
     Here's why and how the 0 (or NULL) works:

     1.The argument to the time() function is a pointer to a time_t variable.
     2.If you pass a valid pointer, time() stores the current time in the memory location pointed to by that pointer and also returns the time value.
     3.If you pass NULL (or 0), time() simply returns the current time without storing it anywhere.

     #include <stdio.h>
     #include <time.h>
     int main() 
     {
     time_t current_time;
     current_time = time(NULL);  // Or time(0)
     printf("Current time in seconds: %ld\n", current_time);
     return 0;
     }
     the function only returns the current time in seconds since (January 1, 1970, 00:00:00 UTC).




     #include <stdio.h>
     #include <time.h>
     int main() 
     {
     time_t current_time;
     time(&current_time);  // Pass the address of 'current_time'
     printf("Current time in seconds: %ld\n", current_time);
     return 0;
     }
    the function stores the current time in current_time and also returns the same value.


    ***
    If you don't need to store the time value explicitly in a variable, passing 0 (or NULL) is convenient.
    It tells the function: "Just return the time; I don't need it stored elsewhere."


    ***
    time_t, which is a data type specifically designed to represent time values.


                                                          SLEEP

    sleep(1); pauses the program for 1 second, useful for adding delays in execution
*/
int main()
{
    string questions[] =
        {
            "What is the capital of Telangana?",
            "What is the national song of INDIA?",
            "Who is the Prime Minister of India?",
            "What is the capital of India?",
            "Which city is known as the Silicon Valley of India?",
            "What is the national flower of India?"
        };

    string options[][4] =
        {
            {"Madhyapradesh", "UP", "AP", "Hyderabad"},
            {"Vande Mataram", "Sare Jahan se Accha", "National Anthem", "Chak de India"},
            {"Donald Trump", "Narendra Modi", "Joe Biden", "K.A.Paul"},
            {"New Delhi", "Mumbai", "Chennai", "Kolkata"},
            {"Bangalore", "Hyderabad", "Chennai", "Pune"},
            {"Lotus", "Rose", "Sunflower", "Tulip"}
        };
    int correctAnswers[] = {4, 1, 2, 1, 1, 1};
    int score = 0;
    int userAnswer;
    char playAgain = 'y';
    cout << "Welcome to the Quiz!" << endl;
    cout << "Answer the following questions by entering the option number (1-4)." << endl;
    while (playAgain == 'y' || playAgain == 'Y')
    {
        score = 0;
        int questionOrder[] = {0, 1, 2, 3, 4, 5};
        shuffleQuestions(questionOrder, 6); // Here we are providing array name so it is passed as pass by address
        for (int i = 0; i < 6; i++)
        {
            cout << "\nQuestion " << i + 1 << ": " << questions[questionOrder[i]] << endl;
            for (int j = 0; j < 4; j++)
            {
                cout << j + 1 << ". " << options[questionOrder[i]][j] << endl;
            }
            bool validInput = false;
            int timer = 10;
            while (!validInput && timer > 0)
            {
                cout << "Your answer (1-4): ";
                cin >> userAnswer;
                if (userAnswer >= 1 && userAnswer <= 4)
                {
                    validInput = true;
                }
                else
                {
                    cout << "Invalid input! Please choose a number between 1 and 4." << endl;
                }
                sleep(1);
                if (timer > 0)
                {
                    timer--;
                }
            }
            if (validInput && userAnswer == correctAnswers[questionOrder[i]])
            {
                cout << "Correct!" << endl;
                score++;
            }
            else if (!validInput)
            {
                cout << "Time's up! The correct answer was option " << correctAnswers[questionOrder[i]] << ": "
                     << options[questionOrder[i]][correctAnswers[questionOrder[i]] - 1] << "." << endl;
            }
            else
            {
                cout << "Wrong answer. The correct answer was option " << correctAnswers[questionOrder[i]] << ": "
                     << options[questionOrder[i]][correctAnswers[questionOrder[i]] - 1] << "." << endl;
            }
        }
        cout << "\nQuiz completed!" << endl;
        cout << "Your total score: " << score << " out of 6" << endl;
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    }
    cout << "Thank you for playing the quiz! Goodbye!" << endl;
    return 0;
}