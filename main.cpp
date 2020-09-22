// including header file
#include "DNA.h"
#include <iostream>
// stream class to both read and write from/to files
#include <fstream>
using namespace std;

// main method
int main(int argc, char** argv){
  // argument count
  if(argc > 1){

    string out = argv[1];
    // choice = y/n
    char choice;

    // loop is for wanting to continue to add files
    bool loop = true;
    DNA* dna = new DNA();

    ofstream output;
    // opening file
    output.open ("kashishpandey.out");
    // output file prints my info
    output << "CPSC350-02" << endl;
    output << "Programming Assignment 1: C++ Review" << endl;
    output << "Kashish Pandey" << endl;
    output << "ID Number: 002342588" << endl;

    // closing file
    output.close();
    // dna is a pointer
    dna->outputFile(out);
    delete dna;

    // if user wants to add another file
    while(loop){

      DNA* dna2 = new DNA();
      // asking to add another file
      cout << "\nAdd another file?: y/n: ";
      cin >> choice;
      // if the choice is yes
      if(choice == 'y' || choice == 'Y'){
        //asking for file
        cout << "Enter new text file: ";
        cin >> out;
        dna2->outputFile(out);
        delete dna2;

      }
      // if the choice is no
      else if(choice == 'n' || choice == 'N'){
        // telling user where all the info is located + telling them the program is done
        cout << "Please check kashishpandey.out - data is stored there. Program has ended." << endl;

        loop = false;
        delete dna2;

      }
      // if the user types something invalid
      else {
		cout << "Please enter a valid option" << endl;
      }
    }
  }
}
