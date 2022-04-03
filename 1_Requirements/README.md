# LEXICAL ANALYZER FOR C
# Table of Contents
* About this project
* Tokens
* How Lexical Analyzer functions
* How to Run this Project
* Assumptions for Subset of C++
* Sample Source Code
* Screen Shots
# About the Project
This project is a lexical analyzer generator written in C. Lexical Analysis is the first phase of the compiler also known as a scanner. It converts the High level input program into a sequence of Tokens.
Lexical Analysis can be implemented with the Deterministic finite Automata.
![image](https://user-images.githubusercontent.com/101394631/161423329-da0763f2-775c-4148-a7ec-7e6c75b7f2ee.png)

Lexical analyzer reads the characters from source code and convert it into tokens.
![image](https://user-images.githubusercontent.com/101394631/161423372-933a2d8d-0d87-49d8-a62c-04c7fed8d9be.png)
# TOKENS
* A lexical token is a sequence of characters that can be treated as a unit in the grammar of the programming languages.
 Example of tokens:
* Type token (id, number, real, . . . )
* Punctuation tokens (IF, void, return, . . . )
* Alphabetic tokens (keywords)
# How Lexical Analyzer functions
1.Tokenization i.e. Dividing the program into valid tokens.
2.Remove white space characters.
3.Remove comments.
4. It also provides help in generating error messages by providing row numbers and column numbers.
# How to Run this Project:
Clone the lexical anlyzer project first.
Change directory to Lexical-Analyzer using command: cd Lexical-Analyzer.
Make a text file in this folder and write source code in C.
Give the iput file to the source code called stringtopharse.
Open  file by double clicking on the file.
now run the code.
You'll see all associated tokens from the source code.
# Assumptions
 Special Symbol: ; { } ( ) , #
 Keyword: int, char, float,main
 Pre-processor Directives: include, define
 Library: iostream, studio, string
 Operators: *, +, >>, <<,>,<
 Numbers/Integers: 0 to 9.
 Identifies/ Variables: All alphabetic strings except the keywords, numbers, Pre-processor directive and library strings.
 # Sample source code
* My source code is provided in the below URL(https://github.com/yamini8309/M1_C_PRO.git)
* My source code txt:
*   double sb = 5.0 + 3 + 5.8 + (a + b) + s + c2 + 1c;
# OUTPUT OF SOURCE CODE
* ![output](https://user-images.githubusercontent.com/101394631/161424654-230b35be-1626-486d-abba-3ca4b601030e.PNG)
