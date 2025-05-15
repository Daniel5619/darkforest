#include <iostream>
#include <stdexcept> // Standard exception library

class DanielException : public std::exception {
    const char* what() const throw(){
        return "custom error occured";
    }
};

int division(int n, int d){
    int returnVal;

        if (d == 0) {
            throw DanielException(); // Throwing an exception
        }
       returnVal = n/d;

    return returnVal;
}

int main() {
    bool success = false;
    int result = 0;
    int a = 10, b = 0;
    
    std::cout << "Enter numerator: ";
    std::cin >> a;
    std::cout << "Enter denominator: ";
    std::cin >> b;

    while(!success){
    try {
    
        result = division(a,b);

        success = true;
        std::cout << "that worked out just fine:" << result << std::endl;

    }catch (const DanielException& e){
        std::cout << "Some daniel specific thing" << "\n" <<  "Please enter another denominator. No zeros please: " << std::endl;
        std::cin >> b;
    }catch (const std::runtime_error& e) { // Catching an exception
        std::cout << "Caught a runtime exception: " << e.what() << std::endl;    
    }catch (const std::exception& e) { // Catching an exception
      std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    }

    std::cout << "result: " << result << "\n";

    return 0;
}