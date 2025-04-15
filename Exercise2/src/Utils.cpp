#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"


using namespace std;


// Calculates the rate of return (ROI) of the portfolio
float get_roi(float V, float S){
    return (V - S) / 100;
}

// Outputs investment details and ROI to a file
void print(float S, int n, float* w, float* r, float V){
    ofstream ofs("./result.txt");

    ofs << "S = "; 
    ofs << fixed << setprecision(2) << S << defaultfloat;
    ofs << ", n = " << setprecision(3) << n << endl;

    // Print weights
    ofs << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        ofs << w[i] << " ";
    ofs << "]" << endl;

    // Print returns
    ofs << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        ofs << r[i] << " ";
    ofs << "]" << endl

        // Print ROI and final portfolio value
        << "Rate of return of the portfolio: " << get_roi(V, S) << endl
        << "V: "; 
    ofs << fixed << setprecision(2) << V << defaultfloat;
    ofs << endl;
    
    ofs.close();
}

// Calculates the final portfolio value after applying weights and returns
float calculate_interest(float* r, float* w, int n, float S){
    float V = 0;
    for(unsigned int i = 0; i < n; i++){
        V += (1 + r[i]) * (w[i] * S); // Value from each asset
    }

    return V;
}
