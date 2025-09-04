# Lab 3: Computer Program Errors, I/O and Arithmetic
There are three different types of errors that can occur in a computer program, and all of these need to be found and fixed before a program will work correctly.  Each of these three errors is examined below.

## Learner Objectives
At the conclusion of this lab assignment, participants should be able to:
* Differentiate among syntax, run-time and logic errors
* Create a C++ program with user interaction using `cout` and `cin`
* Create arithmetic expressions
* Identify when to use integer division and the modulo operator

## Prerequisites
* Understanding of the lessons taught in Chapter 2

## Acknowledgements
Content used in this assignment is based upon information in the following sources:
* Gaddis book lab materials

## Getting Started
1. Open terminal.

   If you haven't done this yet, configure your git "identity":
   ```
   $ git config --global user.name "FIRST_NAME LAST_NAME"
   $ git config --global user.email "YOUR_@COLLEGE_EMAIL"
   ```
2. Make sure your current working directory is `~/cs150/lab`. Navigate to this directory if needed.
3. Clone this repository using `git clone <REPO_URL> lab3`. This should create a folder `lab3` under `~/cs150/lab`.
4. Open Visual Studio Code by typing in the terminal `code .`

## Lab 3.1

### A. Syntax Errors
A *syntax error* in a program, just like a syntax error in English, means that a grammar rule has been broken. One or more of the programming statements in the source code do not follow the rules for how a C++ program must be written.  Let’s take a look at the most commonly made C++ syntax error, an omitted semi-colon.

1. In Visual Studio Code, create a new file `lab3_1.cpp`. Open the C++ source file `lab3_1.cpp` in the text editor and copy the source code below.
```cpp
/**
 * @file WRITE FILE NAME
 *
 * This program finds the average of two numbers.
 * It contains two errors that must be fixed.
 *
 * @author WRITE STUDENT NAME
 * @date   WRITE DATE TODAY
 */
#include <iostream>
using namespace std;

int main ()
{
    int size = 0;    // The number of values to be averaged
    double num1 = 0.0,     // User input number 1
           num2 = 0.0,     // User input number 2
           average = 0.0;  // Average of num1 and num2

    // Get the two numbers
    cout << "Enter two numbers separated by one or more spaces: "
    cin  >> num1 >> num2;

    // Calculate the average
    average = num1 + num2 / size;

    // Display the average
    cout << "The average of the two numbers is: " << average << endl;

    return 0;
}
```
2. The **first 9 lines** is what we call the *header comment*. All your programs should have one, especially your programming assignments. This is also a practice done in the industry, although the information required will be based on the company's coding standards. Update the header comment with the appropriate file name, student name and date today.
3. Save and compile the code in the terminal. The name of the executable file should be `Lab3_1`. Recall two things about compiling the code in the terminal:
   1. Make sure you are inside the folder where the C++ source file is located.
   2. Use the compile command `g++ -Wall <.cpp FILES> -o <NAME OF EXECUTABLE FILE>`

   However, it will not compile successfully. You will see a compilation error that should look like this:
```
main.cpp: In function ‘int main()’:
main.cpp:21:66: error: expected ‘;’ before ‘cin’
   21 |     cout << "Enter two numbers separated by one or more spaces: "
      |                                                                  ^
      |                                                                  ;
   22 |     cin  >> num1 >> num2;
      |     ~~~
```

4. Always read the message carefully. Sometimes it is clear what is wrong. Other times the message may be confusing to a new programmer, but you will get better at deciphering compiler error messages as you gain more experience. This message is quite clear. It says that a semi-colon `;` is missing before the word `cin`. 

    Notice that the compiler error message also includes a line number indicating the approximate, but not the exact location where the error occurred.  In this case, the error occurred at the end of **line 21**. In other C++ compilers, it will detect this error at **line 22**. This is because the compiler doesn't really detect the problem until it reached the `cin` on **line 22**. 
 
    > **Debugging Strategy:** Any time you get a compiler error message and do not see a problem in the line reported, try checking the previous line(s).

5. A program containing compiler errors cannot be run until the errors are fixed and the program is recompiled.  Put a semi-colon `;` at the end of **line 21** and then compile the program again in the terminal. If you have done it correctly, it will compile with no errors this time.  
6. Run/Execute the program in the terminal.
7. Commit your code with a message "*lab 3.1A is completed*". Recall the terminal commands:
   1. `git add -A`
   2. `git commit -m "COMMIT MESSAGE"`

### B. Run-time Errors
A *run-time error* occurs when a program instruction tells the program to do something it is unable to correctly do. This type of error cannot be detected by a compiler because no syntax rules have been broken.  So the program will compile but, as the name suggests, something will go wrong when the program is run. In some cases a run-time error causes the program to abort; in others, it continues running but produces incorrect results.  Let’s take a look at a common run-time error, attempting to divide by zero.

1. Continue working with the previous code. Read through the source code to see if you can spot any errors in the program. Two lines contain errors, but even if you can find them, do not fix them yet.

2. Run the program and, at the prompt, enter  `10 5`.  Did the run-time error cause the program to abort or to produce incorrect results?  If it ran without aborting it probably displayed something like this:
```
Enter two numbers separated by one or more spaces: 10 5
The average of the two numbers is: inf
```

