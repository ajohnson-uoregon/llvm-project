int* test() {
  int* a = 0;
  double b, *c;
  b = 0;
  c = 0;
  return 0;
}

/* Expected result:
int* test() {
  int* a = nullptr;
  double b, *c;
  b = 0;
  c = nullptr;
  return nullptr;
}
*/
