#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>
#include <map>
#include <vector>

// Function to log expenses
void financeTracker() {
    std::map<std::string, double> expenses;
    std::string category;
    double amount;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true) {
        // Time capture per expense
        time_t now = time(0);
        tm *ltm = localtime(&now);
        std::string date = std::to_string(ltm->tm_year + 1900) + "-" +
                           std::to_string(ltm->tm_mon + 1) + "-" +
                           std::to_string(ltm->tm_mday);
        std::string currentTime = std::to_string(ltm->tm_hour) + ":" +
                                  std::to_string(ltm->tm_min) + ":" +
                                  std::to_string(ltm->tm_sec);

        std::cout << "Enter the category of expense (or 'exit' to finish): ";
        std::getline(std::cin, category);
        if (category == "exit") break;

        std::cout << "Enter the amount for " << category << ": ";
        while (!(std::cin >> amount)) {
            std::cout << "Invalid input. Please enter a valid amount: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        expenses[category] += amount;

        // Save entry
        std::ofstream file("finance_log.txt", std::ios::app);
        if (!file) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }
        file << date << "," << currentTime << "," << category << "," << amount << "\n";
        file.close();

        std::cout << "Logged " << amount << " for " << category << " on " << date << " at " << currentTime << "\n";
    }

    // Display total
    double total = 0;
    for (const auto &entry : expenses) {
        total += entry.second;
    }
    std::cout << "Total expenses logged in this session: " << total << "\n\n";
}

// Function to view finance history
void viewFinanceHistory() {
    std::ifstream file("finance_log.txt");
    if (!file) {
        std::cerr << "No finance log found yet!\n\n";
        return;
    }
    std::string line;
    std::cout << "\n=== Finance History: ===\n";
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    std::cout << "\n";
}

// Function to delete a specific entry from the finance log
void deleteFinanceEntry() {
    std::ifstream file("finance_log.txt");
    if (!file) {
        std::cerr << "No finance log found yet!\n\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    std::cout << "\n=== Finance History: ===\n";
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << i + 1 << ". " << lines[i] << std::endl;
    }

    std::cout << "Enter the number of the entry you want to delete (or 0 to cancel): ";
    std::cin >> lineNumber;

    if (lineNumber <= 0 || lineNumber > static_cast<int>(lines.size())) {
        std::cout << "Invalid choice. No entry deleted.\n\n";
        return;
    }

    std::cout << "Are you sure you want to delete this entry? (y/n): ";
    char confirm;
    std::cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        std::cout << "Deletion cancelled.\n\n";
        return;
    }

    lines.erase(lines.begin() + lineNumber - 1);

    std::ofstream outFile("finance_log.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }
    for (const auto &entry : lines) {
        outFile << entry << "\n";
    }
    outFile.close();

    std::cout << "Entry deleted successfully!\n\n";
}

// Function to handle user login
void login() {
    std::string username, password;
    int attempts = 3;

    while (attempts > 0) {
        std::cout << "Enter your username: ";
        std::cin >> username;
        std::cout << "Enter your password: ";
        std::cin >> password;

        if (username == "rii" && password == "njz") {
            std::cout << "Login successful! Welcome, " << username << "!\n";
            return;
        } else {
            attempts--;
            std::cout << "Invalid credentials. You have " << attempts << " attempt(s) left.\n";
        }
    }
    std::cout << "Too many failed attempts. Exiting program.\n";
    exit(0);
}

// Main function
int main() {
    login();
    std::cout << "Welcome to the finance tracker!\n";

    int choice;
    do {
        std::cout << "===== Finance Tracker =====\n";
        std::cout << "1. Log a new expense\n";
        std::cout << "2. View finance history\n";
        std::cout << "3. Delete a finance entry\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid choice: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                financeTracker();
                break;
            case 2:
                viewFinanceHistory();
                break;
            case 3:
                deleteFinanceEntry();
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
