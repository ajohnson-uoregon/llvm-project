int g(int);
void test() {
  [&](int _){ g(g(_)); }(g(0));
}

/* Expected result:
int g(int);
void test() {
  LOG_LAMBDA([&](int _){
      LOG_FN(g, LOG_FN(g, _));
    }, LOG_FN(g, 0));
}
*/
