#include "my_class.hpp"
#include <cstdint>
#include <iostream>
#include <cmath>


namespace mm{
    bool has_same_rows(int ( &matrix )[N_Max][M_Max], int rows, int columns)
    {
        bool flag;
        for (int a = 0; a < rows; a++)
        {
            flag = true;
            for (int b = a + 1; b < rows; b++)
            {
                for (int c = 0; c < columns; c++)
                {
                    if (matrix[a][c] != matrix[b][c])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }


    bool is_simple(int number)
    {
        if (number == 1) return false;
        for (int x = 2; x < sqrt(number)+1; x++)
        {
            if (number % x == 0) return false;
        }
        return true;
    }


    int biggest_simple(int ( &matrix )[N_Max][M_Max], int rows, int columns)
    {
        int big_simple = INT32_MIN;
        for (int a = 0; a < rows; a++)
        {
            for (int b = 0; b < columns; b++)
            {
                if (mm::is_simple(matrix[a][b]) && (big_simple < matrix[a][b])) big_simple = matrix[a][b];
            }
        }
        return big_simple;
    }  



    void replace_minimal(int ( &matrix )[N_Max][M_Max], int rows, int columns, int number)
    {
        for (int b = 0; b < columns; b++)
        {
            int minimal = INT32_MAX;
            int index = 0;
            for (int a = 0; a < rows; a++)
            {
                if (matrix[a][b] < minimal)
                {
                    minimal = matrix[a][b];
                    index = a;
                }
            }
            matrix[index][b] = number;
        }
    }
}