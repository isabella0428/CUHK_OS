/* This file is to test how the 
optimizer works, cannot run actually */

int main(void) {
  int x = 1;
  x = x + 1;
  x = x + 1;
  return x;
}

/* with different optimization levels, 
we get add_O0.s and add_O1.s
The higher the optimization level(add_O1.s) is, 
the more compact it will become. */

