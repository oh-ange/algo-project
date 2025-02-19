#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// operations on numbers :
// basic
int SumOfDigits(int num){
	 int s = 0 ; 
    while (num != 0 ){
    	int d = num % 10 ; // obtain the digit.
    	s = s + d ; // calculate the sum.
    	num = num /10 ; 
	}
	return s; 
}
int reverseNumber(int num){
    int reverse , d;
     reverse = 0;
    while (num != 0 ){
	d = num % 10 ; // obtain the last digit .
   	reverse = reverse*10 + d ; // reverse of the number formation.
   	num = num /10 ;
	}
return reverse;
}

bool isPalindrome(int num) {
   int reverse = reverseNumber(num) ; // use the previous function to obtain the reverse (int reverseNumber(int num).
  return reverse == num ; // return true if reverse = num , return false if reverse != num.
  } 

/* better ; 
bool isPolindrome(int num){
return reverseNumber(num) == num;
}*/

bool isPrime(int num){
	if (num <=1 ){
		return false; // because negatives numbers are never prime && 0 &&1
	}
	int i;
	for ( i = 2 ; i*i <= num ; i++ ){  // find out if there's any devisors.
		if (num%i == 0 ){
			return false ;
		}
	}
	return true; // if the number has'nt any devisors beside 1 and it self .
}

int gcd(int a , int b ){
	while ( b != 0){ 
		int temp = b; 
		b = a%b ; 
		a = temp ; // a got the value of b 
	}
	return a ;  // return last devisor .
}
int lcm (int a , int b){
	return (a*b)/gcd(a, b ); // as we have a formula to calculte lcm using gcd .
}

long factorial(int num){
	int i;
	if (num<0){
		printf("ERROR! \n");
		return -1; // -1 as a sign that there's an error.
	}
	else if (num==0 || num==1){
		return 1;
	}
	else{
		long result =1 ;
		for (i=2 ; i <= num ; i++){
			result *=i ;
		}
		return result;
		}
}

bool isEven(int num){
	if (num%2 == 0 ){
		return true; // if the number is divisible by 2 it's even - return true.
	}
	else { 
	return false; // else it's odd .
	}
}

/* 
bool isEven(int num){
return num%2 == 0;
}
*/

//intermediate

void primeFactors(int num) {
    int i;
    printf("All prime factors of %d are:\n", num);
    for (i = 2; i * i <= num; i++) {
        while (isPrime(i) && num % i == 0) { // Check if i is a prime and divides num
            printf("%d, ", i); // Print the prime factor
            num /= i;          // Reduce num
        }
    }
    if (num > 1) { // If there's any prime factor greater than sqrt(num)
        printf("%d", num);
    }
    printf("\n");
}

bool isArmstrong(int num){
	int s = 0 ;
	int n = num ;
	int i = num , digits = 0 ;
	while (i>0){
		i/=10;
		digits+=1;
	} 
	while (num != 0){
		s = s + pow(num%10 ,digits); // the sum of digits if the number while each digit is to the power of 3 / using the lib <math.h>
		num = num/10;
	}
	if (s == n ){
		return true ; // as it an armstrong number.
		}
	else { 
	return false ;
	}
}// or return s==n ( instead of all of the conditional if)
void fibonacciSeries(int n){
	int a=0 , b=1 , j , i ;  // we assume that the first numbers in the serie are a=0 and b=1 as there is no clue in the project paper if we should put them as inputs.
	 if (n >= 1) printf("%d ", a); // Print the first term
    if (n >= 2) printf("%d ", b); // Print the second term
    for (i =3 ; i <= n ; i++){
		j = a+b ; // we reserve the sum of a+b in another variable.
			printf("%d",j);
		a = b ; // a take the value of b.
		b = j ; // b take the value of the sum of a and b .
	}
	printf(" ");
}

int sumDivisors(int num){
	int i , s=0 ;
	for (i = 1 ; i < num ; i++){
		if (num%i==0){
			s+= i ; // if i is a devisor we add it to the sum.
		}
	}
	return s ;
}

