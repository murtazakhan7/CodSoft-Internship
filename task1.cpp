//TASK 1

// Create a program that generates a random number and asks the
// user to guess it. Provide feedback on whether the guess is too
// high or too low until the user guesses the correct number.
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!\n";
    std::cout << "I have selected a number between 1 and 100. Try to guess it.\n\n";

    do {
        // Get user input
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Check if the guess is too high or too low
        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        }

        attempts++;

    } while (guess != secretNumber);

    // Congratulate the user upon guessing the correct number
    std::cout << "\nCongratulations! You guessed the number in " << attempts << " attempts.\n";

    return 0;
}
