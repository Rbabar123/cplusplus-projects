#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>
#include <sstream>

// Get system time as "HH:MM"
std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_tm = std::localtime(&now_time);

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << local_tm->tm_hour << ":"
        << std::setw(2) << std::setfill('0') << local_tm->tm_min;
    return oss.str();
}

// Convert "HH:MM" to total minutes
int timeToMinutes(const std::string& timeStr) {
    int h = std::stoi(timeStr.substr(0, 2));
    int m = std::stoi(timeStr.substr(3, 2));
    return h * 60 + m;
}

// Validate time input
bool isValidTime(const std::string& timeStr) {
    if (timeStr.size() != 5 || timeStr[2] != ':') return false;
    try {
        int h = std::stoi(timeStr.substr(0, 2));
        int m = std::stoi(timeStr.substr(3, 2));
        return h >= 0 && h < 24 && m >= 0 && m < 60;
    } catch (...) {
        return false;
    }
}

int main() {
    std::string targetTime, launchCommand;

    std::cout << "===========================================\n";
    std::cout << "   Universal Program Auto-Launcher (Linux) \n";
    std::cout << "===========================================\n";

    // Get time input
    do {
        std::cout << "Enter target time to launch (24-hour HH:MM): ";
        std::cin >> targetTime;
        if (!isValidTime(targetTime))
            std::cout << "Invalid time format! Try again.\n";
    } while (!isValidTime(targetTime));

    std::cin.ignore(); // flush newline
    std::cout << "Enter program or full command to launch (e.g. microsoft-edge, firefox, /opt/...):\n> ";
    std::getline(std::cin, launchCommand);

    std::cout << "\n[INFO] Launch scheduled at " << targetTime << "\n";
    std::cout << "[INFO] Program to launch: `" << launchCommand << "`\n\n";

    int targetMinutes = timeToMinutes(targetTime);
    bool warned = false;

    while (true) {
        std::string current = getCurrentTime();
        int currentMinutes = timeToMinutes(current);
        int diff = targetMinutes - currentMinutes;

        std::cout << "[TIME] Current: " << current << " | Time left: " << diff << " minutes\n";

        if (diff == 5 && !warned) {
            std::cout << "[NOTICE] 5 minutes remaining until launch.\n";
            warned = true;
        }

        if (diff <= 0) {
            std::cout << "[ACTION] Time reached. Launching program...\n";
            std::string command = launchCommand + " &";
            int result = system(command.c_str());

            if (result == 0)
                std::cout << "[SUCCESS] Program launched successfully.\n";
            else
                std::cout << "[ERROR] Failed to launch. Check if the command is correct.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::minutes(1));
    }

    std::cout << "[DONE] Exiting auto-launcher.\n";
    return 0;
}