bool isPerfect(int num){
return sumDivisors(num)==num ; // using the function sumOfDevisors(int num) 
}

bool isMagic(int num){
return SumOfDigits(SumOfDigits(num))==1;
}

bool isAutomorphic(int num){
	int i = num , digits = 0 , lastdigits;
	while (i>0){
		i/=10;
		digits+=1;
	} 
	lastdigits = (num*num) % (int) pow(10 , digits);
	// we put (int) because the operator % work only with integers , and the result for pow is double .
	return lastdigits==num;
}

//advanced 

void toBinary(int num){
    // Base case: if the number is 0, print 0 and stop the recursion
    if (num == 0) {
        return;
    }
    // Recursive call to divide the number and print binary in the correct order
     toBinary(num / 2);  // Recursive call for the higher bits
    // Print the remainder when divided by 2 (this is the current bit)
    printf("%d", num % 2);
}

bool isNarcissistic(int num) {
    int original = num, sum = 0, digits = 0, digit;
    int temp = num;
    // Count the number of digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Calculate the sum of each digit raised to the power of digits
    while (num > 0) {
        digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
}
    return sum == original;
}

double sqrtApprox(int num) {
    double x = num; // Initial guess
    double epsilon=0.0000001; // Desired accuracy
    double sqrt;
    // Perform the Babylonian method
    while (fabs(x * x - num) >= epsilon) {
        sqrt = 0.5 * (x + num / x); // using the formula 
        x = sqrt;
    }

    return sqrt;
}

