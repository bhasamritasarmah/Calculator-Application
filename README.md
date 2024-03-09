# The Calculator Application in Work
[Calculator Application Video](<Video/CalculatorApplicationVideo.mp4>)

# Main Software Tool Used to Make This Project
Visual Studio Community Edition 2022


# Steps Taken to Create MFC App
1. Open Visual Studio 2022. On the default page that shows up, click on 'Create a New Project'.

![alt text](<Images/Screenshot (232).png>)

2. In the 'Create new project' page that opens up, choose 'C++' in the Languages dropdown. Select 'MFC App' and click on 'Next'.

![alt text](<Images/Screenshot (233).png>)

3. In the 'Configure your new project' page, enter a relevant 'Project name' and choose the desired 'Location'. Click on 'Create'.

![alt text](<Images/Screenshot (234).png>)

4. In the 'MFC Application' dialog box that appears, choose Application Type as 'Dialog based' from the drop-down and keep the rest as it is. Click on 'Finish'.

![alt text](<Images/Screenshot (235).png>)

5. The MFC project opens up. You can click the 'Local Windows Debugger' button to run the project and see it's default behaviour.

![alt text](<Images/Screenshot (236).png>)


# Steps Taken to Create DLL Project Inside the Same Solution

1. Right click on "Solution 'CalculatorApplication' (1 of 1 project)". In the menu, go to 'Add' and then click on 'New Project...'.

![alt text](<Images/Screenshot (237).png>)

2. In the 'Add a new project' window that appears, select 'Dynamic-Link Library (DLL)' and click on 'Next'.

![alt text](<Images/Screenshot (238).png>)

3. In the 'Configure your new project' window, provide a relevant 'Project name' and select the desired 'Location'. It should ideally be in the same folder as the MFC project.

![alt text](<Images/Screenshot (240).png>)

4. The new project is created.

![alt text](<Images/Screenshot (239).png>)


# Steps Taken to Link the Two Projects

1. Right click on the Solution and click on 'Properties'. In the 'Project Dependencies' section, select 'CalculatorApplication' under 'Projects' dropdown. And tick 'CalculatorOperations' under the 'Depends on:'. This will tell Visual Studio that the 'CalculatorApplication' project depends on 'CalculatorOperations' project. And hence, 'CalculatorOperations' will be built before 'CalculatorApplication' project.

![alt text](<Images/Screenshot (243).png>)

2. Right click on 'References' under 'CalculatorApplication' project and click on 'Add Reference...' on the menu. 

![alt text](<Images/Screenshot (241).png>)

3. On the dialog box, under 'Projects' section, tick the 'CalculatorOperations'. This will tell Visual Studio that 'CalculatorApplication' project references 'CalculatorOperations' project. 

![alt text](<Images/Screenshot (242).png>)


# Steps to Create COperations Class Under 'CalculatorOperations' Project

1. Right click on 'CalculatorOperations' project. Under 'Add' in the menu, select 'Class...'.

![alt text](<Images/Screenshot (244).png>)

2. In the 'Add Class' dialog box that appears, add a desired name in 'Class name' and click 'OK'. A .h and a .cpp file will be created. 

![alt text](<Images/Screenshot (245).png>)

# Windows Registry

### What is Windows Registry?

Windows Registry is a hierarchical database that stores low-level settings for Microsoft Windows operating system and for applications that opt to use the registry. For example, when a program is installed, a new subkey containing settings such as a program's location, its version and how to start the program, are all added to the Windows Registry.

The registry contains two basic elements: *keys* and *values*. Registry keys are container objects similar to folders. Registry values are non-container objects similar to files. Keys may contain values and sub-keys.

### Why do we need it?

Prior to the Windows Registry, .INI files stored each program's settings as a text file or binary file. Compared to .INI files, Windows Registy offers several advantages -
1. **User-specific settings:** .INI files were often located in a shared location that did not provide user-specific settings in a multi-user scenerio. Because user-based registry settings are loaded from a user-specific path rather than from a read-only system location, the registy allows multiple users to use the same machine.
2. **Atomic updates:** If two processes attempt to update the same registry value at the same time, one process's change will precede the other's and the overall consistency of the data will be maintained. Where changes are made to .INI files, such race conditions can result in inconsistent data that does not match either attempted update.
3. **Faster read-writes:** Since file parsing is done much more efficiently with a binary format, it can be read from or written to more quickly than a text INI file.

### How can we update the Registry?

Let's consider the following piece of code to change the style of the button.
```
BOOL CYourApp::InitInstance()
{
    // ...

    // Create or open the registry key
    HKEY hKey;
    LONG result = RegCreateKeyEx(HKEY_CURRENT_USER, _T("Software\\CalculatorApplication"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
    if (result != ERROR_SUCCESS) {
        return FALSE;
    }

    // Set the button style value in the registry
    DWORD buttonStyle = 0; // Default to CButton style
    result = RegSetValueEx(hKey, _T("UseCButton"), 0, REG_DWORD, (BYTE*)&buttonStyle, sizeof(DWORD));
    if (result != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return FALSE;
    }

    // Close the registry key
    RegCloseKey(hKey);

    return TRUE;
}
```

Here is a step-by-step explanation of each function or key-word used in the above piece of program -

1. **HKEY:** HKEY is a typedef supplied in Windows C++ headers that stands for 'Handle to a Registry Key'. When requesting resources from the registry, a handle is provided that represents the actual key.

