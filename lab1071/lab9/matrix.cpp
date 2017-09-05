/**
  Lukas Herman (lukash)
  CPSC 1071 - Lab 9
  April 1, 2017
  reference parameters and operator overloading

  had to comment out some lines in the copy constructor to make it works.
**/

#include "matrix.h"

#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

/*
 * Parameterized constructor that takes
 * in the rows and columns
 */
Matrix::Matrix(int r, int c)
{
   rows = r;
   cols = c;
   mat = new double*[r];
   int i;
   for(i = 0; i < rows; i++){
      mat[i] = new double[cols];
   }
}

/*
 * Copy constructor.
 * It takes in a matrix and copies
 * in the new values to this matrix.
 *
 * DO NOT TOUCH
 */
Matrix::Matrix(const Matrix& rhs) 
{
/*	for(int i = 0; i < rows; i++) {
		delete[] mat[i];
	}

	delete[] mat;
*/
	rows = rhs.rows;
	cols = rhs.cols;

	mat = new double*[rows];
	for(int i = 0; i < rows; i++) {
		mat[i] = new double[cols]();
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			mat[i][j] = rhs[i][j];
		}
	}
}

/*
 * Destructor. Deletes the matrix.
 */
Matrix::~Matrix()
{
   int i;
   for(i = 0; i < rows; i++)
      delete[] mat[i];
   delete[] mat;
}

/*
 * Adds two matrices together
 *
 * same as c version
 */
Matrix Matrix::operator+(const Matrix& rhs)
{
   Matrix matrix(*this);
   int i, j;
   // Check if the sizes of the matrixes are the same
   if(rhs.rows == rows && rhs.cols == cols){
      for(i = 0; i < rows; i++){
         for(j = 0; j < cols; j++){
            matrix.mat[i][j] += rhs.mat[i][j];
         }
      }
   }
   return matrix;
}

/*
 * Subtracts two matrices
 *
 * same as c version
 */
Matrix Matrix::operator-(const Matrix& rhs)
{
   Matrix matrix(*this);
   int i, j;
   // Check if the sizes of the matrixes are the same
   if(rhs.rows == rows && rhs.cols == cols){
      for(i = 0; i < rows; i++){
         for(j = 0; j < cols; j++){
            matrix.mat[i][j] -= rhs.mat[i][j];
         }
      }
   }
   return matrix;
}

/*
 * Multiplies two matrices.
 *
 * DO NOT TOUCH
 */
Matrix Matrix::operator*(const Matrix& rhs)
{
	Matrix result (rows, rhs.cols);
    if(cols == rhs.rows)
    {
        for(int i = 0; i < result.rows; i++)
        {
            for(int j = 0; j < result.cols; j++)
            {
                for(int k = 0; k < cols; k++) 
                {
                    result[i][j] += mat[i][k] * rhs[k][j];
                }
            }
        }
    }

    return result;
}

/*
 * Prints out the matrix
 *
 * DO NOT TOUCH
 */
void Matrix::print()
{
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(2);
	for(int i = 0; i < rows; i++) {
		std::cout << "[";
		for(int j = 0; j < cols; j++) {
			std::cout.width(0);
			j == getCols()-1 ? std::cout << (*this)[i][j] : 
				std::cout << (*this)[i][j] << ", ";
		}
		std::cout << "]" << std::endl;
	}
}

/*
 * Allows us to acces the matrix using the
 * bracket "[]" operator
 *
 * DO NOT TOUCH
 */
double* Matrix::operator[](int row)
{
	return mat[row];
}

/*
 * Allows us to acces the matrix using the
 * bracket "[]" operator
 *
 * DO NOT TOUCH
 */
const double* Matrix::operator[](int row) const
{
	return mat[row];
}

/*
 * returns the number of rows in the matrix.
 *
 * Hint: we stored this in a member variable.
 */
int Matrix::getRows() const
{
   return rows;
}

/*
 * returns the number of columns in the matrix.
 *
 * Hint: we stored this in a member variable.
 */
int Matrix::getCols() const
{
   return cols;
}

/*
 * Matrix transpose
 *
 * same as c version
 */
Matrix Matrix::transpose() const
{
   Matrix matrix(cols, rows);
   int i, j;
   for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++){
         matrix[j][i] = mat[i][j];
      }
   }
   return matrix;
}
