#ifndef GRAM_SCHMIDT_H
#define GRAM_SCHMIDT_H

#include <vector>

std::vector<std::vector<double>> gram_schmidt_classic(int n, std::vector<std::vector<double>> vec);
std::vector<std::vector<double>> gram_schmidt_modified(int n, std::vector<std::vector<double>> vec);

#endif
