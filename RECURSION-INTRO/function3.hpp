#ifndef _function3
#define _function3

/*
Factorial functions
@param int n        The n! value

Calculate n! by multiplying n * (n-1) * (n-2) * ... * 3 * 2 * 1.
*/

int Factorial_Iter( int n )
{
	int product = 1;
	
	for (int i = 1; i <= n ; i++)
	 product *= i ;

	return product;	
}

int Factorial_Rec( int n )
{
	if (n == 1)
		return 1;

	return n * Factorial_Rec(n - 1) ;

}

#endif
