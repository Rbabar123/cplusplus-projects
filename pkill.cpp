#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>
#include <sstream>

bool autoRestart = false; // set to true if you want it to monitor again after killing

// Get current time in "HH:MM" format
std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::tm* local_tm = std::localtime(&time_now);

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << local_tm->tm_hour << ":"
        << std::setw(2) << std::setfill('0') << local_tm->tm_min;
    return oss.str();
}

// Convert "HH:MM" to total minutes since midnight
int timeToMinutes(const std::string& timeStr) {
    int hour = std::stoi(timeStr.substr(0, 2));
    int min = std::stoi(timeStr.substr(3, 2));
    return hour * 60 + min;
}

// Validate time format
bool isValidTime(const std::string& input) {
    if (input.length() != 5 || input[2] != ':') return false;
    try {
        int hour = std::stoi(input.substr(0, 2));
        int min = std::stoi(input.substr(3, 2));
        return (hour >= 0 && hour < 24 && min >= 0 && min < 60);
    } catch (...) {
        return false;
    }
}

void monitorAndKill(const std::string& targetTime) {
    int targetMinutes = timeToMinutes(targetTime);
    bool warned = false;

    std::cout << "Monitoring started. Press Ctrl+C to cancel.\n\n";

    while (true) {
        std::string currentTime = getCurrentTime();
        int currentMinutes = timeToMinutes(currentTime);
        int diff = targetMinutes - currentMinutes;

        std::cout << "[INFO] Current: " << currentTime
                  << " | Target: " << targetTime
                  << " | Time left: " << diff << " min\n";

        if (diff == 5 && !warned) {
            std::cout << "[WARNING] 5 minutes left before closing Microsoft Edge!\n";
            warned = true;
        }

        if (diff <= 0) {
            std::cout << "[ACTION] Target time reached.\n";
            int result = system("pkill -f msedge");
            if (result == 0)
                std::cout << "[SUCCESS] Edge was closed successfully.\n";
            else
                std::cout << "[WARNING] Edge was not closed (maybe not running).\n";

            if (autoRestart) {
                std::cout << "[RESTART] Monitoring will restart in 1 minute...\n\n";
                std::this_thread::sleep_for(std::chrono::minutes(1));
                warned = false;
                continue;
            } else {
                std::cout << "[EXIT] Monitoring ended.\n";
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
}

int main() {
    std::string targetTime;

    std::cout << "====================================\n";
    std::cout << "     Edge Auto-Killer for Linux     \n";
    std::cout << "====================================\n";

    // Time input
    do {
        std::cout << "Enter target time (24-hour format HH:MM): ";
        std::cin >> targetTime;
        if (!isValidTime(targetTime))
            std::cout << "Invalid format. Try again.\n";
    } while (!isValidTime(targetTime));

    std::cout << "Target time set to " << targetTime << ".\n";

    // Start monitoring
    monitorAndKill(targetTime);

    return 0;
}

