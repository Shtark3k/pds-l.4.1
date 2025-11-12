#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

void print_permutation(const std::vector<int>& p) {
    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << p[i];
    }
    std::cout << std::endl;
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    int n;

    // 2) Input the value for n
    std::cout << "Enter the value for n: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Error: Please enter a positive integer for n." << std::endl;
        return 1;
    }

    // Safety check for large n (optional but helpful)
    if (n > 10) {
        std::cout << "Warning: Generating " << factorial(n)
            << " permutations for n=" << n << " may take a long time." << std::endl;
        std::cout << "Continue (y/n)? ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            return 0;
        }
    }

    // Initialize the vector: 1, 2, 3, ..., n
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 1);

    // 3) Output the lexicographically smallest permutation 123...n
    std::cout << "\n--- All Permutations (Lexicographical Order) ---\n" << std::endl;
    std::cout << "1. Initial Permutation (Smallest):" << std::endl;
    print_permutation(p);

    long long count = 1;

    while (std::next_permutation(p.begin(), p.end())) {
        count++;
        // 4.5) Output the obtained permutation
        print_permutation(p);
    }

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "Finished. Generated " << count << " permutations in total." << std::endl;

    return 0;
}