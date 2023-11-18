#include "my_class.hpp"
#include <iostream>


namespace mm{
    void read_matrix(int ( &matrix )[N_Max][M_Max], int& rows, int& columns)
    {
        std::cout << "Please input size(rows, columns) of matrix" << std::endl;
        std::cin >> rows >> columns; 
        std::cout << "Please input elements of matrix" <<  std::endl;
        for (short i = 0; i < rows; i++)
            for (short j = 0; j < columns; j++)
                std::cin >> matrix[i][j];
    }


    void print_matrix(int ( &matrix )[N_Max][M_Max], int rows, int columns)
    {
        for (int a = 0; a < rows; a++)
        {
            for (int b = 0; b < columns; b++)
            {
                std::cout << matrix[a][b] << ' '; 
            }
            std::cout << std::endl;
        }
    }
}
