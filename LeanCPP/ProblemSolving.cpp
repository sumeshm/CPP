#include "ProblemSolving.h"
#include "StringProblems.h"
#include <iomanip>

ProblemSolving::ProblemSolving()
{
}

ProblemSolving::~ProblemSolving()
{
    //dtor
}

int ProblemSolving::printFibonacchiRecurse(int p_max, int p_current)
{
    int l_retVal = 0;
    if (p_current < 2)
    {
        l_retVal = 1;
    }
    else
    {
        l_retVal = printFibonacchiRecurse(p_max, p_current -1) + printFibonacchiRecurse(p_max, p_current - 2);
    }

    cout << ".....[" << p_current << "]=" << l_retVal << endl;
    return l_retVal;
}

void ProblemSolving::printFibonacchi(int p_approach)
{
    cout << "Fibonacchi Series - Memoize: enter a number" << endl;
    int l_fib = 0;
    int l_max = 0;
    cin >> l_max;
    if (l_max < 0)
    {
        cout << l_max << " is not valid, enter a number greater than zero" << endl;
    }

    if (p_approach == FIB_MEMOISE)
    {
        int l_fibArray[l_max];

        for (int l_count = 0; l_count < (l_max + 1); l_count++)
        {
            if (l_count < 2)
            {
                l_fib = 1;
            }
            else
            {
                l_fib = l_fibArray[l_count - 1] + l_fibArray[l_count - 2];
            }

            cout << ".....[" << l_count << "]=" << l_fib << endl;
            l_fibArray[l_count] = l_fib;
        }
    }
    else if (p_approach == FIB_RECURSE)
    {
        l_fib = printFibonacchiRecurse(l_max, l_max);
    }

    cout << "fib[" << l_max << "]=" << l_fib << endl;
}

void ProblemSolving::towerOfHanoi(int p_count, Tower& p_towerA, Tower& p_towerB, Tower& p_towerC)
{
    if (p_count > 0)
    {
        // step-1: move (m-1) rings from A to B, recursively
        // these are all the rings sitting on top of the bottom ring
        towerOfHanoi(p_count - 1, p_towerA, p_towerC, p_towerB);

        // step-2: move bottom ring from A to C
        p_towerA.removeDisc(p_count);
        p_towerC.addDisc(p_count);
        printTowers(p_towerA, p_towerB, p_towerC);

        // step-3: move (m-1) back to on top of bottom ring, i.e, from B to C recursively
        towerOfHanoi(p_count - 1, p_towerB, p_towerA, p_towerC);
    }
}

void ProblemSolving::printTowers(Tower& p_towerA, Tower& p_towerB, Tower& p_towerC)
{
    string l_msg;
    priority_queue<Tower, vector<Tower>, Tower> l_queue;

    l_queue.push(p_towerA);
    l_queue.push(p_towerB);
    l_queue.push(p_towerC);

    while (!l_queue.empty())
    {
        Tower l_tower = l_queue.top();
        l_msg += "\t\t" + l_tower.toString();
        l_queue.pop();
    }

    cout << setw(15) << l_msg << endl;
}


void ProblemSolving::learnArrays()
{
    int sizeM = 0;
    int sizeN = 0;
    cout << "Enter value of M and N: ";
    cin >> sizeM >> sizeN;
    cout << endl;

    // create an array of pointers (double*) of size M
    double** l_dataArray = new double*[sizeM];
    for (int l_idx = 0; l_idx < sizeM; ++l_idx)
    {
        // initialize each index with a double-array of size N
        l_dataArray[l_idx] = new double[sizeN];
    }

    // clean-up
    for (int l_idx = 0; l_idx < sizeM; ++l_idx)
    {
        // delete the double-array at each index
        delete[] l_dataArray[l_idx];
    }

    // delete the pointer array
    delete[] l_dataArray;
}


void ProblemSolving::funWithBits()
{
    int a = 8;
    cout << "data=" << a << endl;
    cout << "\t data * 2  (a << 1) =" << setw(5) << (a << 1) << endl;
    cout << "\t data / 2  (a >> 1) =" << setw(5) << (a >> 1) << endl;
    cout << "\t data * 10 (a << 3 + a << 1) =" << setw(5) << ((a << 3) + (a << 2)) << endl;
}

void ProblemSolving::reverseNumber()
{
    int input = 0;
    int div = 1;
    int output = 0;

    cout << "Enter the number to reverse:" << endl;
    cin >> input;
    while (input > div)
    {
        output = (output * 10) + ((input / div) % 10);
        div = (div << 3)  +  (div << 1);                    // div = div * 10;zxz
    }
    cout << "Reveres of " << input << " = " << output << endl;
}

