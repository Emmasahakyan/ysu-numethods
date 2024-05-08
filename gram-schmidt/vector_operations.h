#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <vector>

double scalar(int n, std::vector<double> vec1, std::vector<double> vec2);
double norm_of_vector(int n, std::vector<double> vec);
std::vector<double> sum_of_vectors(int n, std::vector<double> vec1, std::vector<double> vec2);
std::vector<double> dif_of_vectors(int n, std::vector<double> vec1, std::vector<double> vec2);
std::vector<double> multiplication_of_vectors(int n, std::vector<double> vec1, std::vector<double> vec2);
std::vector<double> multiplication_with_scalar(int n, std::vector<double> vec1, double p);
std::vector<double> division_with_scalar(int n, std::vector<double> vec1, double p);

#endif