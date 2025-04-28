#include <iostream>
#include <cstdlib> 

/**
 * @brief Finds value of J(n) where J(0) = 0, J(1) = 1, J(2) = 2. If n > 2
 * 
 * @param n Input number
 * @return 
 */
long long seriesRecursive(int n) {
    try {
        // Define base cases
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        } else if (n > 2) {
            return (seriesRecursive(n - 1) + 2) * (seriesRecursive(n - 2) + 4) * seriesRecursive(n - 3);
        } else {
            throw "n must be a valid integer!";
        }
    } catch (const char* e) {
        std::cout << "Caught exception: " << e << std::endl;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    // Read n from command line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1; 
    }

    // Convert n to an integer
    int n = std::atoi(argv[1]); 

    // Compute series value of n
    long long result = seriesRecursive(n); 
    std::cout << "seriesRecursive(" << n << ") = " << result << std::endl;

    return 0; 
}
