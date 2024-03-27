#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 
//=====================================================

// WORD DFA 
// Done by: 
// RE:  
bool word(string s) {
    int state = 0;
    int charpos = 0;
    while (s[charpos] != '\0') {
        if (state == 0 && s[charpos] == 't')
            state = 2;
        else if (state == 0 && ((s[charpos] == 'b') || (s[charpos] == 'g') || (s[charpos] == 'm') || (s[charpos] == 'p') || (s[charpos] == 'r') || (s[charpos] == 'n') || (s[charpos] == 'h') || (s[charpos] == 'k')))
            state = 3;
        else if (state == 0 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 0 && s[charpos] == 's')
            state = 5;
        else if (state == 0 && ((s[charpos] == 'd') || (s[charpos] == 'w') || (s[charpos] == 'z') || (s[charpos] == 'j') || (s[charpos] == 'y')))
            state = 4;
        else if (state == 0 && s[charpos] == 'c')
            state = 6;
        else if (state == 1 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 1 && ((s[charpos] == 'd') || (s[charpos] == 'w') || (s[charpos] == 'z') || (s[charpos] == 'j')))
            state = 4;
        else if (state == 1 && ((s[charpos] == 'b') || (s[charpos] == 'g') || (s[charpos] == 'm') || (s[charpos] == 'p') || (s[charpos] == 'r') || (s[charpos] == 'h') || (s[charpos] == 'k')))
            state = 3;
        else if (state == 1 && s[charpos] == 'c')
            state = 6;
        else if (state == 1 && s[charpos] == 's')
            state = 5;
        else if (state == 1 && s[charpos] == 'n')
            state = 7;
        else if (state == 1 && s[charpos] == 't')
            state = 2;
        else if (state == 2 && s[charpos] == 's')
            state = 4;
        else if (state == 2 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 3 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 3 && s[charpos] == 'y')
            state = 4;
        else if (state == 4 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'y') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 5 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 5 && s[charpos] == 'h')
            state = 4;
        else if (state == 6 && s[charpos] == 'h')
            state = 4;
        else if (state == 7 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I')))
            state = 1;
        else if (state == 7 && ((s[charpos] == 'b') || (s[charpos] == 'g') || (s[charpos] == 'm') || (s[charpos] == 'p') || (s[charpos] == 'r') || (s[charpos] == 'n') || (s[charpos] == 'h') || (s[charpos] == 'k')))
            state = 3;
        else if (state == 7 && ((s[charpos] == 'd') || (s[charpos] == 'w') || (s[charpos] == 'z') || (s[charpos] == 'j') || (s[charpos] == 'y')))
            state = 4;
        else if (state == 7 && s[charpos] == 's')
            state = 5;
        else if (state == 7 && s[charpos] == 't')
            state = 2;
        else if (state == 7 && s[charpos] == 'c')
            state = 6;
        else {
            return false;
        }
        charpos++;
    }
    return (state == 0 || state == 1 || state == 7);
}

// PERIOD DFA 
// Done by: Marwa Mohamed
bool isPeriodValid(string input) {
    int currentState = 0;
    int charPosition = 0;
    while (input[charPosition] != '\0') {
        if (currentState == 0 && input[charPosition] == '.')
            currentState = 1;
        else
            return false;
        charPosition++;
    }
    return (currentState == 1);
}

// ------ Three Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
const int NUM_ROWS = 19;
const int NUM_COLS = 2;
const int NUM_TOKENS = 16;

enum TokenType { ERROR, EOFM, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, WORD1, WORD2 };

string tokenNames[NUM_TOKENS] = { "ERROR", "EOFM", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "WORD1", "WORD2" };

string reservedKeywords[NUM_ROWS][NUM_COLS] = {
    {"masu", "VERB"},
    {"masen", "VERBNNEG"},
    {"mashita", "VERBPAST"},
    {"masendeshita", "VERBPASTNEG"},
    {"desu", "IS"},
    {"deshita", "WAS"},
    {"o", "OBJECT"},
    {"wa", "SUBJECT"},
    {"ni", "DESTINATION"},
    {"watashi", "PRONOUN"},
    {"anata", "PRONOUN"},
    {"kare", "PRONOUN"},
    {"kanojo", "PRONOUN"},
    {"sore", "PRONOUN"},
    {"mata", "CONNECTOR"},
    {"soshite", "CONNECTOR"},
    {"shikashi", "CONNECTOR"},
    {"dakara", "CONNECTOR"},
    {"eofm", "EOFM"}
};

string tokenName[30] = {}; // Placeholder for token display names

// ------------ Scanner and Driver -----------------------

ifstream inputFile;
int scanToken(TokenType& tokenType, string& inputWord) {
    inputFile >> inputWord;
    if (inputWord == "eofm") {
        tokenType = EOFM;
        return 0;
    }
    if (!word(inputWord)) {
        if (isPeriodValid(inputWord)) {
            tokenType = PERIOD;
            return 0;
        } else {
            cout << "LEXICAL ERROR: Invalid string passes no DFA token criteria" << endl;
            tokenType = ERROR;
            return 1;
        }
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        if (inputWord == reservedKeywords[i][0]) {
            for (int j = 0; j < NUM_TOKENS; j++) {
                if (reservedKeywords[i][1] == tokenNames[j]) {
                    tokenType = (TokenType)j;
                    return 0;
                }
            }
        }
    }
    if (inputWord[inputWord.size() - 1] == 'E' || inputWord[inputWord.size() - 1] == 'I')
        tokenType = WORD2;
    else
        tokenType = WORD1;
    return 0;
}

int main() {
    TokenType thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    inputFile.open(filename.c_str());

    while (true) {
        scanToken(thetype, theword);
        if (theword == "eofm")
            break;

        cout << "\n \"" << theword << "\"" << " is token type " << tokenNames[thetype] << endl;
    }

    cout << "End of file is encountered." << endl;
    inputFile.close();
}


