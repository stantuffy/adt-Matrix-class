/*
 * Matrix.h
 *
 *  Created on: 8 apr 2019
 *      Author: rob
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>

class Matrix {
public:
	// Default constructor
	Matrix(unsigned int, unsigned int);

	// Copy constructor
	Matrix(const Matrix&);

	// Destructor
	~Matrix();

	/*
	 * Copy assignment
	 */
	Matrix& operator=(const Matrix&);

	/*
	 * Addition between at least two matrices.
	 * Returning from a + involves copying the result out of the local
	 * variable 'output' and into some place where the caller can access it
	 */
	Matrix operator+(const Matrix&);

	/*
	 * Returns a dereferenced pointer to the same class.
	 * For instance A+=B: the elements are added and then copied into A.
	 */
	Matrix& operator+=(const Matrix&);

	/*
	 * Subtraction between at least two matrices
	 */
	Matrix operator-(const Matrix&);

	/*
	 * Returns a dereferenced pointer to the same class.
	 * For instance A-=B: the elements are subtracted and then copied into A.
	 */
	Matrix& operator-=(const Matrix&);

	/*
	 * Scale matrix
	 */
	Matrix& operator*(double);

	/*
	 * Multiplication between at least two matrices
	 */
	Matrix operator*(const Matrix&);

	/*
	 * Returns a dereferenced pointer to the same class.
	 * For instance A*=B: the elements are multiplied and then copied into A.
	 */
	Matrix& operator*=(const Matrix&);

	/*
	 * Returns true or false whether the two matrices are equal
	 */
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);

	/*
	* F(x) for every x
	*/
	template <typename F>
	Matrix& applyFunction(F);

	/*
	 * Inserts value at specified position [r][c]
	 */
	void insert(unsigned int, unsigned int, double);

	/*
	 * Returns specified row vector
	 */
	double* getRowAt(unsigned int);

	/*
	 * Returns specified column vector
	 */
	double* getColumnAt(unsigned int);

	/*
	 * Returns number of rows
	 */
	int getRows() const;

	/*
	 * Returns number of columns
	 */
	int getColumns() const;

	/*
	 * Prints matrix for debugging purposes
	 */
	void toString();

	double** elements;

private:
	unsigned int NUM_ROWS;
	unsigned int NUM_COLS;
};

#endif /* MATRIX_H_ */
