#include <iostream>
using namespace std;

class MAT
{
private:
    int rows, cols;
    int **mat;

public:
    // Constructor
    MAT(int r, int c) : rows(r), cols(c)
    {
        mat = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            mat[i] = new int[cols];
        }
    }

    // Destructor
    ~MAT()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Function to input matrix elements
    void input()
    {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix elements
    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Matrix addition
    MAT operator+(const MAT &other) const
    {
        MAT result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Matrix subtraction
    MAT operator-(const MAT &other) const
    {
        MAT result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    MAT operator*(const MAT &other) const
    {
        MAT result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // Matrix transpose
    MAT transpose() const
    {
        MAT result(cols, rows);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
};

int main()
{
    int m, n;

    cout << "Enter the number of rows and columns of the 1st matrix: ";
    cin >> m >> n;

    MAT mat1(m, n);
    mat1.input();

    cout << "\nEnter the number of rows and columns of the 2nd matrix: ";
    cin >> m >> n;

    MAT mat2(m, n);
    mat2.input();

    cout << "\nMatrix 1:" << endl;
    mat1.display();

    cout << "\nMatrix 2:" << endl;
    mat2.display();

    MAT sum = mat1 + mat2;
    cout << "\nSum of matrices:" << endl;
    sum.display();

    MAT diff = mat1 - mat2;
    cout << "\nDifference of matrices:" << endl;
    diff.display();

    if (m == n)
    {
        MAT prod = mat1 * mat2;
        cout << "\nProduct of matrices:" << endl;
        prod.display();
    }
    else
    {
        cout << "\nMatrix multiplication not possible for non-square matrices." << endl;
    }

    MAT trans1 = mat1.transpose();
    cout << "\nTranspose of Matrix 1:" << endl;
    trans1.display();

    MAT trans2 = mat2.transpose();
    cout << "\nTranspose of Matrix 2:" << endl;
    trans2.display();

    return 0;
}