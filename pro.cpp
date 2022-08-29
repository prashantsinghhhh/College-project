// C program to Implement Weedle's Rule
#include <math.h>
#include <stdio.h>

// A sample function f(x) = 1/(1+x^2)
float y(float x)
{
	float num = 1;
	float denom = 1.0 + x * x;

	return num / denom;
}

// Function to find the integral value
// of f(x) with step size h, with
// initial lower limit and upper limit
// a and b
float WeedleRule(float a, float b, int n)
{
	// Find step size h
	double h = fabs(b - a) / n;  // fabs returns absolute value which is always +ve
  int looping;
  looping=n/6;
    for(int i=1;i<=looping;i++){
      // To store the final sum
      float sum = 0;
	// Find sum using Weedle's Formula
	sum = sum + (((3 * h) / 10) * (y(a)+ 5*y(a + h)+y(a +2* h)+ 6 * y(a + 3 * h)
								+ y(a + 4 * h)+ 5 * y(a + 5 * h)+ y(a + 6 * h)));
     return sum; // Return the final sum
    }
}


int main()
{
	// lower limit and upper limit
	float lower_limit, upper_limit, n;
   printf("Enter the lower limit:\n");
   scanf("%f",&lower_limit);
    printf("Enter the upper limit:\n");
      scanf("%f",&upper_limit);
       printf("Enter the number of segements:\n");
        scanf("%f",&n);

	
  if((int)n%6==0){
    // Function Call
	printf("f(x) = %f", WeedleRule(lower_limit, upper_limit,n));
  }
  else{
    printf("not a multiple of 6 so cant be solved by weddle's rule \n");
  }	
	
	return 0;
}