double power(int base, int exp) {
    double result = 1;
    int i;
    for ( i = 1; i <= exp; i++) {
        result *= base; // the number is multiplied by itself exp times.
    }
    return result;
}
bool isHappy(int num){

  // Loop to check if the number is happy
    while (num != 1 && num != 4) {  //we put 4 to stop the loop at some point for unhappy numbers 
      int sum = 0;
        int digit;
        // Calculate the sum of the squares of the digits
        while (num > 0) {
            digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
    num =sum ; // num take the value of sum 
}
return num == 1 ;
}

bool isAbundant(int num){
	int i, s=0 ;
	for(i=1;i < num ; i++){ // form i =0 until i<num to avoid adding the number itself to the sum
		if (num%i==0){ // if i is a devisor we add it to the sum .
			s+=i;
		}
	}
	return s > num ; // if s<num it return false , else it return true. 
	
}

bool isDeficient(int num){// same code as the code of isAbundant , but not the result.
	int i, s=0 ;
	for(i=1;i < num ; i++){
		if (num%i==0){
			s+=i; //adding the devisor to the sum of devisors.
		}
	}
	return s < num ; // if s<num it return true , else it return false.
	
}

int sumEvenFibonacci(int n){
	
	int a=0 , b=1 , j , i , s=0 ; 
    for (i =1 ; i <= n ; i++){
    	if(isEven(b)==true){ // using isEven function to checks if b is even or not
    		s+=b ;
		}
		j = a+b ; 
		a = b ; // a take the value of b.
		b = j ; // b take the value of the sum of a and b .
	}
return s;
}

bool isHarshad(int num){  // using the function SumOfDigits(int num) , we check if the num is divisible by the sum of its digits 
	return num%SumOfDigits(num)==0;
}

unsigned long catalanNumber(int n){ // using the formula (n*2)!/n!*(n+1)! and the function long factorial(int num)
 return factorial(2 * n) / (factorial(n) * factorial(n + 1));
}

void pascalTriangle(int n) {
	int line , space , i ;
    for ( line = 0 ; line < n; line++) {
        int value = 1;   // print 1 in all lines 

    
        for ( space = 0; space < n - line - 1 ; space++) { //print a space to bouild our teiangle
            printf(" ");
        }
        for ( i = 0; i <= line; i++) {
            printf("%d ", value); // print the value
            
            value = value * (line - i) / (i + 1); //using a formula to create the pascal triangle 
        }
        printf("\n"); // we move to the next line after finished the loop for 
    }
}

unsigned long bellNumber(int n){
 unsigned long current = 1, previous = 1, temp;
	int i ,j;
    for(i = 1; i <= n; i++){
        temp = current;
        for ( j = 1; j < i; j++) {
            temp = temp + previous;
            previous = temp - previous;
        }
        current = temp;
    }
    return current;
} 
/*
unsigned long bellNumber(int n, int k) {
    if (n == 0) return 1; 
    if (k == n) return 0; 
    return bellNumber(n - 1, 0) + bellNumber(n - 1, k + 1) * (n - 1 - k) / (k + 1);
}
*/


bool isKaprekar(int num){
    if (num == 1) return 1; // Special case for 1
    long long square = (long long)num * num;

    // Determine the number of digits in the square
    int numDigits = 0;
    long long temp = square;
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    // Split the square and check partitions
    long long divisor = 1;
    int i;
    for ( i = 1; i < numDigits; i++) {
        divisor *= 10;
        long long left = square / divisor;
        long long right = square % divisor;

        if (right != 0 && left + right == num) {
            return true; // Kaprekar number
        }
    }
    return false; // Not a Kaprekar number
}
bool isSmith(int num){
	if (isPrime(num)==true){ //for primes numbers we return false .( using the function bool isPrime(int num)
		return false ;
	}

	int i , sumfactors=0 , temp=num;
	for (i=2 ; i*i<=num ; i++){
		while ( temp%i==0){
		sumfactors+= SumOfDigits(i);
        }
    }
    return true;
}
int sumOfPrimes(int n) {
    int i , sum = 0;
    for ( i = 2; i <= n; i++) { // Start from 2 because 1 is not prime
        if (isPrime(i)) {
            sum += i; // Add the prime number to the sum
        }
    }
    return sum;
}

//operations on arrays:
// basic :
void initializeArray(int arr[], int size, int value){
	int i;
	for(i=0; i<size ; i++){
		arr[i]=value;
	}
}

void printArray(int arr[], int size){
	int i;
	for(i=0; i<size ; i++){
	printf("%d",arr[i]);
	}
}

int findMax(int arr[], int size){
	int i , max ;
	max = arr[0];
	for(i=1 ; i<size ; i++){
	if(arr[i]>max){
		max= arr[i];
	}
	}
	return max;
}

int findMin(int arr[], int size){
	int i , min ;
	min = arr[0];
	for(i=1 ; i<size ; i++){
	if(arr[i]<min){
		min= arr[i];
	}
	}
	return min;
}

int sumArray(int arr[], int size){
    int i , sum=0;
    for(i=0 ; i<size ; i++){
    	sum+= arr[i];
	}
	return sum;
}

double averageArray(int arr[], int size){
return  sumArray(arr, size)/size;
}

bool isSorted(int arr[], int size){
	int i;
	if(size<=1){
		return true;
	}
	
	for (i=0; i<size-1; i++){
		if(arr[i]>arr[i+1]){
		return false;
		}
	}
	return true;
}

// intermediate array functions
void reverseArray(int arr[], int size){
	int temp , i;
	for(i=0 ; i<=size/2;i++){
		temp=arr[i];
		arr[i]=arr[size-1-i];
		arr[size-1-i]=temp;
	}
}

void countEvenOdd(int arr[], int size , int* evenCount , int* oddCount){
	*evenCount=0;
	*oddCount=0;
	int i;
	for(i=0; i<size ; i++){
		if(arr[i]%2==0){
			(*evenCount)++;
		}
		else{
			(*oddCount)++;
		}
	}
}

int secondLargest(int arr[], int size){
	 if (size < 2) {
        printf("Array must have at least two elements.\n");
        return -1; // Return -1 to indicate error
    }

    int largest = arr[0];
    int secondLargest = -1; 
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // Update second largest
            largest = arr[i];        // Update largest
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i]; 
        }
    }

    if (secondLargest == -1) {
        printf("No second largest element found (all elements might be the same).\n");
        return -1;
    }

    return secondLargest;
}

