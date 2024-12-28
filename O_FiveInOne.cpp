#include <iostream>
using namespace std;

int maxNum(int array[], int count)
{

    int max = array[0];

    for (int i = 0; i < count; i++)
    {
        if (array[i] >= max)
        {
            max = array[i];
        }
    }

    return max;
}
int minNum(int array[], int count)
{
    int min = array[0];

    for (int i = 0; i < count; i++)
    {
        if (array[i] <= min)
        {
            min = array[i];
        }
    }
    return min;
}
int num_of_Prime(int array[], int count)
{

    int count_Prime = 0;

    for (int i = 0; i < count; i++)
    {
        bool booll = true;

        if (array[i] <= 1)
            continue;

        for (int j = 2; j < array[i] / 2; j++)
        {

            if (array[i] % j == 0)
            {
                booll = false;
                break;
            }
        }
        if (booll == true)
        {
            count_Prime++;
        }
    }

    return count_Prime;
}

int num_of_Palindrome(int array[], int count)
{

    int count_Palindrome = 0;

    for (int i = 0; i < count; i++)
    {
        int Rev_num = 0;
        int temp = array[i];
        while (temp > 0)
        {

            Rev_num = Rev_num * 10 + (temp % 10);
            temp = temp / 10;
        }

        if (array[i] == Rev_num)
        {
            count_Palindrome++;
        }
    }

    return count_Palindrome;
}

int num_Denominators(int array[], int count)
{

    int ArrayNumDen[count];

    for (int i = 0; i < count; i++)
    {
        int count_Denominators = 0;
        for (int j = 1; j <= array[i]; j++)
        {
            if (array[i] % j == 0)
            {
                count_Denominators++;
            }
        }

        ArrayNumDen[i] = count_Denominators;
    }

    int max = ArrayNumDen[0];
    int NumMaxDen = array[0];

    for (int i = 0; i < count; i++)
    {
        if (ArrayNumDen[i] > max)
        {
            max = ArrayNumDen[i];
            NumMaxDen = array[i];
        }

        else if (ArrayNumDen [i] == max)
        {
            if (array[i] > NumMaxDen)
            {
                NumMaxDen = array[i];
            }
            
        }
        
    }
    return NumMaxDen;
}

int main()
{

int n;
cin>>n;
int array[n];
for (int i = 0; i < n; i++)
{
    cin>>array[i];
}

cout<<"The maximum number : "<<maxNum(array,n)<<endl;
cout<<"The minimum number : "<<minNum(array,n)<<endl;
cout<<"The number of prime numbers : "<<num_of_Prime(array,n)<<endl;
cout<<"The number of palindrome numbers : "<<num_of_Palindrome(array,n)<<endl;
cout<<"The number that has the maximum number of divisors : "<<num_Denominators(array,n)<<endl;


}