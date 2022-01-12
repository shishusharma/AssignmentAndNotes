#include<iostream>
using namespace std;
void factorial(int n)
{	
	int i,fact=1;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	cout<<"The factorial of "<<n<<" is "<<fact<<"\n";
}
