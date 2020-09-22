// header file
#include <iostream>
using namespace std;

class DNA{
private:

    double sum;
    double mean;
    double variance;
    double standardDev;

    string dnaSeq;
    string numLine;
    int count;

    int countA;
    int countC;
    int countT;
    int countG;

    int countAA;
    int countAC;
    int countAT;
    int countAG;

    int countCA;
    int countCC;
    int countCT;
    int countCG;

    int countTA;
    int countTC;
    int countTT;
    int countTG;

    int countGA;
    int countGC;
    int countGT;
    int countGG;

    double probabilityA;
    double probabilityC;
    double probabilityT;
    double probabilityG;

    double probabilityAA;
    double probabilityAC;
    double probabilityAT;
    double probabilityAG;

    double probabilityCA;
    double probabilityCC;
    double probabilityCT;
    double probabilityCG;

    double probabilityTA;
    double probabilityTC;
    double probabilityTT;
    double probabilityTG;

    double probabilityGA;
    double probabilityGC;
    double probabilityGT;
    double probabilityGG;

    public:
      //constructor
      DNA();
      //destructor
      ~DNA();
      // all calculations
      void calculateFile(string input);
      //output kashishpandey.out
      void outputFile(string file);
      
};
