#include <stdio.h>

int mult (float a, float b, float c) {

   printf ("\n %f \n",a*b*c);
//	return (a*b*c);

}

 int main ()  {

    float x, y;

    x = 23.5;
    y = 12.9;

    mult (x, y, 3.87);

    return 0;
}
