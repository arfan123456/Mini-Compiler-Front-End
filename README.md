# Mini Compiler Front-End

A C++ based Mini Compiler Front-End that demonstrates several fundamental concepts of Compiler Design through a single interactive console application.

The project combines multiple Compiler Lab experiments into one menu-driven program, including lexical analysis, comment removal, pattern recognition, symbol table generation, operator detection, infix-to-postfix conversion, three-address code generation, and basic parse tree representation.

---

## 📌 Project Overview

A compiler translates source code into a form that can be understood and executed by a computer.

This project focuses on the **front-end concepts of a compiler**, where source code is analyzed and transformed through different stages.

The application provides a menu-driven interface that allows users to perform different compiler-related operations.

---

## ✨ Features

The project implements the following features:

- Lexical Analysis / Tokenization
- Keyword Detection
- Identifier Validation
- Constant Detection
- Operator Detection
- Comment Removal
- Pattern Recognition
- Symbol Table Generation
- Infix to Postfix Conversion
- Three-Address Code Generation
- Basic Parse Tree Representation
- Interactive Menu-Driven Console Interface

---

## 🛠️ Technologies Used

- **C++**
- C++ Standard Library
- Regular Expressions (`regex`)
- Stack
- Queue
- Vector
- Map
- String Stream
- Tuple
- Algorithm Library

---

## 🧪 Compiler Lab Experiments

This project combines multiple compiler laboratory experiments into one program.

### Experiment 1: Lexical Analyzer

The lexical analyzer tokenizes the given source code and classifies tokens into different categories.

Supported token types include:

- Keywords
- Identifiers
- Operators
- Constants
- Pattern-matching tokens
- Unknown tokens

Example:

```text
int x = 10

Output:

int : keyword
x : identifier
= : operator
10 : constant
Experiment 2: Remove Comments

The program removes both:

Single-line comments
Multi-line comments

Example:

// This is a comment


int x = 10;


/*
   Multi-line comment
*/

The comments are removed before further processing.

Experiment 3: Pattern Recognition

The project supports recognition of the following regular expression patterns:

a+
a*b+

Examples:

aaaa
ab
aab
aaabbb

The program checks whether the input string matches one of the supported patterns.

Experiment 4: Identifier Recognition and Symbol Table

The program validates identifiers using the following pattern:

[a-zA-Z_][a-zA-Z0-9_]*

Valid examples:

x
total
student_name
_value

A symbol table is also maintained for recognized identifiers.

The symbol table contains:

Name	Type	Address
x	int	1000
total	int	1001

The address starts from 1000 and increases for every new identifier.

Experiment 5: Operator Detection

The program detects common arithmetic, relational, and assignment operators.

Supported operators include:

+
-
*
/
%
=
==
!=
<
>
<=
>=
Experiment 6: Symbol Table

The symbol table stores information about identifiers found during lexical analysis.

Each symbol contains:

Name
Type
Address

Example:

Symbol Table:


Name    Type    Address
x       int     1000
y       int     1001
total   int     1002
Experiment 7: Three-Address Code Generation

The program generates intermediate three-address code from a postfix expression.

Example input:

a b + c *

Output:

t1 = a + b
t2 = t1 * c
Result: t2

This demonstrates the generation of an intermediate representation used in compiler design.

Experiment 8: Infix to Postfix Conversion

The program converts an infix expression into postfix notation using operator precedence and a stack.

Example:

a + b * c

Postfix:

a b c * +

The program uses operator precedence to determine the correct order of operations.

Experiment 9: Parse Tree Representation

The project provides a basic representation of the parse tree using the generated postfix expression.

The postfix expression is displayed as the current parse-tree representation.

Example:

Parse Tree Representation (Postfix):


a b c * +
Experiment 10: Compiler Front-End Integration

The individual compiler laboratory concepts are integrated into a single menu-driven application.

The user can select different operations from the main menu and perform compiler-related tasks interactively.

📋 Main Menu

When the program starts, the following menu is displayed:

===== Mini Compiler Menu =====


1. Enter Source Code
2. Remove Comments
3. Tokenize and Classify
4. Display Symbol Table
5. Convert Infix to Postfix
6. Generate 3-Address Code
7. Show Parse Tree
8. Pattern Recognition (a+, a*b+)
0. Exit
🔄 Program Workflow

The general workflow of the project is:

Source Code
     │
     ▼
Remove Comments
     │
     ▼
Tokenization
     │
     ▼
Token Classification
     │
     ├── Keywords
     ├── Identifiers
     ├── Constants
     └── Operators
     │
     ▼
Symbol Table
     │
     ▼
Intermediate Code
     │
     ├── Infix → Postfix
     │
     └── Three-Address Code
     │
     ▼
Basic Parse Tree Representation
💻 How to Run
Step 1: Clone the Repository
git clone YOUR_REPOSITORY_URL

Then move into the project directory:

cd Mini-Compiler-Front-End
Step 2: Compile the Program

Using g++:

g++ main.cpp -o compiler
Step 3: Run the Program
Windows
compiler.exe
Linux / macOS
./compiler
🖥️ Example Usage
Enter Source Code

Select:

1

Then enter source code:

int x = 10;
int y = 20;
x = x + y;

Finish the input by typing:

END
Remove Comments

Select:

2

The program displays the source code after removing comments.

Tokenize and Classify

Select:

3

The program identifies:

Keywords
Identifiers
Operators
Constants
Display Symbol Table

Select:

4

The program displays the generated symbol table.

Infix to Postfix

Select:

5

Example input:

a + b * c

Output:

a b c * +
Three-Address Code

Select:

6

Enter a postfix expression:

a b + c *

Output:

t1 = a + b
t2 = t1 * c
Result: t2
Pattern Recognition

Select:

8

Enter a string such as:

aaabbb

The program checks whether it matches:

a+

or

a*b+

Type:

END

to stop testing strings.

📂 Project Structure
Mini-Compiler-Front-End/
│
├── main.cpp
├── README.md
└── screenshots/
    ├── menu.png
    ├── lexical_analysis.png
    ├── symbol_table.png
    ├── postfix.png
    └── three_address_code.png

File names may be different depending on how the project is organized.
