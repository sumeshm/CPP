#include "PayPal.h"
#include <set>
#include <stdlib.h>


set<void*> memData;
/*
void* operator new(size_t s, const char *file, int line)
{
    void* mem = malloc(s);
    memData.insert(mem);
    cout << "--> mem_new :" << mem << " @ " << file << "::" << line << ": " << s << " bytes" << endl;

    //if (!mem) puts("out");
    return mem;
}

void operator delete(void* mem)
{
    cout << "--> mem_del @ " << mem << " : " << sizeof(mem) << " bytes" << endl;
    memData.erase(mem);
    free(mem);
}

#define new new(__FILE__, __LINE__)
*/

void PayPal::memoryTrcakerDemo()
{
    int* d1 = new int();
    int* d2 = new int();

    delete d1;

    for(auto itr = memData.begin(); itr != memData.end(); itr++)
    {
        cout << "MemLeak: " << *itr << endl;
    }

    cout << endl;
}


void PayPal::printArr(int arr[], int n, int sum)
{
    int i = 0;
    cout << "arr= [";
    while (i < n)
    {
        cout << arr[i++];
    }
    cout << "] : n=" << n << " : sum=" << sum << endl;
}
bool PayPal::isSubsetSum (int arr[], int n, int sum)
{
    printArr(arr, n, sum);
   // Base Cases
   if (sum == 0)
   {
       cout << "TRUE" << endl;
     return true;
   }

   if (n == 0 && sum != 0)
   {
       cout << "FALSE" << endl;
     return false;
   }

   // If last element is greater than sum, then ignore it
   if (arr[n-1] > sum)
     return isSubsetSum (arr, n-1, sum);

   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element
   */
   return isSubsetSum (arr, n-1, sum) || isSubsetSum (arr, n-1, sum-arr[n-1]);
}

// Returns true if arr[] can be partitioned in two subsets of
// equal sum, otherwise false
bool PayPal::findPartiion (int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
       sum += arr[i];

    // If sum is odd, there cannot be two subsets with equal sum
    if (sum%2 != 0)
       return false;

    cout << "SUM=" << sum/2 << endl;
    // Find if there is subset with sum equal to half of total sum
    return isSubsetSum (arr, n, sum/2);
}

bool PayPal::findPartiionDy(int arr[], int n)
{
    int sum = 0;
    int i, j;

    // Caculcate sun of all elements
    for (i = 0; i < n; i++)
      sum += arr[i];

    if (sum%2 != 0)
       return false;

    bool part[sum/2+1][n+1];

    // initialize top row as true
    for (i = 0; i <= n; i++)
      part[0][i] = true;

    // initialize leftmost column, except part[0][0], as 0
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;

     // Fill the partition table in botton up manner
     for (i = 1; i <= sum/2; i++)
     {
       for (j = 1; j <= n; j++)
       {
         part[i][j] = part[i][j-1];
         cout << "[" << i <<", " << j << "] : ";
         cout << "arr[j-1]=" << arr[j-1] << " : i - arr[j-1]=" << (i - arr[j-1]) << " : ";
         if (i >= arr[j-1]) {
            cout << "part[i][j]=" << part[i][j] << " : part[i - arr[j-1]][j-1]=" << part[i - arr[j-1]][j-1] << endl;
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
         }
           cout << "\tpart[i][j]=" << part[i][j] << endl;
       }
       cout << endl;
     }

     // uncomment this part to print table
     for (i = 0; i <= sum/2; i++)
     {
       for (j = 0; j <= n; j++)
       {
           cout << "[" << i <<", " << j << "] ";
       }
       cout << endl;
       for (j = 0; j <= n; j++)
        {
            cout << " " << part[i][j] << "     ";
        }

       cout << endl;
     }

     return part[sum/2][n];
}

int PayPal::dictionaryContains(string word)
{
    cout << "dictionaryContains: " << word;
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0){
            cout << " --> YES" << endl;
           return true;
        }

    cout << " --> NO" << endl;
    return false;
}


bool PayPal::wordBreak(string str)
{
    int size = str.size();
    if (size == 0)   return true;

    // Create the DP table to store results of subroblems. The value wb[i]
    // will be true if str[0..i-1] can be segmented into dictionary words,
    // otherwise false.
    bool wb[size+1];
    //memset(wb, 0, sizeof(wb)); // Initialize all values as false.
    std::fill(wb, wb + sizeof(wb), '\0');

    cout << "wordBreak: " << str << endl;
    for (int i=1; i<=size; i++)
    {
        cout << "\nI=" << i << endl;
        // if wb[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
        if (wb[i] == false && dictionaryContains( str.substr(0, i) ))
            wb[i] = true;

        // wb[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
        if (wb[i] == true)
        {
            // If we reached the last prefix
            if (i == size) {
                     for (int i = 1; i <= size; i++)
                        cout << " " << wb[i];
                        cout << endl;
                return true;
            }

            for (int j = i+1; j <= size; j++)
            {
                cout << "J=" << j << endl;
                // Update wb[j] if it is false and can be updated
                // Note the parameter passed to dictionaryContains() is
                // substring starting from index 'i' and length 'j-i'
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i) ))
                    wb[j] = true;

                // If we reached the last character
                if (j == size && wb[j] == true){
                     for (int i = 1; i <= size; i++)
                        cout << " " << wb[i];
                        cout << endl;
                    return true;
                }
            }
        }
    }

    // Uncomment these lines to print DP table "wb[]"
     for (int i = 1; i <= size; i++)
        cout << " " << wb[i];
        cout << endl;

    // If we have tried all prefixes and none of them worked
    return false;
}

void PayPal::paypal()
{
    /*
    //int arr[] = {3, 1, 5, 9, 12};
    int arr[] = {4, 3, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiionDy(arr, n) == true)
     cout << "Can be divided into two subsets of equal sum" << endl;
  else
     cout << "Can not be divided into two subsets of equal sum" << endl;
     */

    wordBreak("ilikesamsungmango")? cout <<"Yes\n": cout << "No\n";
    //wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    //wordBreak("")? cout <<"Yes\n": cout << "No\n";
    //wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    //wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    //wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";

    // memoryTrcakerDemo();
}



