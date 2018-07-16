#include <bits/stdc++.h>
#include <iostream>
using namespace std;

namespace A {
  double add (double a, double b) {
    return a + b;
  } 
}

int main(){
  cout<< A::add(5.5, 3.8) <<endl;
}

