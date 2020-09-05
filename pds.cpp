#include <iostream>
using namespace std;

int main() {
  cout << "Hello, please input a base and its exponent." << endl;
  int a;
  int b;
  cin >> a;
  cin >>b;
  unsigned long long int output = a;
  if (b>1)
    {
      for (int i = b-1; i > 0; i--)
	{
	  output = output*a;
	}
    }
  else if (a == 0 && b== 0) cout << "Undefined" << endl;
  else if (b == 0) output = 1;
  cout << a << "^" << b << "=" << output << endl;
  int temp = output;
  output = 0;
  while (temp != 0)
    {
      output = output + temp % 10;
      temp = temp/10;
    }
  cout << "Sum of Digits: " << output << endl;
}
