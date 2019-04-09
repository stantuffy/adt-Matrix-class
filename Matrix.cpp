/*
 * Matrix.cpp
 *
 *  Created on: 8 apr 2019
 *      Author: rob
 */

#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns) : NUM_ROWS(rows), NUM_COLS(columns) {
	elements = new double*[NUM_ROWS];
	for (int i=0; i<NUM_ROWS; i++)
		elements[i] = new double[NUM_COLS];
}

Matrix::Matrix(const Matrix& other) : NUM_ROWS(other.NUM_ROWS), NUM_COLS(other.NUM_COLS) {
	this->elements = new double*[NUM_ROWS];
	for (int i=0; i<NUM_ROWS; i++) {
		elements[i] = new double[NUM_COLS];
		for (int j=0; j<NUM_COLS; j++)
			elements[i][j] = other.elements[i][j];
	}
}

Matrix::~Matrix() {
	for (int i=0; i<NUM_ROWS; i++) {
		delete[] elements[i];
	}
	delete[] elements;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	double** newElements = new double*[other.getRows()];
	for (int i=0; i<other.getRows(); i++)
	{
		newElements[i] = new double[other.getColumns()];
		for (int j=0; j<other.getColumns(); j++)
		{
			newElements[i][j] = other.elements[i][j];
		}
	}

	for (int i=0; i<this->NUM_ROWS; i++)
		delete[] this->elements[i];
	delete[] this->elements;

	this->elements = newElements;
	this->NUM_ROWS = other.getRows();
	this->NUM_COLS = other.getColumns();
	return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
	if (other.getRows() != this->NUM_ROWS && other.getColumns() != this->NUM_COLS)
		throw "Matrix sizes do not match!";

	Matrix output(other.getRows(),other.getColumns());
	for (int i=0; i<other.getRows(); i++)
	{
		for (int j=0; j<other.getColumns(); j++)
		{
			output.elements[i][j] = other.elements[i][j] + this->elements[i][j];
		}
	}
	return output;

	// return *this += other;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (other.getRows() != this->NUM_ROWS && other.getColumns() != this->NUM_COLS)
			throw "Matrix sizes do not match!";

	for (int i=0; i<NUM_ROWS; i++)
	{
		for (int j=0; j<NUM_COLS; j++)
		{
			this->elements[i][j] += other.elements[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& other)
{
	if (other.getRows() != this->NUM_ROWS && other.getColumns() != this->NUM_COLS)
			throw "Matrix sizes do not match!";

		Matrix output(other.getRows(),other.getColumns());
		for (int i=0; i<other.getRows(); i++)
		{
			for (int j=0; j<other.getColumns(); j++)
			{
				output.elements[i][j] = this->elements[i][j] - other.elements[i][j];
			}
		}
		return output;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (other.getRows() != this->NUM_ROWS && other.getColumns() != this->NUM_COLS)
				throw "Matrix sizes do not match!";

		for (int i=0; i<NUM_ROWS; i++)
		{
			for (int j=0; j<NUM_COLS; j++)
			{
				this->elements[i][j] -= other.elements[i][j];
			}
		}
		return *this;
}

Matrix& Matrix::operator*(double scalar)
{
	for (int i=0; i<NUM_ROWS; i++)
	{
		for (int j=0; j<NUM_COLS; j++)
		{
			this->elements[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& other)
{
	if (this->NUM_COLS != other.getRows())
		throw "Column of first matrix must be equal to row of second!";

	Matrix output(this->NUM_ROWS,other.getColumns());

	for (int i=0; i<NUM_ROWS; i++)
	{
		for (int j=0; j<other.getColumns(); j++)
		{
			for (int k=0; k<NUM_COLS; k++)
			{
				output.elements[i][j] += this->elements[i][k] * other.elements[k][j];
			}
		}
	}
	return output;
}

/* ================================ DA RIVEDERE ================================ */
Matrix& Matrix::operator*=(const Matrix& other)
{
	if (this->NUM_COLS != other.getRows())
			throw "Column of first matrix must be equal to row of second!";

	Matrix output(this->NUM_ROWS,other.getColumns());

	for (int i=0; i<NUM_ROWS; i++)
	{
		for (int j=0; j<other.getColumns(); j++)
		{
			for (int k=0; k<NUM_COLS; k++)
			{
				output.elements[i][j] += this->elements[i][k] * other.elements[k][j];
			}
		}
	}
	*this = output;
	return *this;
}

bool Matrix::operator==(const Matrix& other) {
	if (this->NUM_ROWS != other.getRows() || this->NUM_COLS != other.getColumns())
		return false;

	for (int i=0; i<NUM_ROWS; i++)
	{
		for (int j=0; j<NUM_COLS; j++)
		{
			if (this->elements[i][j] != other.elements[i][j])
				return false;
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other) {
	return !(*this == other);
}

void Matrix::insert(unsigned int i, unsigned int j, double value) {
	this->elements[i][j] = value;
}

double* Matrix::getRowAt(unsigned int row) {
	double* vector = new double[this->NUM_COLS];

	for (int j=0; j<NUM_COLS; j++)
		vector[j] = this->elements[row][j];

	return vector;
}

double* Matrix::getColumnAt(unsigned int col) {
	double* vector = new double[this->NUM_ROWS];

	for (int i=0; i<NUM_ROWS; i++)
		vector[i] = this->elements[i][col];

	return vector;
}

int Matrix::getRows() const {
	return this->NUM_ROWS;
}

int Matrix::getColumns() const {
	return this->NUM_COLS;
}

void Matrix::toString()
{
	for (int i=0; i<NUM_ROWS; i++)
	{
		for (int j=0; j<NUM_COLS; j++)
		{
			std::cout << elements[i][j] << " ";
		}
		std::cout << "\n";
	}
}


