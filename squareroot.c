// Author: Rachmad V. W. Putra
// Description: Model of a square root computation from the paper "A Novel Fixed-Point Square Root Algorithm and Its Digital Hardware Design" 
// Link of the paper: https://doi.org/10.1109/ICTSS.2013.6588110

#include <stdio.h>

int main(void)
{
  // Example
  int D = 445;
  int n = 10;
  
  // Initiation
  int R = 0, Q = 0, F = 0;
  int mask = 0x3;
  int Ft = 0;
   
  for (int i = n; i > 0; i -= 2) 
  {
    R = (R << 2) | (D & ( 3 << (i-2) )) >> (i-2);
    if (R >= ((F << 1) | 1)) 
    {
      Q = (Q << 1) | 1;
      F = ((F + (F & 1)) << 1) | 1;
    } 
    else 
    {
      Q = (Q << 1) | 0;
      F = ((F + (F & 1)) << 1) | 0;
    }
    R = R - (F * (F & 1));	  
    printf("index(%d) = %d/%d\n", i, Q, R);
  }
printf("sqrt(%d) = %d/%d\n", D, Q, R);
}