3. The error occurs on **line 25** when a quantity is divided by `size`.  Notice that `size` is set on **line 15** to `0`.  Correct the error by changing **line 15** of the source code to set `size` equal to `2` so that the quantity on **line 25** will be divided by `2`.  Then recompile and rerun the program, again entering `10` and `5` for the two numbers. The output should now look like this:
```
Enter two numbers separated by one or more spaces: 10 5
The average of the two numbers is: 12.5
```
4. Commit your code with a message "*lab 3.1B is completed*".

### C. Logic Errors
A *logic error* causes a program to work incorrectly.  It doesn’t break any syntax rules and doesn’t tell the computer to do anything it is unable to do.  Instead, it occurs when the program logic is wrong because what the programmer tells the program to do does not match what he or she means for it to do.  If you were explaining to someone how to do laundry, it would be a logic error to tell them to put the laundry in the oven, when what you meant was for them to put it in the washer.  Another logic error would occur if you told them to wash the laundry and then fold it but forgot to tell them to dry it.  It would also be a logic error if you got the steps out of order and told them to first fold the laundry, then dry it, and then finally to wash it.  Likewise, for a program to be correct, each instruction must be correct, no instructions must be omitted, and the instructions must be carried out in the right order. 

Let’s look at a logic error that causes a program to carry out two mathematical operations in the wrong order.

1. Look again at the output created by the previous program.  Notice that the user entered `10` and `5`, but the program reported the average to be `12.5`, rather than `7.5`. The error occurs on **line 25**.  To find an average of a set of values, you must add the values before you divide by the number of values.  But the code on **line 25** tells the computer to divide the value stored in `num2` by `size` before adding the result to the value stored in `num1`.  You will learn more in Chapters 2 and 3 about how to write correct mathematical statements in C++. For now, just add parentheses on **line 25** so it says:
```cpp
average = (num1 + num2) / size;
```

2. Recompile and rerun the program, again entering `10` and `5` at the prompt.  Now that you have corrected the logic error, you should get the following correct result.
```
Enter two numbers separated by one or more spaces: 10 5
The average of the two numbers is: 7.5
```

3. Commit your code with a message "*lab 3.1C is completed*".
4. Push your code back to the GitHub repo.

## Lab 3.2 - Fix the Errors
1. Inside Lab3 folder create a `lab3_2.cpp` file
2. Add the following code in the editor
```cpp
/**
 * @file WRITE FILE NAME
 *
 * This This program has one syntax error and one logic error.
 *
 * @author WRITE STUDENT NAME
 * @date   WRITE DATE TODAY
 */
#include <iostream>
using namespace std

int main ()
{
    double length = 0.0,  // Length of a room in feet
           width = 0.0,   // Width of a room in feet
           area = 0.0;        // Area of the room in sq. ft.

    // Get the room dimensions
    cout << "Enter room length (in feet): ";
    cin  >> length;

    cout << "Enter room width (in feet): ";
    cin  >> length;

    // Compute and display the area
    area = length * width;
    cout << "The area of the room is " << area 
         << " square feet." << endl;

    return 0;
}
```
3. Fix the header comment similar to what you did in **Lab 3.1a Step 2**.
4. Use the compiler error message to help you locate the syntax error and fix it.
5. Once the program compiles with no errors, run the program, and examine the output.  Analyze what is going wrong so you can find and fix the logic error in the program.  Once you have it running correctly the output should look like the following:
```
Enter room length (in feet): 15
Enter room width (in feet): 10
The area of the room is 150 square feet.
```
6. Commit your code with a message "*lab 3.2 is completed*".
7. Push your code back to the GitHub repo.

## Lab 3.3 - Convert Seconds into days, hours, minutes and seconds
- [ ] Create a `lab3_3.cpp` file. 
- [ ] In `lab3_3n.cpp`, create a C++ program to convert seconds into days, hours, minutes and seconds. The program will prompt the user to enter the number of seconds and the program will display the seconds in days, hours, minutes and seconds. Below are sample runs of the program you will be creating. Once you have designed and written your program, compile the code in the terminal. The name of the executable file should be `Lab3_3`.

> **HINT**: You will need to use *integer division* and *modulo operator* to design an algorithm for this. However, there are other ways to solve it.

Run 1:
<pre>
Enter number of seconds: <b>9234</b>
9234 seconds is equivalent to 0 days 2 hours 33 minutes and 54 seconds
</pre>

Run 2:
<pre>
Enter number of seconds: <b>193234</b>
193234 seconds is equivalent to 2 days 5 hours 40 minutes and 34 seconds
</pre>

Run 3:
<pre>
Enter number of seconds: <b>100</b>
100 seconds is equivalent to 0 days 0 hours 1 minutes and 40 seconds
</pre>

> You can use this [website](https://www.tools4noobs.com/online_tools/seconds_to_hh_mm_ss/) to check if your results are the same.

- [ ] Present your work to the instructor after finishing all parts of the lab. Prepare to answer questions.
- [ ] Commit your code with a message "*lab 3.3 is completed*".
- [ ] Do a final push of your code back to the GitHub repo.

## Submitting Assignments
* It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
