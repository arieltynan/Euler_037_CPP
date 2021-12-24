// Euler_037_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int removeFirstDigit(int n)
{
    if (n < 10) return 0;

    else return n % 10 + removeFirstDigit(n / 10) * 10;
}
 
bool primeCheck(int temp, vector<int> v)
{
    bool valid = true;
    while (temp != 0) //separates ints into digits
    {
        if (bool exists = find(begin(v), end(v), temp) != end(v) == false)
        {
            valid = false;
            break;
        }
        temp /= 10;
    }
    return valid;
}

bool primeCheckRev(int temp, vector<int> v)
{
    bool valid = true;
    while (temp != 0) //separates ints into digits
    {
        if (bool exists = find(begin(v), end(v), temp) != end(v) == false)
        {
            valid = false;
            break;
        }
        temp = removeFirstDigit(temp);
    }
    return valid;
}


int main()
{
    // Prime seive adopted from Euler_035_CPP
    vector<int> primes;
    int total = 0; //sum of valid primes
    int n = 1000000; //primes less than n (1000000)
    primes.push_back(2);
    for (int i = 3; i < n; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
        }
    } // end for loop, prime search

    //Primes without even numbers or fives
    vector<int> pVect; //final vector of primes without even numbers
    for (int i = 0; i < primes.size(); i++) //i = 4 to skip 2,3,5, and 7
    {
        bool evens = false;
        int pTemp = primes[i];
        while (pTemp != 0) //separates ints into digits
        {
            //cout << pTemp << " ";
            pTemp /= 10;

            if ((pTemp % 2 == 0 && pTemp == 23) && pTemp != 0) // 23 only valid number with a 2; an exception
            {
                evens = true;
                break;
            }
        }

        if (evens == false)
        {
            pVect.push_back(primes[i]);
            //cout << primes[i] << endl;
        }
    } //end for loop for prime gen
    for (int i = 0; i < pVect.size(); i++)
    {
        bool valid = true; //if false, number is not prime for all iterations
        int temp = pVect[i];




        //Check if all are prime
        if (primeCheck(temp, pVect) == true && primeCheckRev(temp, pVect) && temp > 7)
        {
            total = total + temp;
            cout << temp << endl;
        }
    }
    cout << "The sum of the 11 primes is: " << total << endl;;
        
        





        // Generate prime list
        // no primes with 2,3,5,6,8,0
    // for each prime
        // Solve initial direction
           // Series of %10 and /10 and checking all resulting values against prime list
        // Reverse number 
              /*  while (n != 0) {
                    remainder = n % 10;
                    reversedNumber = reversedNumber * 10 + remainder;
                    n /= 10;
                } */    
             // Series of %10 and /10 and checking all resulting values against prime list
}

