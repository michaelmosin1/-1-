#include <iostream>
#include <fstream>


int length(char* word)
{
    unsigned int leng = 0;
    while (word[leng] != '\0') leng++;
    return leng;
}


bool has_three_same(char* word)
{
    int len = length(word);
    for (int a = 0; a < len - 2; a++)
    {
        int count = 1;
        for (unsigned int b = a + 1; b < len; b++)
        {
            if (word[a] == word[b]) count++;
            if (count == 3) return true;
        }
    }
    return false;
}


void copy_to_string(char* input, char* output, int size_of_output)
{ //copies all symbols from 1 word to other
    if (size_of_output < length(input))
    {
        return;
    }
    else 
    {
        for (int a = 0; a <= length(input); a++) output[a] = input[a];
    }
}


bool strcompare(char* word1, char* word2) 
{ //compares two strings and returns are they same or no
    if (length(word1) == length(word2)) 
        {
            for (short a = 0; a < length(word1); a++) 
                {
                    if (word1[a] != word2[a]) return false;
                }
            return true;
        }
    return false;
}


int main()
{
    const int W_Length = 100;
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    bool duplicate;
    bool is_sorted = false;
    int n;
    int i = 0;
    char massive[2000][W_Length];
    std::cout << "Please input N" << std::endl;
    std::cin >> n;
    while (!in.eof())
    {
        duplicate = false;
        char word[100] = {};
        in >> word;
        for (int a = 0; a < i; a++) 
        {
            if (strcompare(word, massive[a])) 
            {
                duplicate = true;
                break;
            }
        }
        if (has_three_same(word) && !duplicate)
        {
            if (i < n)
            {
                copy_to_string(word, massive[i], W_Length);
                i++;
            }
            else if (i == n)
            {
                is_sorted = true;
                i++;
                for (int a = 0; a < n - 1; a++)
                {
                    for (int b = a + 1; b < n; b++)
                    {
                            if (length(massive[b]) < length(massive[a]))
                            swap(massive[a], massive[b]);
                    }
                }
            }
            else 
            {
                for (int a = 0; a < i; a++)
                {
                    if (length(word) < length(massive[a]))
                    {
                        for (int b = n - 1; b > a+1; b--)
                        {
                            copy_to_string(massive[b], massive[b-1], W_Length);
                        }
                        copy_to_string(word, massive[a], W_Length);
                        break;
                    }
                }
            }
        }
    }
    if (!is_sorted)
    {
        for (int a = 0; a < i - 1; a++)
        {
            for (int b = a + 1; b < i; b++)
            {
                if (length(massive[b]) < length(massive[a]))
                    swap(massive[a], massive[b]);
            }
        }
    }
    for (int a = 0; a < std::min(i, n); a++)
        out << massive[a] << ' ';
    return 0;
}