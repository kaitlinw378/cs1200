#include <fstream>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    std::ifstream in_str(argv[1]);

    
    if (!in_str.good()) {
      std::cerr << "Can't open " << argv[1] << " to read.\n";
      exit(1);
    }
    
    int temp;
    int sum = 0;
    int i = 0;
    int low;
    
    while (in_str >> temp) {
      // do something with my_variable
        if (i == 0 || temp < low) {
            low = temp;
        }
       
        sum += temp;
        i++;
    }
    float avg = float(sum) / float(i);
    
    std::cout << "Average: " << avg << std::endl;
    std::cout << "Lowerst: " << low << std::endl;
    std::cout << "Count: " << i << std::endl;
}
