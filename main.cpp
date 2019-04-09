/*
 * main.cpp
 *
 *  Created on: 8 apr 2019
 *      Author: rob
 */

#include "Matrix.h"

int main() {
	Matrix A(2,2);
	A.insert(0, 0, 1);
	A.insert(0, 1, 3);
	A.insert(1, 1, 9);
	A.insert(1,0,2);
	A.toString();

	std:: cout << "\n";

	Matrix B(2,2);
	B.insert(0,0,100);
	B.insert(0, 1, 100);
	B.insert(1, 0, 100);
	B.insert(1,1,100);
	B.toString();

	std::cout << "\n";

	A=B;
	//A+=B;

	// operator works, but inserts garbage values when C's elements are 0
	//Matrix D = A+B+B+A+A;
	//Matrix D = A+B+A+B;
	//D.print();

	Matrix Q(3,1);
	Q.insert(0,0,2);
	Q.insert(1,0,2);
	Q.insert(2,0,2);


	Matrix P(1,3);
	P.insert(0,0,3);
	P.insert(0,1,3);
	P.insert(0,2,3);

	//Matrix Z = Q*P;
	Q*=P;
	Q.toString();




	std::cout << "\n";

	Matrix C(3,3);
	//C.insert(0,0,900);
	//C.insert(0, 1, 900);
	//C.insert(0, 2, 900);
	C.insert(1,0,900);
	C.insert(1,1,900);
	C.insert(1, 2, 900);
	C.insert(2, 0, 900);
	C.insert(2,1,900);
	C.insert(2,2,900);
	C.toString();

	return 0;


}

