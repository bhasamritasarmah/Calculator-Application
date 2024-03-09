// RegistryKeyCreator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main() {
    // Declare variables
    HKEY hKey;
    DWORD dwDisposition;
    DWORD buttonStyle = 0; // Default to CButton style

    // Create or open the registry key
    LONG result = RegCreateKeyEx(HKEY_CURRENT_USER, _T("Software\\CalculatorApplication"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition);
    if (result != ERROR_SUCCESS) {
        std::cerr << "Error creating/opening registry key." << std::endl;
        return 1; // Return error code
    }

    // Set the button style value in the registry
    result = RegSetValueEx(hKey, _T("UseCButton"), 0, REG_DWORD, (BYTE*)&buttonStyle, sizeof(DWORD));
    if (result != ERROR_SUCCESS) {
        std::cerr << "Error setting registry value." << std::endl;
        RegCloseKey(hKey);
        return 1; // Return error code
    }

    // Close the registry key
    RegCloseKey(hKey);

    std::cout << "Registry key created successfully." << std::endl;

    return 0; // Return success
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
