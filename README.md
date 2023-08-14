#include <iostream>
#include <chrono>
#include <thread>

// ... Define necessary structures and data ...

void displayMenu() {
    std::cout << "==============================\n";
    std::cout << "       CHOOSE PROGRAM\n";
    std::cout << "==============================\n";
    std::cout << "1. Calculator\n";
    std::cout << "2. Unit Converter\n";
    std::cout << "3. Library System\n";
    std::cout << "4. Student Management System\n";
    std::cout << "5. Quadratic Equation Solver\n";
    std::cout << "6. Hospital Management System\n";
    std::cout << "7. Movie Ticket and Food Management System\n";
    std::cout << "8. Learn C Language\n";
    std::cout << "9. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Enter your choice: ";
}

void animateLoading(int durationMs) {
    // ... Implement animation logic ...
}

void displayCode(const std::string& code) {
    // ... Implement code display ...
}

void getInput(std::string& input) {
    std::cout << ">> ";
    std::getline(std::cin, input);
}

// ... Implement functions for each program option ...

int main() {
    const int durationMs = 3000;

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 9) {
            std::cout << "Exiting program...\n";
            break;
        }

        // ... Implement option handling ...

        std::string loadingString = "Loading...";
        animateLoading(durationMs);

        // ... Display code with animation ...

        std::string input;
        getInput(input);

        // ... Process input and display output ...

        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cout << std::endl;
    }

    std::cout << "Thanks for using the program!\n";

    return 0;
}