int ProblemSolving::findMin(int* p_arr, int p_first, int p_last)
{
    if (p_last < p_first)
    {
        return p_arr[0];                // index has passed each other, return first element
    }
    if (p_last == p_first)
    {
        return p_arr[p_first];          // array has only one element left
    }

    int mid = p_first + (p_last - p_first)/2;

    if (mid < p_last && p_arr[mid + 1] < p_arr[mid])
    {
        return p_arr[mid + 1];           // element next to mid is minimum
    }

    // handle duplicates
    if (p_arr[p_first] == p_arr[mid] || p_arr[p_last] == p_arr[mid])
    {
        return min(findMin(p_arr, p_first, mid-1), findMin(p_arr, mid+1, p_last));
    }

    if (mid > p_first && p_arr[mid] < p_arr[mid - 1])
    {
        return p_arr[mid];              // mid is the minimum
    }

    if (p_arr[p_last] > p_arr[mid])
    {
        return findMin(p_arr, p_first, mid-1);      // search before mid
    }
    else
    {
        return findMin(p_arr, mid+1, p_last);       // search after mid
    }
}

void ProblemSolving::minOfRotatedArray()
{
    int lenght = 0;
    int arr1[] =  {5, 6, 1, 2, 3, 4};
    int arr2[] =  {1, 1, 0, 1};
    int arr3[] =  {1, 1, 2, 2, 3};
    int arr4[] =  {3, 3, 3, 4, 4, 4, 4, 5, 3, 3};
    int arr5[] =  {2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2};
    int arr6[] =  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1};
    int arr7[] =  {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2};
    int arr8[] =  {0, 1, 2, 3, 4, 5};
    int arr9[] =  {5, 4, 3, 2, 1, 0};
    int arr10[] =  {0, 0, 0, 0};

    lenght = sizeof(arr1)/sizeof(arr1[0]);
    cout << "{5, 6, 1, 2, 3, 4} = " << findMin(arr1, 0, lenght-1) << endl;

    lenght = sizeof(arr2)/sizeof(arr2[0]);
    cout << "{1, 1, 0, 1} = " << findMin(arr2, 0, lenght-1) << endl;

    lenght = sizeof(arr3)/sizeof(arr3[0]);
    cout << "{1, 1, 2, 2, 3} = " << findMin(arr3, 0, lenght-1) << endl;

    lenght = sizeof(arr4)/sizeof(arr4[0]);
    cout << "{3, 3, 3, 4, 4, 4, 4, 5, 3, 3} = " << findMin(arr4, 0, lenght-1) << endl;

    lenght = sizeof(arr5)/sizeof(arr5[0]);
    cout << "{2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2} = " << findMin(arr5, 0, lenght-1) << endl;

    lenght = sizeof(arr6)/sizeof(arr6[0]);
    cout << "{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1} = " << findMin(arr6, 0, lenght-1) << endl;

    lenght = sizeof(arr7)/sizeof(arr7[0]);
    cout << "{2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2} = " << findMin(arr7, 0, lenght-1) << endl;

    lenght = sizeof(arr8)/sizeof(arr8[0]);
    cout << "{0, 1, 2, 3, 4, 5} = " << findMin(arr8, 0, lenght-1) << endl;

    lenght = sizeof(arr9)/sizeof(arr9[0]);
    cout << "{5, 4, 3, 2, 1, 0} = " << findMin(arr9, 0, lenght-1) << endl;

    lenght = sizeof(arr10)/sizeof(arr10[0]);
    cout << "{0, 0, 0, 0} = " << findMin(arr10, 0, lenght-1) << endl;
}

int ProblemSolving::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    string l_msg = p_msg + "PROBLEM_SOLVING";
    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\n" << l_msg << endl;
        cout << "Welcome to Problem Solving!" << endl;
        cout << "---------------------------------" << endl;
        cout << "0. Print Fibonacchi Series - Memoize" << endl;
        cout << "1. Print Fibonacchi Series - Recursion" << endl;
        cout << "2. Tower of Hanoi" << endl;
        cout << "3. Initialize N dimensional array" << endl;
        cout << "4. BIT operations" << endl;
        cout << "5. Reverse a Number" << endl;
        cout << "6. Min-item of sorted ROTATED array" << endl;
        cout << "7. " << endl;
        cout << "8. " << endl;
        cout << "9. STRING Problems sub-menu" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '0':
            {
                printFibonacchi(FIB_MEMOISE);
                break;
            }
        case '1':
            {
                printFibonacchi(FIB_RECURSE);
                break;
            }
        case '2':
            {
                int l_rings = 0;
                cout << "Enter the number of rings:" << endl;
                cin >> l_rings;
                Tower l_towerA(1, l_rings);
                Tower l_towerB(2);
                Tower l_towerC(3);
                printTowers(l_towerA, l_towerB, l_towerC);

                towerOfHanoi(l_rings, l_towerA, l_towerB, l_towerC);
                break;
            }
        case '3':
            {
                learnArrays();
                break;
            }
        case '4':
            {
                funWithBits();
                break;
            }
        case '5':
            {
                reverseNumber();
                break;
            }
        case '6':
            {
                minOfRotatedArray();
                break;
            }
        case '9':
            {
                StringProblems l_stringProblems;
                l_retVal = l_stringProblems.printOptions(l_msg + " <> ");
                l_feedBack = l_retVal;
                break;
            }
        case 'b':
            l_retVal = 0;
            break;
        case 'q':
            l_retVal = 0;
            l_feedBack = 0;
            break;
        default:
            cout << "'" << l_data[0] << "' is an invalid choice.....try again" << endl;
            break;
        }

        cout << endl;
    }

    return l_feedBack;
}

