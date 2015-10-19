#include <iostream>
   #include <functional>
   #include <algorithm>
   using namespace std;
   int main ()
   {
       int first[] = {10, 40, 90};
       int second[] = {1, 2, 3};
       int results[5];
       transform ( first, first + 3, second, results, divides<int>());
       for (int i = 0; i < 3; i++)
           cout << results[i] << " ";
       return 0;
   }