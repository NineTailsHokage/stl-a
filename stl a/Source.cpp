#include <iostream>
#include <stdexcept>
#include <cctype>
#include <string>

class invalidCharacterException : public std::runtime_error {
public:
    invalidCharacterException() : std::runtime_error("Invalid character: must be a letter (A-Z, a-z).") {}
};

class invalidRangeException : public std::runtime_error {
public:
    invalidRangeException() : std::runtime_error("Invalid range: resulting character is not a letter (A-Z, a-z).") {}
};

char character(char start, int offset) {
    if (!std::isalpha(start)) {
        throw invalidCharacterException();
    }

    char result = start + offset;

    // Check if the result is a letter
    if (!std::isalpha(result)) {
        throw invalidRangeException();
    }

    return result;
}

int main() {
    std::string input;
    char start;
    int offset;

    while (true) {
        std::cout << "Enter a character (or type 'exit' to quit): ";
        std::cin >> input;

        // Check if the user wants to exit
        if (input == "exit") {
            break;
        }

        // Ensure the input is a single character
        if (input.length() != 1) {
            std::cerr << "Please enter a single character.\n";
            continue;
        }

        start = input[0];

        std::cout << "Enter an offset: ";
        std::cin >> offset;

        try {
            char result = character(start, offset);
            std::cout << start << " + " << offset << " = " << result << "\n";
        }
        catch (const invalidCharacterException& e) {
            std::cerr << "Invalid character: " << start << " - " << e.what() << std::endl;
        }
        catch (const invalidRangeException& e) {
            std::cerr << "Invalid range: " << start << " + " << offset << " - " << e.what() << std::endl;
        }

        std::cout << "\n";
    }

    return 0;
}