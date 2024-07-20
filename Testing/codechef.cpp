#include <iostream>
#include <vector>
#include <string>

int solution(std::vector<std::string>& A); // Declaration of the solution function

int main() {
    // Example input
    std::vector<std::string> tiles = {"RR", "GR", "RG", "GR","GR","RR"};
    
    // Call the solution function
    int result = solution(tiles);
    
    // Print the result
    std::cout << "The length of the longest possible sequence is: " << result << std::endl;
    
    return 0;
}

// Implementation of the solution function
int solution(std::vector<std::string>& A) {
    int rr = 0, gg = 0, rg = 0, gr = 0;
    
    for (const auto& tile : A) {
        if (tile == "RR") rr++;
        else if (tile == "GG") gg++;
        else if (tile == "RG") rg++;
        else if (tile == "GR") gr++;
    }
    
    return rr + gg + std::abs(rg - gr);
}