void elementFrequency(int arr[], int size){
 int i , j ;
 int visited[size]; // Array to keep track of visited elements
    for ( i = 0; i < size; i++) {
        visited[i] = 0; // Initialize as not visited
    }

    printf("Element Frequency:\n");

    for (i = 0; i < size; i++) {
        if (visited[i] == 0) { 
            int count = 1; 
            for ( j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    visited[j] = 1; // Mark as visited
                }
            }
            printf("%d occurs %d times.\n", arr[i], count);
        }
    }
}
int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0;
   
    int i , j = 0; // Index for the next unique element
    for ( i = 1; i < size; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1; // New size of the array
}
int binarySearch(int arr[], int size, int target) { // the array should be sorted
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;    // Target found
        if (arr[mid] < target) left = mid + 1; // Target in the right half
        else right = mid - 1;                  // Target in the left half
    }
    return -1; // Target not found
}

int linearSearch(int arr[], int size, int target) {
    int i;
    for ( i = 0; i < size; i++) {
        if (arr[i] == target) return i; // Target found
    }
    return -1; // Target not found
}

void leftShift(int arr[], int size, int rotations) {
    rotations = rotations % size; // Handle cases where rotations > size
    int temp[rotations] , i;
    
    // Store the first 'rotations' elements
    for (i = 0; i < rotations; i++) {
        temp[i] = arr[i];
    }

    // Shift the remaining elements to the left
    for (i = rotations; i < size; i++) {
        arr[i - rotations] = arr[i];
    }

    // Place the saved elements at the end
    for (i = 0; i < rotations; i++) {
        arr[size - rotations + i] = temp[i];
    }
}

void rightShift(int arr[], int size, int rotations) {
    rotations = rotations % size; // Handle cases where rotations > size
    int i , temp[rotations];

    // Store the last 'rotations' elements
    for ( i = 0; i < rotations; i++) {
        temp[i] = arr[size - rotations + i];
    }

    // Shift the remaining elements to the right
    for ( i = size - 1; i >= rotations; i--) {
        arr[i] = arr[i - rotations];
    }

    // Place the saved elements at the beginning
    for ( i = 0; i < rotations; i++) {
        arr[i] = temp[i];
    }
}


// sorting algorithms 
void bubbleSort(int arr[], int size){
	
int i ,j , temp;
   for (i=0 ; i<size ; i++){
   	 for (j=0 ; j<size-1 ; j++){
   	 	if(arr[j]>arr[j+1]){
   	 		temp=arr[j];
   	 		arr[j]=arr[j+1];
   	 		arr[j+1]=temp;
			}
		}
   }
}

