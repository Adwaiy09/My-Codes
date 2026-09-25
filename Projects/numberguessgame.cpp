#include <iostream>
#include <random>

int main()
{
    std::random_device rd;                           // seed generator
    std::mt19937 engine(rd());                       // pseudo sequence generator
    std::uniform_int_distribution<int> range(0, 10); // our desired range
    int n;
    int mystery;
    int rightAttempts = 0;
    int wrongAttempts = 0;
    std::cout << "       ============ Number Guessing Game ============\nEnter -1 to EXIT the game.\n";
    std::cout << "You have to guess a number between 0-10\n";
    std::cout << "Guess the number: ";

    while (std::cin >> n && n != -1)
    {

        mystery = range(engine);
        if (n == mystery)
        {
            std::cout << "You guessed it right !!! \nAgain: ";
            rightAttempts++;
        }
        if (n != mystery)
        {
            std::cout << "You guessed it wrong :( \nAgain: ";
            wrongAttempts++;
        }
    }

    std::cout << "Right Attempts: " << rightAttempts << std::endl;
    std::cout << "Wrong Attempts: " << wrongAttempts << std::endl;
    std::cout << "Total Attempts: " << rightAttempts + wrongAttempts;
}