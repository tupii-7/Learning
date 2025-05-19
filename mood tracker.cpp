#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>

void logMood() {
    std::string mood;
    std::string date, currentTime;

    // Get current date and time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date = std::to_string(ltm->tm_year + 1900) + "-" +
           std::to_string(ltm->tm_mon + 1) + "-" +
           std::to_string(ltm->tm_mday);
    currentTime = std::to_string(ltm->tm_hour) + ":" +
                  std::to_string(ltm->tm_min) + ":" +
                  std::to_string(ltm->tm_sec);

    // Ask for user mood
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "How are you feeling today, sayang? (e.g., happy, sad, tired): ";
    std::getline(std::cin, mood);

    // Write to file
    std::ofstream file("mood_log.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    file << date << " " << currentTime << " - " << mood << "\n";
    file.close();

    std::cout << "Mood logged successfully! ♡\n\n";
}

void viewMoodHistory() {
    std::ifstream file("mood_log.txt");
    if (!file) {
        std::cerr << "No mood log found yet!\n\n";
        return;
    }

    std::string line;
    std::cout << "\n=== Mood History: ===\n";
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    std::cout << "\n";
}

int main() {
    int choice;

    do {
        std::cout << "===== Mood Journal Tracker =====\n";
        std::cout << "1. Log a new mood\n";
        std::cout << "2. View mood history\n";
        std::cout << "3. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                logMood();
                break;
            case 2:
                viewMoodHistory();
                break;
            case 3:
                std::cout << "Okayy, see you next time~ Take care of your heart!\n";
                break;
            default:
                std::cout << "Oops! Invalid choice. Try again, cutie~\n\n";
        }
    } while (choice != 3);

    return 0;
}