```
LONG RegCreateKeyEx( 
    HKEY hKey, 
    LPCWSTR lpSubKey, 
    DWORD Reserved, 
    LPWSTR lpClass, 
    DWORD dwOptions, 
    REGSAM samDesired, 
    LPSECURITY_ATTRIBUTES lpSecurityAttributes, 
    PHKEY phkResult, 
    LPDWORD lpdwDisposition
);
```
2. **RegCreateKeyEx:** This function creates the specified key. If the key already exists in the registry, the function opens it. 
    - *hKey:* One of the predefined reserved handle values. In this case, it is HKEY_CURRENT_USER.
    - *lpSubKey:* Pointer to a null-terminated string specifying the name of a subkey that this function opens or creates. In this case, it is the subkey path "Software\\\\CalculatorApplication" written in Unicode.
    - *Reserved:* This parameter is reserved and is set to 0 always.
    - *lpClass:* Pointer to a null-terminated string that specifies the class (object type) of this key. This parameter is ignored if the key already exists. Since, HKEY_CURRENT_USER already exists, this is set to NULL.
    - *dwOptions:* In this case, it is set to *REG_OPTION_NON_VOLATILE* (default). The information is stored in a file and is preserved when the system is restarted.
    - *samDesired:* Mask that specifies the access rights for the key to be created. In this case, it is set to *KEY_WRITE*, which combines the STANDARD_RIGHTS_WRITE, KEY_SET_VALUE, and KEY_CREATE_SUB_KEY access rights.
    - *lpSecurityAttributes:* Windows automatically assigns the key a default security descriptor. The value is set to NULL always.
    - *phkResult:* Pointer to a variable that receives a handle to the open or created key. In this case it is hKey.
    - *lpdwDisposition:* Pointer to a variable that receives the value as REG_CREATED_NEW_KEY or REG_OPENED_EXISTING_KEY. In this case, it is set to NULL.

3. **ERROR_SUCCESS:** Indicates success. Corresponds to a 0 (LONG) value.
4. The key created by RegCreateKeyEx function has no values.
5. **DWORD:** A data type that stands for *double word*. It is a 32-bit unsigned integer.

```
LONG RegSetValueEx( 
    HKEY hKey, 
    LPCWSTR lpValueName, 
    DWORD Reserved, 
    DWORD dwType, 
    const BYTE *lpData, 
    DWORD cbData
);
```

6. **RegSetValueEx:** This function stores data in the value field of an open registry key. It can also set additional value and type information for the specified key.
    - *hKey:* One of the predefined reserved handle values. In this case, it is HKEY_CURRENT_USER.
    - *lpValueName:* Pointer to a string containing the name of the value to set. If the value with this name is not already present in the key, the function adds it to the key. In this case, it is "UseCButton".
    - *Reserved:* This parameter is reserved and is set to 0 always.
    - *dwType:* Specifies the type of information to be stored as the value's data. In this case, it is a DWORD, which refers to a 32-bit number.
    - *lpData:* Pointer to a buffer containing the data to be stored with the specified value name. In this case, it is *buttonStyle*.
    - *cbData:* Specifies the size, in bytes, of the information pointed to by the *lpData* parameter.

7. **RegCloseKey:** Closes a handle to the specified registry key.


# Steps To Create a Console Script to Update Registry

1. Type 'regedit.exe' in the Search bar of your system.

![alt text](<Images/Screenshot (246).png>)

2. Inside the folder 'HKEY_CURRENT_USER' and the sub-folder 'Software', search for 'CalculatorApplication'. It should not be present.

![alt text](<Images/Screenshot (247).png>)

3. Now, open Visual Studio 2022 as an administrator. (Why? Because we need admin priviledges to make changes to the registry.)

![alt text](<Images/Screenshot (249).png>)

4. Click on 'New Project' in the default window that opens up. In the 'Create a new project' window, select C++ Console App and click 'Next'. Give a suitable name for the Project and click on 'Create'.

![alt text](<Images/Screenshot (250).png>)

5. Write the script for updating registry in the &lt;project_name&gt;.cpp file. And run the file.

![alt text](<Images/Screenshot (251).png>)

6. Now check the Registry Editor. A new value will be created there.

![alt text](<Images/Screenshot (248).png>)






# Resources Used

1. [MFC Playlist](https://www.youtube.com/watch?v=awT-e2zxBUQ&list=PLbbMKXzfxUBTB06Pvc2lXxCUqX6z0hwNi)
2. [Making a Calculator Application using MFC](https://www.youtube.com/watch?v=r0p6bTs_8Pg&pp=ygUWbWZjIG1pY3Jvc29mdCB0dXRvcmlhbA%3D%3D)
3. [Linking a DLL project with a dialog-based MFC Project](https://www.youtube.com/watch?v=z9x3anC3ruw&t)
4. [Creating a registry key with given details](https://chat.openai.com/share/eec5b30b-e60c-4e97-9a5d-6794a91fada8)
5. [About Windows Registry](https://en.wikipedia.org/wiki/Windows_Registry)
6. [About RegCreateKeyEx](https://learn.microsoft.com/en-us/previous-versions/ms961347(v=msdn.10))
7. [About RegCreateKeyExA](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regcreatekeyexa)
8. [About Registry Key Security and Access Rights](https://learn.microsoft.com/en-us/windows/win32/sysinfo/registry-key-security-and-access-rights)
9. [About RegSetValueEx](https://learn.microsoft.com/en-us/previous-versions/ms942534(v=msdn.10))