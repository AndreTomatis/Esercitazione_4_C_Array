#pragma once
#include <iostream>


using namespace std;


float get_roi(float V, float S);
void print(float S, int n, float*w, float*r, float V);
float calculate_interest(float* r, float* w, int n, float S);