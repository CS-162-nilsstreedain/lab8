//
//  main.cpp
//  Lab 8
//
//  Created by Nils Streedain on 11/15/21.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void printVector(std::vector <int> const &vect) {
    for (auto element : vect)
        std::cout << element << " ";
    std::cout << std::endl;
}

bool isPrime(int x) {
    for (int i = 2; i <= x / 2; i++)
        if (x%i == 0)
            return false;
    return true;
}

int main(int argc, const char * argv[]) {
    // Ask user how big to make the array
    std::cout << "What should the size of the array be?" << std::endl;
    
    // Retrieve and verify user input
    int vectSize = 0;
    while (!(std::cin >> vectSize) || vectSize < 1 || vectSize > 25) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input, please type an integer between 1 and 25." << std::endl;
    }
    std::cout << std::endl;
    
    // Create randomly arranged vector of size vectSize
    std::vector<int> toSort(vectSize);
    std::generate(toSort.begin(), toSort.end(), []() {
        return rand() % 100;
    });
    
    // Print randomly arranged vector
    std::cout << "Randomly Arranged Vector:" << std::endl;
    printVector(toSort);
    
    // Copy and sort vector
    std::vector<int> sorted = toSort;
    for (int i = 0; i < vectSize; i++) {
        // Find min for each iteration
        int currMin = i;
        for (int j = i; j < vectSize; j++)
            if (sorted.at(currMin) > sorted.at(j))
                currMin = j;

        // Swap min element with the correct index
        int temp = sorted.at(i);
        if (temp != currMin) {
            sorted.at(i) = sorted.at(currMin);
            sorted.at(currMin) = temp;
        }
    }
    
    // Print sorted Vector
    std::cout << std::endl << "Sorted Vector:" << std::endl;
    printVector(sorted);
    
    
    // Print Prime numbers
    std::cout << std::endl << "Prime Numbers:" << std::endl;
    for (auto element : sorted)
        if (isPrime(element))
            std::cout << element << " ";
    
    std::cout << std::endl;
    
    return 0;
}
