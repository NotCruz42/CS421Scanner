#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: **
// RE:   **
// WORD DFA 
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
// Done by: **
bool period(string s) {
              int state = 0;
              int charpos = 0;
              while (s[charpos] != '\0') {  // while there is a character in the string
                  if (state == 0 && s[charpos] == '.')  // if we are in the start state and we read a period
                      state = 1;  // go to the final state
                  else
                      return false; // if we read any other character, it's not a period
                  charpos++;
              }
              return (state == 1);  // return true if we are in the final state
}


// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
 enum tokentype { ERROR, EOFM, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, WORD1, WORD2 };

          string tokenName[NUMTOKENS] = { "ERROR", "EOFM", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "WORD1", "WORD2" };

          string reservedWords[ROWS][COLS] = {
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

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { }; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file
 int scanner(tokentype& tt, string& w) {
              fin >> w;
              if (w == "eofm") {
                  tt = EOFM;
                  return 0;
              }
              if (!word(w)) {
                  if (period(w)) {
                      tt = PERIOD;
                      return 0;
                  } else {
                      cout << "LEXICAL ERROR: Invalid string passes no DFA token criteria" << endl;
                      tt = ERROR;
                      return 1;
                  }
              }
              for (int i = 0; i < ROWS; i++) {
                  if (w == reservedWords[i][0]) {
                      for (int j = 0; j < NUMTOKENS; j++) {
                          if (reservedWords[i][1] == tokenName[j]) {
                              tt = (tokentype)j;
                              return 0;
                          }
                      }
                  }
              }
              if (w[w.size() - 1] == 'E' || w[w.size() - 1] == 'I')
                  tt = WORD2;
              else
                  tt = WORD1;
              return 0;
          }

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: 
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.   
  
  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */

}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

