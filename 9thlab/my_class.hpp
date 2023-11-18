#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP
#define N_Max 100
#define M_Max 100


namespace mm
{
    void read_matrix(int ( &matrix )[N_Max][M_Max], int& rows, int& columns);
    void print_matrix(int ( &matrix )[N_Max][M_Max], int rows, int columns);
    bool has_same_rows(int ( &matrix )[N_Max][M_Max], int rows, int columns);
    bool is_simple(int number);
    int biggest_simple(int ( &matrix )[N_Max][M_Max], int rows, int columns);
    void replace_minimal(int ( &matrix )[N_Max][M_Max], int rows, int columns, int number);
}

#endif