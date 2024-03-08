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
