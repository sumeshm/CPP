#include <algorithm>
#include "StringProblems.h"

StringProblems::StringProblems()
{
}

StringProblems::~StringProblems()
{
    //dtor
}

int StringProblems::myAtoI()
{
    string sData = "";
    int iData = 0;
    cout << "Enter a number: " << endl;
    cin >> sData;
    for (unsigned int count = 0; count < sData.size(); count++)
    {
        int temp1 = iData;
        int temp2 = iData;
        int temp3 = temp1 << 3;
        int temp4 = temp2 << 1;

        cout << "\t temp1=" << temp3 << ", temp2=" << temp4 << endl;


        iData = (iData * 10) + sData[count] - '0';
        //iData = (iData << 3) + (iData << 1) + (sData[count] - '0');
    }


    cout << "iData=" << iData;
    return iData;
}

void StringProblems::charCombinations(char* p_data, int p_curIdx, int p_length)
{
    if (p_curIdx == p_length)
    {
        cout << p_data << endl;
    }
    else
    {
        for (int l_idx = p_curIdx; l_idx < p_length; l_idx++)
        {
            swapChar((p_data + p_curIdx), (p_data + l_idx));
            charCombinations(p_data, p_curIdx + 1, p_length);
            swapChar((p_data + p_curIdx), (p_data + l_idx));       // reset the data
        }
    }
}

string StringProblems::palindromicSubsequence(string s)
{
    const int len = s.length();
    int i = 0, j = 0, cLen = 0, maxI = 0, maxJ = 0;
    int memo[len][len];
    int subStrIdx[len];
    string retVal = "";

    // initialize the table with default values
    for (i = 0; i < len; i++)
    {
        subStrIdx[i] = 0;
        for (j = 0; j < len; j++)
        {
            memo[i][j] =  (i == j) ? 1 : 0;
        }
    }

    // memoise via len*len table
    for (cLen = 2; cLen <= len; cLen++)
    {
        int iMax = len - cLen;
        for (i = 0; i <= iMax; i++)
        {
            j = i + cLen - 1;
            if (s.at(i) == s.at(j))
            {
                // diagonally below (bottom then left) cell + 2
                memo[i][j] = 2 + memo[i+1][j-1];

                if (memo[i][j] > memo[maxI][maxJ])
                {
                    maxI = i;
                    maxJ = j;
                }
            }
            else
            {
                // max val between left cell and bottom cell
                memo[i][j] = (memo[i][j-1] > memo[i+1][j]) ? memo[i][j-1] : memo[i+1][j];
            }
        }
    }

    int subStrLen = memo[maxI][maxJ];
    cout << "Sub String Len =" << subStrLen << " @ " << maxI << ", " << maxJ << endl;

    i = maxI;
    j = maxJ;
    while (i < len && j >= 0 && i < j)
    {
        int curr = memo[i][j];
        int left = memo[i][j-1];
        int down = memo[i+1][j];
        int diag = memo[i+1][j-1];

        if (curr == (diag + 2) && curr != left && curr != down)
        {
            subStrIdx[i] = 1;
            subStrIdx[j] = 1;
            i += 1; j -= 1;
        }
        else if (left > down)
        {
            j -= 1;
        }
        else
        {
            i += 1;
        }

        if (memo[i][j] == 1 && (curr -2) == 1)
        {
            subStrIdx[i] = 1;
        }
    }

    for (i = 0; i < len; i++)
    {
       if (subStrIdx[i] == 1)
        {
            const char c = s.at(i);
            retVal.append(&c);
        }
    }

    return retVal;
}

string StringProblems::palindromicSubstring(string s)
{

    return s;
}

string StringProblems::commonSubsequence(string s1, string s2)
{
    const int lenX = s1.length() + 1;
    const int lenY = s2.length() + 1;
    int i = 0, j = 0, maxI = 0, maxJ = 0;
    int memo[lenX][lenY];
    string retVal = "";

    // initialize table to zero
    for (i = 0; i < lenY; i++)
    {
        for (j = 0; j < lenX; j++)
        {
            memo[i][j] =  0;
        }
    }

    for (i = 1; i < lenY; i++)
    {
        char c1 = s2.at(i-1);
        for (j = 1; j < lenX; j++)
        {
            char c2 = s1.at(j-1);
            if (c1 == c2)
            {
                memo[i][j] =  memo[i-1][j-1] + 1;

                if (memo[i][j] > memo[maxI][maxJ])
                {
                    maxI = i;
                    maxJ = j;
                }
            }
        }
    }

    int subStrLen = memo[maxI][maxJ];
    int startIdx = maxI - subStrLen;

    return s1.substr(startIdx, subStrLen);
}

bool StringProblems::isStringPalindrome(string s1)
{
    string s2(s1);
    reverse(s2.begin(), s2.end());
    string output = commonSubsequence(s1, s2);

    return (output.length() == s1.length());
}

int StringProblems::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    string l_msg = p_msg + "STRINGS";

    string data1 = "abcba";
    string data2 = "abcdef";
    string data3 = "babcbabcbaccba";
    string data4 = "GEEKSFORGEEKS";
    string data5 = "abcdaf";
    string data6 = "zbcdf";

    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\n" << l_msg << endl;
        cout << "Welcome to Problem Solving with STRINGS!" << endl;
        cout << "---------------------------------" << endl;
        cout << "0. atoi implementation" << endl;
        cout << "1. Print all combinations of the characters in a string ABCD" << endl;
        cout << "2. Longest Palindromic Subsequence" << endl;
        cout << "3. Longest Palindromic Substring" << endl;
        cout << "4. Longest Common Subsequence" << endl;
        cout << "5. Is this a Palindrome" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '0':
            {
                myAtoI();
                break;
            }
        case '1':
            {
                string l_data;
                cout << "Enter a string:" << endl;
                cin >> l_data;
                cout << "* * * * * * *" << endl;
                charCombinations(const_cast<char*>(l_data.c_str()), 0, l_data.length());
                break;
            }
        case '2':
            {
                cout << "Palindromic Sub-Sequence:" << endl;
                cout << "\tInput=" << data1 << " --> " << palindromicSubsequence(data1) << endl;
                cout << "\tInput=" << data2 << " --> " << palindromicSubsequence(data2) << endl;
                cout << "\tInput=" << data3 << " --> " << palindromicSubsequence(data3) << endl;
                cout << "\tInput=" << data4 << " --> " << palindromicSubsequence(data4) << endl;
                break;
            }
        case '3':
            {
                cout << "Palindromic Sub-String:" << endl;
                cout << "\tInput=" << data1 << " --> " << palindromicSubstring(data1) << endl;
                cout << "\tInput=" << data2 << " --> " << palindromicSubstring(data2) << endl;
                cout << "\tInput=" << data3 << " --> " << palindromicSubstring(data3) << endl;
                cout << "\tInput=" << data4 << " --> " << palindromicSubstring(data4) << endl;
                break;
            }
        case '4':
            {
                cout << "Longest Common Subsequence" << endl;
                cout << "\tInput=: " << data5 << ", " << data6 << " --> " << commonSubsequence(data1, data2) << endl;
                break;
            }
        case '5':
            {
                string data;
                cout << "Is this a Palindrome? Give us your input: " << endl;
                getline(cin, data);
                cout << "\t" << data << (isStringPalindrome(data) ? " --> Is a Palindrome" : " --> Not a Palindrome" ) << endl;
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

