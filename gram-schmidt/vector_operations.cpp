#include "vector_operations.h"
#include <cmath>
#include <vector>

double scalar(int n,vector<double> vec1,vector<double> vec2){
    double k=0;
    for(int i=0;i<n;i++){
        k+=vec1[i]*vec2[i];
    }
    return k;
}

double norm_of_vector(int n,vector<double> vec){
    double k=0;
    for(int i=0;i<n;i++){
        k+=vec[i]*vec[i];
    }
    k=sqrt(k);
    return k;
}

vector<double> sum_of_vectors(int n,vector<double> vec1,vector<double> vec2){
    vector<double> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=vec1[i]+vec2[i];
    }
    return vec;
}

vector<double> dif_of_vectors(int n,vector<double> vec1,vector<double> vec2){
    vector<double> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=vec1[i]-vec2[i];
    }
    return vec;
}

vector<double> multiplication_of_vectors(int n,vector<double> vec1,vector<double> vec2){
    vector<double> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=vec1[i]*vec2[i];
    }
    return vec;
}

vector<double> multiplication_with_scalar(int n,vector<double> vec1,double p){
    vector<double> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=vec1[i]*p;
    }
    return vec;
}

vector<double> division_with_scalar(int n,vector<double> vec1,double p){
    vector<double> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=vec1[i]/p;
    }
    return vec;
}