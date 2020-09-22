// including header file
#include "DNA.h"
#include <iostream>
// stream class to both read and write from/to files
#include <fstream>
// in readme file - used for standard deviation and variance
#include <cmath>
//in readme file - used for random_shuffle of dnaSeq
#include <algorithm>
using namespace std;

DNA::DNA(){
  // assigning values
  sum = 0;
  mean = 0;
  variance = 0;
  standardDev = 0;

  dnaSeq = "";
  numLine = "";
  count = 0;

  countA = 0;
  countC = 0;
  countT = 0;
  countG = 0;

  countAA = 0;
  countAC = 0;
  countAT = 0;
  countAG = 0;

  countCA = 0;
  countCC = 0;
  countCT = 0;
  countCG = 0;

  countTA = 0;
  countTC = 0;
  countTT = 0;
  countTG = 0;

  countGA = 0;
  countGC = 0;
  countGT = 0;
  countGG = 0;

  probabilityA = 0;
  probabilityC = 0;
  probabilityT = 0;
  probabilityG = 0;

  probabilityAA = 0;
  probabilityAC = 0;
  probabilityAT = 0;
  probabilityAG = 0;

  probabilityCA = 0;
  probabilityCC = 0;
  probabilityCT = 0;
  probabilityCG = 0;

  probabilityTA = 0;
  probabilityTC = 0;
  probabilityTT = 0;
  probabilityTG = 0;

  probabilityGA = 0;
  probabilityGC = 0;
  probabilityGT = 0;
  probabilityGG = 0;
}

//destructor
  DNA::~DNA(){
  }

