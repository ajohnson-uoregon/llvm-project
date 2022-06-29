#include "stdio.h"

// int add(int x) {
//   int y = x;
//   y = y+y+y;
//   return y;
// }
//
// int add2(int x) {
//   int y = x;
//   x = 0;
//   x = add(3);
//   return y;
// }
//
// int add3(int x) {
//   int y = x;
//   y = y*2;
//   y = y+y;
//   int ** z = 0;
//   printf("hello world\n");
//
//   return y;
// }
//
// int add4(int x) {
//   int* y = &x;
//   *y += 3;
//   if (*y == 4) {
//     y = 0;
//   }
//   return *y;
// }
//
// int global;
// int* add5(int x) {
//   if (x == 5) {
//     return &global;
//   }
//   else {
//     return 0;
//   }
// }
//
// void lambda() {
//   auto l = [](float a, float b) {  return a < b; };
//
//   l(3, 4);
// }
//
// int adams() {
//   add4(2);
//   return 42;
// }
//
// int main() {
//   adams();
//   lambda();
// }



int g(int);
void test() {
  [&](int _){ g(g(_)); }(g(0));
}

int main() {

}