void selectionSort(int arr[], int size){
	int min , i ,j , temp;
	for (i=0 ; i<size ; i++){
		min=i;
		for(j=i+1 ; j<size ; j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if (min != i){
			temp = arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
}

void insertionSort(int arr[], int size){
 int i , j , temp;
 for(i=1 ; i<size ; i++){
 	j=i;
 	while(j>0 && arr[j-1]>arr[j]){
 		temp = arr[j];
		arr[j]=arr[j-1]; 
		arr[j-1]=temp;
		 j=j-1; 
	 }
 }
}
//add
void inputArray(int arr[], int size) {
    int i;
    printf("Enter %d values for the array:\n", size);
    for (i = 0; i < size; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

/*
//advanced  array functions
int findMissingNumber(int arr[], int size){
	
	int i;
	for (i=0 ; i< size; i++){
		if (arr[i]!=i){
			return i;
		}
	}
}

void findPairsWithSum(int arr[], int size, int sum){
	int i, j;
	for(i=0; i<size ; i++){
		for (j=i; j<size;j++){
			if(arr[i]+arr[j]==sum){
				printf("%d and %d \n", arr[i] , arr[j]);
			}
		}
	} 	
}

void findSubArrayWithSum(int arr[], int size , int sum){
	
} 
*/

void printMainMenu() {
    printf("\n----- Main Menu -----\n");
    printf("1. Array Functions\n");
    printf("2. Number Functions\n");
    printf("0. Exit\n");
}

void printArrayMenu() {
    printf("\n----- Array Functions Menu -----\n");
    printf("1. Initialize Array\n");
    printf("2. Print Array\n");
    printf("3. Find Maximum Value\n");
    printf("4. Find Minimum Value\n");
    printf("5. Sum of Array Elements\n");
    printf("6. Average of Array\n");
    printf("7. Check if Array is Sorted\n");
    printf("8. Reverse Array\n");
    printf("9. Count Even and Odd Elements\n");
    printf("10. Find Second Largest Element\n");
    printf("11. Frequency of Elements\n");
    printf("12. Remove Duplicates\n");
    printf("13. Binary Search\n");
    printf("14. Linear Search\n");
    printf("15. Left Shift Array\n");
    printf("16. Right Shift Array\n");
    printf("17. Bubble Sort\n");
    printf("18. Selection Sort\n");
    printf("19. Insertion Sort\n");
    printf("20. input array\n");
    printf("0. Exit\n");
}
void printNumberMenu() {
    printf("\nSelect an operation:\n");
    printf("1. Sum of Digits\n");
    printf("2. Reverse Number\n");
    printf("3. Palindrome Check\n");
    printf("4. Prime Number Check\n");
    printf("5. GCD\n");
    printf("6. LCM\n");
    printf("7. Factorial\n");
    printf("8. Even Number Check\n");
    printf("9. Prime Factors\n");
    printf("10. Armstrong Number Check\n");
    printf("11. Fibonacci Series\n");
    printf("12. Perfect Number Check\n");
    printf("13. Magic Number Check\n");
    printf("14. Automorphic Number Check\n");
    printf("15. Convert to Binary\n");
    printf("16. Narcissistic Number Check\n");
    printf("17. Square Root Approximation\n");
    printf("18. Power Calculation\n");
    printf("19. Happy Number Check\n");
    printf("20. Abundant Number Check\n");
    printf("21. Deficient Number Check\n");
    printf("22. Sum of Even Fibonacci Numbers\n");
    printf("23. Harshad Number Check\n");
    printf("24. Catalan Number Calculation\n");
    printf("25. Pascal Triangle\n");
    printf("26. Bell Number Calculation\n");
    printf("27. Kaprekar Number Check\n");
    printf("28. Smith Number Check\n");
    printf("29. Sum of Primes\n");
    printf("30. Sum of Divisors\n");
    printf("0. Exit\n");
}

int main() {
    int choice, subChoice;
    int arr[100];
    int size, value, target, rotations, evenCount, oddCount, num1, num2 , num , n;
    
    while(1) {
        printMainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Array Functions Menu
                while(1) {
                    printArrayMenu();
                    printf("\nEnter your choice: ");
                    scanf("%d", &subChoice);

                    if(subChoice == 0) break; // Go back to Main Menu

                    switch(subChoice) {
                        case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                if (size <= 0 || size > 100) {
                    printf("Invalid size. Please enter a size between 1 and 100.\n");
                    break;
                }
                printf("Enter the value to initialize the array with: ");
                scanf("%d", &value);
                initializeArray(arr, size, value);
                printf("Array initialized successfully.\n");
                break;

            case 2:
                if (size > 0) {
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 3:
                if (size > 0) {
                    printf("Maximum Value: %d\n", findMax(arr, size));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 4:
                if (size > 0) {
                    printf("Minimum Value: %d\n", findMin(arr, size));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 5:
                if (size > 0) {
                    printf("Sum of Array Elements: %d\n", sumArray(arr, size));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 6:
                if (size > 0) {
                    printf("Average of Array: %.2f\n", averageArray(arr, size));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 7:
                if (size > 0) {
                    if (isSorted(arr, size)) {
                        printf("Array is sorted.\n");
                    } else {
                        printf("Array is not sorted.\n");
                    }
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 8:
                if (size > 0) {
                    reverseArray(arr, size);
                    printf("Array reversed successfully.\n");
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 9:
                if (size > 0) {
                    countEvenOdd(arr, size, &evenCount, &oddCount);
                    printf("Even Count: %d, Odd Count: %d\n", evenCount, oddCount);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 10:
                if (size > 0) {
                    printf("Second Largest Element: %d\n", secondLargest(arr, size));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 11:
                if (size > 0) {
                    elementFrequency(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 12:
                if (size > 0) {
                    size = removeDuplicates(arr, size);
                    printf("Duplicates removed successfully.\n");
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 13:
                if (size > 0) {
                    printf("Enter the target for binary search: ");
                    scanf("%d", &target);
                    printf("Binary Search Index: %d\n", binarySearch(arr, size, target));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 14:
                if (size > 0) {
                    printf("Enter the target for linear search: ");
                    scanf("%d", &target);
                    printf("Linear Search Index: %d\n", linearSearch(arr, size, target));
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 15:
                if (size > 0) {
                    printf("Enter the number of rotations for left shift: ");
                    scanf("%d", &rotations);
                    leftShift(arr, size, rotations);
                    printf("Array left-shifted successfully.\n");
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 16:
                if (size > 0) {
                    printf("Enter the number of rotations for right shift: ");
                    scanf("%d", &rotations);
                    rightShift(arr, size, rotations);
                    printf("Array right-shifted successfully.\n");
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 17:
                if (size > 0) {
                    bubbleSort(arr, size);
                    printf("Array sorted using Bubble Sort.\n");
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 18:
                if (size > 0) {
                    selectionSort(arr, size);
                    printf("Array sorted using Selection Sort.\n");
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;

            case 19:
                if (size > 0) {
                    insertionSort(arr, size);
                    printf("Array sorted using Insertion Sort.\n");
                    printArray(arr, size);
                } else {
                    printf("Array is empty. Please initialize the array first.\n");
                }
                break;
                case 20:
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid size. Please enter a size between 1 and 100.\n");
        break;
    }
    inputArray(arr, size);
    printf("Array values entered successfully.\n");
    break;

            
                        default:
                            printf("Invalid choice.\n");
                    }
                }
                break;

            case 2: // Number Functions Menu
                while(1) {
                    printNumberMenu();
                    printf("\nEnter your choice: ");
                    scanf("%d", &subChoice);

                    if(subChoice == 0) break; // Go back to Main Menu

                    switch(subChoice) {
                        case 1:
                            printf("Enter a number: ");
                            scanf("%d", &num1);
                            printf("Sum of Digits: %d\n", SumOfDigits(num1));
                            break;
                        case 2:
                            printf("Enter a number: ");
                            scanf("%d", &num1);
                            printf("Reversed Number: %d\n", reverseNumber(num1));
                            break;
                        case 3:
                            printf("Enter a number: ");
                            scanf("%d", &num1);
                            if(isPalindrome(num1))
                                printf("It is a palindrome.\n");
                            else
                                printf("It is not a palindrome.\n");
                            break;
                        case 4:
                            printf("Enter a number: ");
                            scanf("%d", &num1);
                            if(isPrime(num1))
                                printf("It is a prime number.\n");
                            else
                                printf("It is not a prime number.\n");
                            break;
                        case 5: // GCD
                            printf("Enter two numbers: ");
                            int a, b;
                            scanf("%d %d", &a, &b);
                            printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
                            break;

                        case 6: // LCM
                            printf("Enter two numbers: ");
                            scanf("%d %d", &a, &b);
                printf("LCM of %d and %d is %d\n", a, b, lcm(a, b));
                break;

            case 7: // Factorial
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Factorial of %d is %ld\n", num, factorial(num));
                break;

            case 8: // Even Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isEven(num)) {
                    printf("%d is an Even number.\n", num);
                } else {
                    printf("%d is an Odd number.\n", num);
                }
                break;

            case 9: // Prime Factors
                printf("Enter a number: ");
                scanf("%d", &num);
                primeFactors(num);
                break;

            case 10: // Armstrong Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isArmstrong(num)) {
                    printf("%d is an Armstrong number.\n", num);
                } else {
                    printf("%d is not an Armstrong number.\n", num);
                }
                break;

            case 11: // Fibonacci Series
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                fibonacciSeries(n);
                break;

            case 12: // Perfect Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isPerfect(num)) {
                    printf("%d is a Perfect number.\n", num);
                } else {
                    printf("%d is not a Perfect number.\n", num);
                }
                break;

            case 13: // Magic Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isMagic(num)) {
                    printf("%d is a Magic number.\n", num);
                } else {
                    printf("%d is not a Magic number.\n", num);
                }
                break;

            case 14: // Automorphic Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isAutomorphic(num)) {
                    printf("%d is an Automorphic number.\n", num);
                } else {
                    printf("%d is not an Automorphic number.\n", num);
                }
                break;

            case 15: // Convert to Binary
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Binary representation of %d: ", num);
                toBinary(num);
                printf("\n");
                break;

            case 16: // Narcissistic Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isNarcissistic(num)) {
                    printf("%d is a Narcissistic number.\n", num);
                } else {
                    printf("%d is not a Narcissistic number.\n", num);
                }
                break;

            case 17: // Square Root Approximation
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Approximate square root of %d: %.6f\n", num, sqrtApprox(num));
                break;

            case 18: // Power Calculation
                printf("Enter base and exponent: ");
                int base, exp;
                scanf("%d %d", &base, &exp);
                printf("%d raised to the power of %d is %.6f\n", base, exp, power(base, exp));
                break;

            case 19: // Happy Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isHappy(num)) {
                    printf("%d is a Happy number.\n", num);
                } else {
                    printf("%d is not a Happy number.\n", num);
                }
                break;

            case 20: // Abundant Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isAbundant(num)) {
                    printf("%d is an Abundant number.\n", num);
                } else {
                    printf("%d is not an Abundant number.\n", num);
                }
                break;

            case 21: // Deficient Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isDeficient(num)) {
                    printf("%d is a Deficient number.\n", num);
                } else {
                    printf("%d is not a Deficient number.\n", num);
                }
                break;

            case 22: // Sum of Even Fibonacci Numbers
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                printf("Sum of even Fibonacci numbers: %d\n", sumEvenFibonacci(n));
                break;

            case 23: // Harshad Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isHarshad(num)) {
                    printf("%d is a Harshad number.\n", num);
                } else {
                    printf("%d is not a Harshad number.\n", num);
                }
                break;

            case 24: // Catalan Number Calculation
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Catalan number for %d is %lu\n", n, catalanNumber(n));
                break;

            case 25: // Pascal Triangle
                printf("Enter the number of rows: ");
                scanf("%d", &n);
                pascalTriangle(n);
                break;

            case 26: // Bell Number Calculation
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Bell number for %d is %lu\n", n, bellNumber(n));
                break;

            case 27: // Kaprekar Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isKaprekar(num)) {
                    printf("%d is a Kaprekar number.\n", num);
                } else {
                    printf("%d is not a Kaprekar number.\n", num);
                }
                break;

            case 28: // Smith Number Check
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isSmith(num)) {
                    printf("%d is a Smith number.\n", num);
                } else {
                    printf("%d is not a Smith number.\n", num);
                }
                break;

            case 29: // Sum of Primes
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Sum of primes up to %d is %d\n", n, sumOfPrimes(n));
                break;

            case 30: // Sum of Divisors
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Sum of divisors of %d is %d\n", num, sumDivisors(num));
                break;

            case 0: // Exit
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");

}
}
}
}
}
