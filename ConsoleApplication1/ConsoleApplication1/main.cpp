#include <iostream>

/*
 * Checks if number is a prime number
 * :Param number: The number to check
 * :Return: true if number is prime, otherwise false
 */
bool isPrime(int number) {
    // Special cases checks :
    // 1 is a special number but it not a prime
    if (number == 1) {
        return false;
    }
    // The primality check, using the complexity - sqrt(n) method
    for (int i = 2; i <= std::sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number = 0;
    std::cout << "Enter number to check if it's prime : ";
    std::cin >> number;
    if (number < 0) {
        std::cout << "LEAVE ME ALONE YOU MALICIOUS USERS";
        return 1;
    }
    if (isPrime(number)) {
        std::cout << "P R I M E" << std::endl;
    } else {
        std::cout << "Not prime" << std::endl;
    }
    return 0;
}


