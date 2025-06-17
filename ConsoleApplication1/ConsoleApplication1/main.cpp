#include <iostream>

bool isPrime(int number);

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

/*
* Checks if number is a prime number
* :Param number: The number to check
* :Return: true if number is prime, otherwise false
*/
bool isPrime(int number) {
    //Special cases checks :
    //1 is a special number but it not a prime
    if (number == 1) {
        return false;
    }
    //For efficiency, check if number is even and return false if it is
    if (!(number & 1)) {
        return false;
    }
    //The actual primality check for odd numbers, using the complexity - sqrt(n) method
    for (int i = 3; i <= std::sqrt(number); i+=2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
