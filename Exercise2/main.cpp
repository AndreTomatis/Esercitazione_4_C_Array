#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "./src/Utils.hpp"


using namespace std;


int main()
{
    string fn = "./data.txt";
    ifstream ifs(fn);    

    //if the file can't be opened the program ends
    if (ifs.fail()) {
        cerr << "Can't open " << fn << endl;
        return 1;
    }

    int S, n;
    char tmp;


    //read the file first 2 rows
    ifs >> tmp; ifs >> tmp;
    ifs >> S;
    
    ifs >> tmp; ifs >> tmp;
    ifs >> n;
    
    //skip the third row
    ifs >> tmp; ifs >> tmp; ifs >> tmp;

    //store in 2 C-style arrays the values for w and r.
    float *r = new float[n];
    float *w = new float[n];

    for(unsigned int i = 0; i < n; i++){
        ifs >> w[i];
        ifs >> tmp;
        ifs >> r[i];
    }


    float V = calculate_interest(r,w,n,S);

    //if V = 0 then it means something went wrong because there's no interest
    if (V == 0){
        cerr << "error: invalid list r or w in portfolio" << endl;
        return 1;
    }else{
        print(S, n, w, r, V);
    }


    //close the file and disallocate the two arrays
    ifs.close();

    delete[] r;
    delete[] w;

    return 0;
}
