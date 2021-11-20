#include "string.h"
#include <iostream>


int main() {
  String s1("no please");
  String s2("hey");

  s1.append(s2);
//  //const char *c = "chars";
//  s1.append("char");
  std::cout << s1 << std::endl;
   
}
