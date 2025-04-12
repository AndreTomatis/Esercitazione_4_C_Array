#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;



float get_roi(float V, float S){
    return (V - S) / 100;
}


void print(float S, int n, float*w, float*r, float V){
    ofstream ofs("./result.txt");

    ofs << "S = "; 
    ofs << S;
    ofs << ", n = " << n << endl;
    ofs << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        ofs << w[i] << " ";
    ofs << "]" << endl;

    ofs << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        ofs << r[i] << " ";
    ofs << "]" << endl
        << "Rate of return of the portfolio: " << get_roi(V, S) << endl
        << "V: "; 
    ofs << fixed << setprecision(2) << V << defaultfloat;
    ofs << endl;
    
    ofs.close();
}


float calculate_interest(float* r, float* w, int n, float S){
    float V = 0;
    for(unsigned int i = 0; i < n; i++){
        V += (1+r[i])*(w[i] * S);
    }

    return V;
}


int main()
{


    string fn = "./data.txt";
    ifstream ifs(fn);    

    if (ifs.fail()) {
        cerr << "Can't open " << fn << endl;
        return 1;
    }

    int S, n;
    char tmp;


    ifs >> tmp; ifs >> tmp;
    ifs >> S;
    
    ifs >> tmp; ifs >> tmp;
    ifs >> n;
    
    ifs >> tmp; ifs >> tmp; ifs >> tmp;

    float *r = new float[n];
    float *w = new float[n];

    for(unsigned int i = 0; i < n; i++){
        ifs >> w[i];
        ifs >> tmp;
        ifs >> r[i];
    }


    float V = calculate_interest(r,w,n,S);

    if (V == 0){
        cerr << "error: invalid list r or w in portfolio" << endl;
        return 1;
    }else{
        print(S, n, w, r, V);
    }


    ifs.close();

    delete[] r;
    delete[] w;

    return 0;
}
