// Mini Compiler Front-End in C++
// Uses all 10 experiments from Compiler Lab
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <sstream>
#include <stack>
#include <tuple>
#include <algorithm>
#include <limits>
using namespace std;

// Experiment 4 & 6: Identifier & Symbol Table
struct Symbol {
    string name;
    string type;
    int address;
};
vector<Symbol> symbolTable;
int addressCounter = 1000;

bool isKeyword(const string& token) {
    const vector<string> keywords = {"int", "float", "char", "if", "else", "for", "while", "return"};
    return find(keywords.begin(), keywords.end(), token) != keywords.end();
}

bool isValidIdentifier(const string& token) {
    return regex_match(token, regex("[a-zA-Z_][a-zA-Z0-9_]*"));
}

void addToSymbolTable(string name, string type) {
    for (auto& sym : symbolTable) if (sym.name == name) return;
    symbolTable.push_back({name, type, addressCounter++});
}

// Experiment 5: Operator Detection
bool isOperator(const string& token) {
    const vector<string> ops = {"+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">="};
    return find(ops.begin(), ops.end(), token) != ops.end();
}

// Experiment 2: Remove Comments
string removeComments(const string& code) {
    regex singleLine("//.*");
    regex multiLine("/\\*.*?\\*/");
    return regex_replace(regex_replace(code, multiLine, ""), singleLine, "");
}

// Experiment 3: Pattern Recognition
tuple<bool, string> matchPattern(const string& token) {
    if (regex_match(token, regex("a+"))) return {true, "a+"};
    if (regex_match(token, regex("a*b+"))) return {true, "a*b+"};
    return {false, ""};
}

// Experiment 1: Lexical Analyzer (tokenizer)
vector<string> tokenize(const string& code) {
    stringstream ss(code);
    string token;
    vector<string> tokens;
    while (ss >> token) tokens.push_back(token);
    return tokens;
}

// Experiment 7: 3-Address Code Generator
void generate3AddressCode(const string& expr) {
    stack<string> stk;
    int tempNum = 1;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isOperator(token)) {
            if (stk.size() < 2) {
                cout << "Invalid expression for 3-address code generation." << endl;
                return;
            }
            string b = stk.top(); stk.pop();
            string a = stk.top(); stk.pop();
            string temp = "t" + to_string(tempNum++);
            cout << temp << " = " << a << " " << token << " " << b << endl;
            stk.push(temp);
        } else stk.push(token);
    }
    if (!stk.empty()) cout << "Result: " << stk.top() << endl;
}

// Experiment 8: Infix to Postfix
int precedence(const string& op) {
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

vector<string> infixToPostfix(vector<string> tokens) {
    stack<string> ops;
    vector<string> output;
    for (auto& token : tokens) {
        if (isOperator(token)) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                output.push_back(ops.top()); ops.pop();
            }
            ops.push(token);
        } else {
            output.push_back(token);
        }
    }
    while (!ops.empty()) {
        output.push_back(ops.top()); ops.pop();
    }
    return output;
}

// Experiment 9: Parse Tree (Basic Representation)
void printParseTree(const vector<string>& postfix) {
    cout << "\nParse Tree Representation (Postfix):\n";
    for (const auto& token : postfix) cout << token << " ";
    cout << endl;
}

void displayMenu() {
    cout << "\n===== Mini Compiler Menu =====\n";
    cout << "1. Enter Source Code\n";
    cout << "2. Remove Comments\n";
    cout << "3. Tokenize and Classify\n";
    cout << "4. Display Symbol Table\n";
    cout << "5. Convert Infix to Postfix\n";
    cout << "6. Generate 3-Address Code\n";
    cout << "7. Show Parse Tree\n";
    cout << "8. Pattern Recognition (a+, a*b+)\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

int main() {
    string rawCode;
    string processedCode;
    vector<string> tokens;
    vector<string> postfix;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Enter your code (end input with a single line containing 'END'):\n";
                rawCode.clear();
                while (true) {
                    string line;
                    getline(cin, line);
                    if (line == "END") break;
                    rawCode += line + "\n";
                }
                break;

            case 2:
                processedCode = removeComments(rawCode);
                cout << "\nCode after removing comments:\n" << processedCode << endl;
                break;

            case 3:
                tokens = tokenize(processedCode);
                cout << "\nTokens & Classification:\n";
                for (const auto& token : tokens) {
                    if (isKeyword(token)) cout << token << " : keyword\n";
                    else if (isOperator(token)) cout << token << " : operator\n";
                    else if (isValidIdentifier(token)) {
                        cout << token << " : identifier\n";
                        addToSymbolTable(token, "int");
                    } else if (regex_match(token, regex("[0-9]+"))) {
                        cout << token << " : constant\n";
                    } else {
                        auto matchResult = matchPattern(token);
                        if (get<0>(matchResult)) cout << token << " : matches pattern " << get<1>(matchResult) << "\n";
                        else cout << token << " : unknown\n";
                    }
                }
                break;

            case 4:
                cout << "\nSymbol Table:\nName\tType\tAddress\n";
                for (const auto& sym : symbolTable)
                    cout << sym.name << "\t" << sym.type << "\t" << sym.address << endl;
                break;

            case 5:
                cout << "\nEnter infix expression (space separated): ";
                {
                    string line;
                    getline(cin, line);
                    stringstream ss(line);
                    string token;
                    vector<string> infix;
                    while (ss >> token) infix.push_back(token);
                    postfix = infixToPostfix(infix);
                    cout << "Postfix Expression:\n";
                    for (auto& t : postfix) cout << t << " ";
                    cout << endl;
                }
                break;

            case 6:
                cout << "\nEnter postfix expression (space separated): ";
                {
                    string line;
                    getline(cin, line);
                    generate3AddressCode(line);
                }
                break;

            case 7:
                printParseTree(postfix);
                break;

            case 8:
                cout << "\nEnter strings to test against patterns a+ and a*b+ (type END to finish):\n";
                while (true) {
                    string str;
                    getline(cin, str);
                    if (str == "END") break;
                    auto result = matchPattern(str);
                    if (get<0>(result))
                        cout << str << " matches pattern: " << get<1>(result) << endl;
                    else
                        cout << str << " does not match any pattern\n";
                }
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
