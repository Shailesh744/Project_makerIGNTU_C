#include<bits/stdc++.h>
// #include <iostream>
// #include <cstring>
// #include <chrono>
// #include <thread>

void animateRotation(int durationMs) {
    const int numOfFrames = 4;
    const std::string frames[numOfFrames] = { "|", "/", "-", "\\" };

    int frameIndex = 0;
    auto startTime = std::chrono::system_clock::now();

    while (true) {
        auto currentTime = std::chrono::system_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

        if (elapsedTime > durationMs)
            break;

        std::cout << "\r" << frames[frameIndex] << " Loading...";
        std::cout.flush();

        frameIndex = (frameIndex + 1) % numOfFrames;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "\r" << std::string(frames[numOfFrames - 1].length() + 11, ' ') << "\r"; // Clear the line
    std::cout << "Loading complete!" << std::endl;
}

void displayTemplate(const std::string& templateString) {
    std::cout << templateString << std::endl;
}

void getInput(std::string& input) {
    std::cout << ">> ";
    std::getline(std::cin, input);
}

int main() {
    const int durationMs = 3000; // Duration of rotation animation in milliseconds

    while (true) {
        std::string templateString =
            "==============================\n"
            "       CHOOSE PROGRAM     \n"
            "==============================\n"
            "1. Calculator\n"
            "2. Unit Converter\n"
            "3. Library System\n"
            "4. Student Management System\n"
            "5. Quadratic Equation Solver\n"
            "6. Hospital Management System\n"
            "7. Movie ticket and food management system\n"
            "8. Learn C language\n"
            "9. Exit\n"
            "==============================\n"
            "Enter your choice: ";

        displayTemplate(templateString);

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 9) {
            std::cout << "Exiting program..." << std::endl;
            break;
        }

        std::string code;
        std::string input;

        switch (choice) {
            case 1:
                code = "/* #include <iostream>\nint main() {\nchar oper;\ndouble num1, num2;\nstd::cout << \"Enter an operator (+, -, , /): \";\nstd::cin >> oper;\nstd::cout << \"Enter two numbers: \";\nstd::cin >> num1 >> num2;\nswitch (oper) {\ncase '+':\nstd::cout << num1 << \" + \" << num2 << \" = \" << num1 + num2 << '\\n';\nbreak;\ncase '-':\nstd::cout << num1 << \" - \" << num2 << \" = \" << num1 - num2 << '\\n';\nbreak;\ncase '':\nstd::cout << num1 << \" * \" << num2 << \" = \" << num1 * num2 << '\\n';\nbreak;\ncase '/':\nif (num2 == 0) {\nstd::cout << \"Error: division by zero\\n\";\n} else {\nstd::cout << num1 << \" / \" << num2 << \" = \" << num1 / num2 << '\\n';\n}\nbreak;\ndefault:\nstd::cout << \"Error: invalid operator\";\nbreak;\n}\nreturn 0;\n}\n*/";
                break;
            case 2:
                code = "/* #include <iostream>\nint main() {\ndouble temp, converted;\nint option;\nstd::cout << \"Enter the temperature you want to convert: \";\nstd::cin >> temp;\nstd::cout << \"Select an option:\\n\";\nstd::cout << \"1. Convert from Celsius to Fahrenheit.\\n\";\nstd::cout << \"2. Convert from Fahrenheit to Celsius.\\n\";\nstd::cin >> option;\nswitch (option) {\ncase 1:\nconverted = (temp * 9/5) + 32;\nstd::cout << temp << \" Celsius is equal to \" << converted << \" Fahrenheit.\" << std::endl;\nbreak;\ncase 2:\nconverted = (temp - 32) * 5/9;\nstd::cout << temp << \" Fahrenheit is equal to \" << converted << \" Celsius.\" << std::endl;\nbreak;\ndefault:\nstd::cout << \"Invalid option selected.\" << std::endl;\nbreak;\n}\nreturn 0;\n}\n*/";
                break;
            case 3:
                code = "/* #include <iostream>\n#include <cstring>\n#define MAX_BOOKS 100\n#define MAX_TITLE_LEN 50\n#define MAX_AUTHOR_LEN 30\n#define MAX_ISBN_LEN 13\ntypedef struct {\nchar title[MAX_TITLE_LEN];\nchar author[MAX_AUTHOR_LEN];\nchar isbn[MAX_ISBN_LEN];\nint is_available;\n} Book;\nBook library[MAX_BOOKS];\nint num_books = 0;\nvoid add_book() {\nif (num_books >= MAX_BOOKS) {\nstd::cout << \"Error: Library is full\\n\";\nreturn;\n}\nBook new_book;\nstd::cout << \"Enter book title: \";\nstd::cin.ignore();\nstd::cin.getline(new_book.title, MAX_TITLE_LEN);\nstd::cout << \"Enter book author: \";\nstd::cin.getline(new_book.author, MAX_AUTHOR_LEN);\nstd::cout << \"Enter book ISBN: \";\nstd::cin.getline(new_book.isbn, MAX_ISBN_LEN);\nnew_book.is_available = 1;\nlibrary[num_books++] = new_book;\nstd::cout << \"Book added successfully\\n\";\n}\nvoid display_books() {\nstd::cout << \"Title\\t\\tAuthor\\t\\tISBN\\t\\tAvailability\\n\";\nfor (int i = 0; i < num_books; i++) {\nstd::cout << library[i].title << \"\\t\" << library[i].author << \"\\t\" << library[i].isbn << \"\\t\" << (library[i].is_available ? \"Available\" : \"Not available\") << std::endl;\n}\n}\nvoid search_book() {\nchar search_str[MAX_TITLE_LEN];\nstd::cout << \"Enter book title to search: \";\nstd::cin.ignore();\nstd::cin.getline(search_str, MAX_TITLE_LEN);\nint found = 0;\nfor (int i = 0; i < num_books; i++) {\nif (strstr(library[i].title, search_str) != nullptr) {\nstd::cout << \"Book found:\\nTitle: \" << library[i].title << \"Author: \" << library[i].author << \"ISBN: \" << library[i].isbn << \"Availability: \" << (library[i].is_available ? \"Available\" : \"Not available\") << std::endl;\nfound = 1;\n}\n}\nif (!found) {\nstd::cout << \"Book not found\\n\";\n}\n}\nint main() {\nint choice;\ndo {\nstd::cout << \"\\n1. Add book\\n2. Display all books\\n3. Search book\\n4. Exit\\nEnter your choice: \";\nstd::cin >> choice;\nswitch (choice) {\ncase 1:\nadd_book();\nbreak;\ncase 2:\ndisplay_books();\nbreak;\ncase 3:\nsearch_book();\nbreak;\ncase 4:\nstd::cout << \"Exiting program\\n\";\nbreak;\ndefault:\nstd::cout << \"Invalid choice\\n\";\nbreak;\n}\n} while (choice != 4);\nreturn 0;\n}\n*/";
                break;
            case 4:
                code = "/* #include <iostream>\n#include <cstring>\n#define MAX_STUDENTS 100\ntypedef struct {\nchar name[50];\nint age;\nfloat grade;\n} Student;\nStudent students[MAX_STUDENTS];\nint num_students = 0;\nvoid add_student() {\nif (num_students >= MAX_STUDENTS) {\nstd::cout << \"Error: Maximum number of students reached\\n\";\nreturn;\n}\nStudent new_student;\nstd::cout << \"Enter student name: \";\nstd::cin.ignore();\nstd::cin.getline(new_student.name, 50);\nstd::cout << \"Enter student age: \";\nstd::cin >> new_student.age;\nstd::cout << \"Enter student grade: \";\nstd::cin >> new_student.grade;\nstudents[num_students++] = new_student;\nstd::cout << \"Student added successfully\\n\";\n}\nvoid display_students() {\nstd::cout << \"Name\\t\\tAge\\tGrade\\n\";\nfor (int i = 0; i < num_students; i++) {\nstd::cout << students[i].name << \"\\t\" << students[i].age << \"\\t\" << students[i].grade << std::endl;\n}\n}\nvoid search_student() {\nchar search_str[50];\nstd::cout << \"Enter student name to search: \";\nstd::cin.ignore();\nstd::cin.getline(search_str, 50);\nint found = 0;\nfor (int i = 0; i < num_students; i++) {\nif (strstr(students[i].name, search_str) != nullptr) {\nstd::cout << \"Student found:\\nName: \" << students[i].name << \"Age: \" << students[i].age << \"Grade: \" << students[i].grade << std::endl;\nfound = 1;\n}\n}\nif (!found) {\nstd::cout << \"Student not found\\n\";\n}\n}\nint main() {\nint choice;\ndo {\nstd::cout << \"\\n1. Add student\\n2. Display all students\\n3. Search student\\n4. Exit\\n\";\nstd::cout << \"Enter your choice: \";\nstd::cin >> choice;\nstd::cin.ignore(); // consume newline character left in buffer\nswitch (choice) {\ncase 1:\nadd_student();\nbreak;\ncase 2:\ndisplay_students();\nbreak;\ncase 3:\nsearch_student();\nbreak;\ncase 4:\nstd::cout << \"Exiting program...\\n\";\nbreak;\ndefault:\nstd::cout << \"Invalid choice\\n\";\nbreak;\n}\n} while (choice != 4);\nreturn 0;\n}\n*/";
                break;
            case 5:
                code = "#include <iostream>\n#include <cmath>\n\nint main() {\n double a, b, c, discriminant, root1, root2, realPart, imaginaryPart;\n    std::cout << \"Enter coefficients a, b and c: \";\n    std::cin >> a >> b >> c;\n    discriminant = b * b - 4 * a * c;\n    // real and different roots\n    if (discriminant > 0) {\n        root1 = (-b + std::sqrt(discriminant)) / (2 * a);\n        root2 = (-b - std::sqrt(discriminant)) / (2 * a);\n        std::cout << \"Root1 = \" << root1 << \" and Root2 = \" << root2;\n    }\n    // real and equal roots\n    else if (discriminant == 0) {\n        root1 = root2 = -b / (2 * a);\n        std::cout << \"Root1 = Root2 = \" << root1;\n    }\n    // complex roots\n    else {\n        realPart = -b / (2 * a);\n        imaginaryPart = std::sqrt(-discriminant) / (2 * a);\n        std::cout << \"Root1 = \" << realPart << \" + \" << imaginaryPart << \"i and Root2 = \" << realPart << \" - \" << imaginaryPart << \"i\";\n    }\n    return 0;\n}";
                break;
            case 6:
                code = "/* #include <iostream>\n#include <cstring>\n#define MAX_PATIENTS 100\n#define MAX_NAME_LEN 50\n#define MAX_ADDRESS_LEN 100\n#define MAX_SYMPTOMS_LEN 200\ntypedef struct {\nchar name[MAX_NAME_LEN];\nchar address[MAX_ADDRESS_LEN];\nint age;\nchar gender;\nchar symptoms[MAX_SYMPTOMS_LEN];\n} Patient;\nPatient patients[MAX_PATIENTS];\nint num_patients = 0;\nvoid add_patient() {\nif (num_patients >= MAX_PATIENTS) {\nstd::cout << \"Error: Hospital is full\\n\";\nreturn;\n}\nPatient new_patient;\nstd::cout << \"Enter patient name: \";\nstd::cin.ignore();\nstd::cin.getline(new_patient.name, MAX_NAME_LEN);\nstd::cout << \"Enter patient address: \";\nstd::cin.getline(new_patient.address, MAX_ADDRESS_LEN);\nstd::cout << \"Enter patient age: \";\nstd::cin >> new_patient.age;\nstd::cout << \"Enter patient gender (M/F): \";\nstd::cin >> new_patient.gender;\nstd::cout << \"Enter patient symptoms: \";\nstd::cin.ignore();\nstd::cin.getline(new_patient.symptoms, MAX_SYMPTOMS_LEN);\npatients[num_patients++] = new_patient;\nstd::cout << \"Patient added successfully\\n\";\n}\nvoid display_patients() {\nstd::cout << \"Name\\t\\tAge\\tGender\\tAddress\\t\\t\\tSymptoms\\n\";\nfor (int i = 0; i < num_patients; i++) {\nstd::cout << patients[i].name << \"\\t\" << patients[i].age << \"\\t\" << patients[i].gender << \"\\t\" << patients[i].address << \"\\t\\t\\t\" << patients[i].symptoms << std::endl;\n}\n}\nvoid search_patient() {\nchar search_str[MAX_NAME_LEN];\nstd::cout << \"Enter patient name to search: \";\nstd::cin.ignore();\nstd::cin.getline(search_str, MAX_NAME_LEN);\nint found = 0;\nfor (int i = 0; i < num_patients; i++) {\nif (strstr(patients[i].name, search_str) != nullptr) {\nstd::cout << \"Patient found:\\nName: \" << patients[i].name << \"Age: \" << patients[i].age << \"Gender: \" << patients[i].gender << \"Address: \" << patients[i].address << \"Symptoms: \" << patients[i].symptoms << std::endl;\nfound = 1;\n}\n}\nif (!found) {\nstd::cout << \"Patient not found...\\n\";\n}\n}\n*/";
                break;
            case 7:
                code = "#include <iostream>\n\nint ticketPrice = 10;\nint popcornPrice = 5;\nint sodaPrice = 3;\nint ticketsSold = 0;\nint popcornSold = 0;\nint sodaSold = 0;\nint totalRevenue = 0;\n\nvoid displayMenu() {\n    std::cout << \"Welcome to the Movie Theater!\\n1. Buy movie ticket\\n2. Buy popcorn\\n3. Buy soda\\n4. View sales report\\n5. Exit\\n\";\n}\n\nvoid buyTicket() {\n    int quantity;\n    std::cout << \"Movie ticket price is $\" << ticketPrice << \"\\nHow many tickets do you want to buy? \";\n    std::cin >> quantity;\n    if (quantity <= 0) {\n        std::cout << \"Invalid quantity!\\n\";\n        return;\n    }\n    ticketsSold += quantity;\n    totalRevenue += quantity * ticketPrice;\n    std::cout << \"You bought \" << quantity << \" tickets for a total of $\" << quantity * ticketPrice << \"\\n\";\n}\n\nvoid buyPopcorn() {\n    int quantity;\n    std::cout << \"Popcorn price is $\" << popcornPrice << \"\\nHow many popcorns do you want to buy? \";\n    std::cin >> quantity;\n    if (quantity <= 0) {\n        std::cout << \"Invalid quantity!\\n\";\n        return;\n    }\n    popcornSold += quantity;\n    totalRevenue += quantity * popcornPrice;\n    std::cout << \"You bought \" << quantity << \" popcorns for a total of $\" << quantity * popcornPrice << \"\\n\";\n}\n\nvoid buySoda() {\n    int quantity;\n    std::cout << \"Soda price is $\" << sodaPrice << \"\\nHow many sodas do you want to buy? \";\n    std::cin >> quantity;\n    if (quantity <= 0) {\n        std::cout << \"Invalid quantity!\\n\";\n        return;\n    }\n    sodaSold += quantity;\n    totalRevenue += quantity * sodaPrice;\n    std::cout << \"You bought \" << quantity << \" sodas for a total of $\" << quantity * sodaPrice << \"\\n\";\n}\n\nvoid viewSalesReport() {\n    std::cout << \"Tickets sold: \" << ticketsSold << \"\\nPopcorn sold: \" << popcornSold << \"\\nSoda sold: \" << sodaSold << \"\\nTotal revenue: $\" << totalRevenue << \"\\n\";\n}\n\nint main() {\n    int choice;\n    while (1) {\n        displayMenu();\n        std::cout << \"Enter your choice: \";\n        std::cin >> choice;\n        switch (choice) {\n            case 1:\n                buyTicket();\n                break;\n            case 2:\n                buyPopcorn();\n                break;\n            case 3:\n                buySoda();\n                break;\n            case 4:\n                viewSalesReport();\n                break;\n            case 5:\n                std::cout << \"Thank you for visiting the Movie Theater!\\n\";\n                exit(0);\n            default:\n                std::cout << \"Invalid choice!\\n\";\n                break;\n        }\n    }\n    return 0;\n}";
                break;
            case 8:
            std::cout << "1.C Flow Control\n";
            std::cout << "2.C Functions\n";
            std::cout << "3.C Arrays\n";
            std::cout << "4.C Pointers\n";
            std::cout << "5.C Strings\n";
            std::cout << "6.Structure And Union\n";
            std::cout << "7.C Files\n";

            int too;
            std::cin >> too;
            switch (too)
            {
            case 1:
                std::cout << "C Flow Control is a set of statements and constructs in the C programming language that allows programmers to control the flow of program execution. These statements include if-else statements, switch statements, loops (such as for loops, while loops, and do-while loops), and jump statements (such as break, continue, and goto).\n";
                break;
            case 2:
                std::cout << "C Functions are blocks of code that perform a specific task.\nThey are called by name and can take inputs as arguments and optionally return a value.\nFunctions allow code reusability and help in modular programming.\n";
                break;
            case 3:
                std::cout << "In C programming, an array is a collection of elements of the same data type, declared in the following format:\n\n<datatype> <array_name>[<size_of_array>];\n";
                break;
            case 4:
                std::cout << "In C programming, a pointer is a variable that stores the memory address of another variable.\nPointers are used to manipulate memory and create more efficient code by passing memory addresses instead of large data structures.\nThey can be used to dynamically allocate and deallocate memory, as well as access data structures such as arrays and structures.\n";
                break;
            case 5:
                std::cout << "C strings are arrays of characters terminated by a null character, denoted by the '\\0' character.\n";
                break;
            case 6:
                std::cout << "Structure And Union are used to group different types of variables under a single name.\n";
                break;
            case 7:
                std::cout << "C Files are used to read from and write to files in C programming. They allow you to store and access data outside of your program's memory space. File operations include opening, reading, writing, and closing files. These operations can be performed on text files, binary files, or both.\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 7.\n";
                break;
            }
    
            default:
                std::cout << "thanks!" << std::endl;
                continue; // Skip to next iteration
        }

        std::string loadingString = "Loading...";
        animateRotation(durationMs);

        templateString =
            "==============================\n"
            "          HERE IS YOUR PROGRAM        \n"
            "==============================\n";
        displayTemplate(templateString);

        // Display code with animation
        for (char c : code) {
            std::cout << c;
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        std::cout << std::endl;

        templateString =
            "==============================\n"
            "           USER INPUT         \n"
            "==============================\n";
        displayTemplate(templateString);

        getInput(input);

        templateString =
            "==============================\n"
            "         OUTPUT RESULT        \n"
            "==============================\n";
        displayTemplate(templateString);

        // Display loading animation for output result
        for (char c : loadingString) {
            std::cout << c;
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        std::cout << std::endl;
        std::cout << "Result: <Output Result>" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Thanks for using the program!" << std::endl;

    return 0;
}
