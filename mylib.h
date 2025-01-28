
#ifndef MYLIB_H
#define MYLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// operations on numbers
// basic
int SumOfDigits(int num);
int reverseNumber(int num);
bool isPalindrome(int num);
bool isPrime(int num);
int gcd(int a , int b );
int lcm (int a , int b);
long factorial(int num);
bool isEven(int num) ;
//intermediate
void primeFactors(int num); 
bool isArmstrong(int num);
void fibonacciSeries(int n);
int sumDivisors(int num);
bool isPerfect(int num);
bool isMagic(int num);
bool isAutomorphic(int num);
// advanced  
void toBinary(int num);
bool isNarcissistic(int num);
double sqrtApprox(int num);
double power(int base, int exp);
bool isHappy(int num);
bool isAbundant(int num);
bool isDeficient(int num);
int sumEvenFibonacci(int n);
bool isHarshad(int num);
unsigned long catalanNumber(int n);
void pascalTriangle(int n);
unsigned long bellNumber(int n);
bool isKaprekar(int num);
bool isSmith(int num);
int sumOfPrimes(int n);
// opertions on arrays
// basic arrays functions
void initializeArray(int arr[], int size, int value);
void printArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int sumArray(int arr[], int size);
double averageArray(int arr[], int size);
bool isSorted(int arr[], int size);
//intermediate arrays functions
void reverseArray(int arr[], int size);
void countEvenOdd(int arr[], int size , int* evenCount , int* oddCount);
int secondLargest(int arr[], int size);
void elementFrequency(int arr[], int size);
int removeDuplicates(int arr[], int size);
int binarySearch(int arr[], int size, int target);
int linearSearch(int arr[], int size, int target);
void leftShift(int arr[], int size, int rotations);
void rightShift(int arr[], int size, int rotations);
//sorting algorithms
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

//add
void inputArray(int arr[], int size);

//menu
void printMainMenu();
void printArrayMenu();
void printNumberMenu();
#endif

