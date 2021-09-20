/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 1 - Tutnese Translation
 * This is the main file, where our main method lives. This program reads an english file from the command line and writes the tutnese translation to another file from the command line.
*/
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char** argv) {
  FileProcessor *x = new FileProcessor(); // creates FileProcessor pointer to use its method processFile later 
  if (argc == 3) { // checks if correct amount of command line arguments were entered.
    x->processFile(argv[1], argv[2]); // reads english file from argv[1] and writes tutnese translation in file from argv[2]
  } else { // if incorrect amount of command lines were entered
    cout << "Must enter 2 seperate file names when running program." << endl;
  }
  delete x; // frees up spacce taken by FileProcessor x
  return 0;
}
