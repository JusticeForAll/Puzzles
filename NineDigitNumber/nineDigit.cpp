#include <algorithm>
#include <iostream>
#include <math.h>

int arrayToNumber(int* arr, const int size);

int main()
{
    int number[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 0;
    bool found = false;
    int numIterations = 0;
    do
    {
        ++numIterations;
        num = arrayToNumber(number, 9);
        for(int i = 9; i > 1; --i)
        {
            //++numIterations;
            if(num % i == 0)
            {
                found = true;
                num /= 10;
                continue;
            }
            else
            {
                found = false;
                break;
            }
        }
        
        if(found)
        {
            std::cout<<"Number: "<<arrayToNumber(number, 9)<<"\n";
            break;
        }
    } while(std::next_permutation(number, number + 9));
    
    std::cout<<"Number of iterations: "<<numIterations<<std::endl;
    return 0;
}

int arrayToNumber(int* arr, const int size)
{
    int result = 0;
    
    for(int i = 0; i < size; ++i)
    {
        result += pow(10, size - i - 1) * arr[i];
    }
    return result;
}