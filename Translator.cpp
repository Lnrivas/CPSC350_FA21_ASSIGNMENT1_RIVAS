/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 1 - Tutnese Translation
 * This is the implementation .cpp file for the Translator class. Used for translating an english word into a tutnese word and translating an english sentence into a tutnese sentence.
*/
#include "Translator.h"
#include "Model.h" // for access to methods from Model

Translator::Translator() { // default constructor body, it's empty

}

Translator::~Translator() { // destructor body, it's empty

}

string Translator::translateEnglishWord(string englishWord) { // takes a single string representing a single English word as input and returns a string representing the Tutnese translation.
  string ret = "";
  Model m; // makes Model object to use the methods from the Model class
  for (int i = 0; i < englishWord.size(); ++i) { // iterates through the english word, letter by letter
    if (i < englishWord.size()-1 && englishWord[i] == englishWord[i+1]) { // for the first letter in a double letter sequence
       ret += m.translateDoubleCharacter(englishWord[i]);
    } else { // for any other character
      ret += m.translateSingleCharacter(englishWord[i]);
    }
  }
  return ret; // returns the translated word.
}

string Translator::translateEnglishSentence(string englishSentence) { // takes a single string representing a single English sentence as input and returns a string representing the Tutnese translation. Accounts for punctuation.
  string out = "";
  string word = "";
  for (int i = 0; i < englishSentence.size(); ++i) { // iterates through the english sentence, character by character
    word += englishSentence[i]; // adds each letter to "word"
    if (englishSentence[i] == ' ' || i == englishSentence.size()-1) { // if " " is encountered or end of sentence is reached aka a full word have been iterated through and added to "word"
      out += translateEnglishWord(word); // translates word saved in "word" variable to tutnese and saves it in "out" variable
      word = ""; // clears "word" variable so it is ready to store the next word.
    }
  }
  return out; // returns the translated sentence.
}
