#include <iostream>
#include <cstdlib> 

/**
* COMPLETE THE DOCUMENTATION
*/
long long recurse(int n) {
    // Define base cases
    // int result;
    // If n > 2, result = recurse(n − 1) + 2 + recurse(n − 2) + 4 × J(n − 3)
    // idk how to end the recursion when we get what we want
    return 0;
}

// EXAMPLE RECURSIVE FUNCTION TO COMPUTE FACTORIALS
// Define a function to calculate factorial
// recursively
/*
long long factorial(int n)
{
    // Base case - If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case - Return n multiplied by
    // factorial of (n-1)

    return n * factorial(n - 1);
}
*/


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
