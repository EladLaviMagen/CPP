#include <iostream>

#define END_INPUT 10

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

/*
* Gets primes and stores them in an array
* :Param arr: [OUT] Array pointer for the array to store the primes in
* :Param size: Size of array, as well as the number of primes to collect
* :Return: None
*/
void getPrimes(int* arr, int size) {
    if (arr != nullptr) {
        int numbersInserted = 0;
        int numberCounter = 2;
        while (numbersInserted < size) {
            if (isPrime(numberCounter)) {
                arr[numbersInserted] = numberCounter;
                numbersInserted++;
            }
            numberCounter++;
        }
    }
}

/*
* Inputs a number from user
* :Return: The number inputted
*/
int getNumberFromUser() {
    int number = 0;
    std::cout << "Enter number of primes : ";
    std::cin >> number;
    return number;
}

int main() {
    int numberOfPrimes = getNumberFromUser();
    int* primeArray = new int[numberOfPrimes];
    getPrimes(primeArray, numberOfPrimes);
    std::cout << "Primes : " << std::endl;
    for (int i = 0; i < numberOfPrimes; i++) {
        std::cout << primeArray[i] << "  ";
    }
    delete[] primeArray;
    return 0;
}