void DNA::calculateFile(string input){
  //reading into file
  ifstream infile(input);

  while (getline(infile, numLine)){
    for(int i = 0; i < numLine.length(); ++i){
      // toupper will make all uppercase
      char nucleotide = toupper(numLine[i]);
      // looking at the letter following the Nucleotide therefore the i+1
      char bigram = toupper(numLine[i+1]);

      // checking if nucleotide is 'A' then checking the following character
      if (nucleotide == 'A'){
        countA++;
        if(bigram == 'A'){
          countAA++;
        }
        else if(bigram == 'C'){
          countAC++;
        }
        else if(bigram == 'T'){
          countAT++;
        }
        else if(bigram == 'G'){
          countAG++;
        }
        sum++;
      }
      // checking if nucleotide is 'C' then checking the following character
      if (nucleotide == 'C'){
        countC++;
        if(bigram == 'A'){
          countCA++;
        }
        else if(bigram == 'C'){
          countCC++;
        }
        else if(bigram == 'T'){
          countCT++;
        }
        else if(bigram == 'G'){
          countCG++;
        }
        sum++;
      }
      // checking if nucleotide is 'T' then checking the following character
      if (nucleotide == 'T'){
        countT++;
        if(bigram == 'A'){
          countTA++;
        }
        else if(bigram == 'C'){
          countTC++;
        }
        else if(bigram == 'T'){
          countTT++;
        }
        else if(bigram == 'G'){
          countTG++;
        }
        sum++;
      }
      // checking if nucleotide is 'G' then checking the following character
      if (nucleotide == 'G'){
        countG++;
        if(bigram == 'A'){
          countGA++;
        }
        else if(bigram == 'C'){
          countGC++;
        }
        else if(bigram == 'T'){
          countGT++;
        }
        else if(bigram == 'G'){
          countGG++;
        }
        sum++;
      }
    }
    count++;
}

  // calculation of mean
  mean = sum / count;

  // relative probability of each nucleotide (A,C,T,G)
  probabilityA = countA / sum;
  probabilityC = countC / sum;
  probabilityT = countT / sum;
  probabilityG = countG / sum;

  // relative probability of (AA, AC, AT, AG)
  probabilityAA = countAA / (sum/2);
  probabilityAC = countAC / (sum/2);
  probabilityAT = countAT / (sum/2);
  probabilityAG = countAG / (sum/2);

  // relative probability of (TA, TC, TT, TG)
  probabilityTA = countTA / (sum/2);
  probabilityTC = countTC / (sum/2);
  probabilityTT = countTT / (sum/2);
  probabilityTG = countTG / (sum/2);

  // relative probability of (CA, CC, CT, CG)
  probabilityCA = countCA / (sum/2);
  probabilityCC = countCC / (sum/2);
  probabilityCT = countCT / (sum/2);
  probabilityCG = countCG / (sum/2);

  // relative probability of (GA, GC, GT, GG)
  probabilityGA = countGA / (sum/2);
  probabilityGC = countGC / (sum/2);
  probabilityGT = countGT / (sum/2);
  probabilityGG = countGG / (sum/2);

  //reading into file
  ifstream newfile(input);

  double calc = 0.0;
  double v = 0;

  while (getline(newfile, numLine)){
    for(int i = 0; i < numLine.length(); ++i){
      // pow from #include <cmath>
      calc = pow(( numLine.length() - mean ), 2);
    }
    v+= calc;
    variance = (v / (count-1));
    // square root from #include <cmath>
    standardDev = sqrt(variance);
  }
}

  void DNA::outputFile(string file){
    //writing into file
    ofstream firstFile;
    firstFile.open ("kashishpandey.out", fstream::app);
    calculateFile(file);

    // all the print statements
    firstFile << "\nThe data from the text file " << file << " is: " << endl;
    firstFile << "Sum: " << sum << endl;
    firstFile << "Mean: " << mean << endl;
    firstFile << "Variance: " << variance << endl;
    firstFile << "Standard Deviation: " << standardDev << endl;

    firstFile << "\nRelative probability of A: " << probabilityA << endl;
    firstFile << "Relative probability of C: " << probabilityC << endl;
    firstFile << "Relative probability of T: " << probabilityT << endl;
    firstFile << "Relative probability of G: " << probabilityG << endl;

    firstFile << "\nRelative probability of AA: " << probabilityAA <<endl;
    firstFile << "Relative probability of AC: " << probabilityAC << endl;
    firstFile << "Relative probability of AT: " << probabilityAT << endl;
    firstFile << "Relative probability of AG: " << probabilityAG << endl;

    firstFile << "\nRelative probability of CA: " << probabilityCA << endl;
    firstFile << "Relative probability of CC: " << probabilityCC << endl;
    firstFile << "Relative probability of CT: " << probabilityCT << endl;
    firstFile << "Relative probability of CG: " << probabilityCG << endl;

    firstFile << "\nRelative probability of TA: " << probabilityTA << endl;
    firstFile << "Relative probability of TC: " << probabilityTC << endl;
    firstFile << "Relative probability of TT: " << probabilityTT << endl;
    firstFile << "Relative probability of TG: " << probabilityTG << endl;

    firstFile << "\nRelative probability of GA: " << probabilityGA << endl;
    firstFile << "Relative probability of GC: " << probabilityGC << endl;
    firstFile << "Relative probability of GT: " << probabilityGT << endl;
    firstFile << "Relative probability of GG: " << probabilityGG << endl;

    firstFile << "\nGaussian distribution of 1000 DNA strings: " << endl;

    // closing kashishpandey.out
    firstFile.close();
    // another stream to do Gaussian distribution
    ofstream nextFile;
    nextFile.open ("kashishpandey.out", fstream::app);
    // Gaussian distribution
    // pre-incrementing ++i
    for(int i = 0; i <= 1000; ++i){

      // a and b, uniformly distributed in [0,1)
      // using RAND_MAX and rand() - in readme file
      double a = ((double)rand() / (RAND_MAX));
      double b = ((double)rand() / (RAND_MAX));

      //C = sqrt(-2 ln (a)) * cos(2πb)
      double c = sqrt(-2 * log(a)) * cos(2* 3.14 * b);
      //D = σC + μ
      double d = abs(ceil((standardDev * c) + mean));

      // checking if d is 0
      if(d == 0){
        d = 1;
      }
      // using round() results in whole nucleotide instead of half - caused errors without rounding
      int probA = round(probabilityA * d);
      int probC = round(probabilityC * d);
      int probT = round(probabilityT * d);
      int probG = round(probabilityG * d);

      // gets d length
      for(int x = 0; x < d; ++x){
        // adding right amount of char to string
        // rounding for whole number
       if(0 < round((probA))){
         dnaSeq += 'A';
         probA--;
       }
       if(0 < round((probC))){
         dnaSeq += 'C';
         probC--;
       }
       if(0 < round((probT))){
         dnaSeq += 'T';
         probT--;
       }
       if(0 < round((probG))){
         dnaSeq += 'G';
         probG--;
       }
   }
   //shuffles the elements in the range [start, finish) with uniform distribution
   random_shuffle (dnaSeq.begin(), dnaSeq.end());

   nextFile << dnaSeq << endl;
   // needed for sequence to print out in the file
   dnaSeq = "";
    }
    // closing nextFile
    nextFile.close();
  }
