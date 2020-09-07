//same repo for both parts, note commits as part 1 or part 2
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int pow(int a,int b)
{
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

  return output;
}

vector<int> vectorize_digits(int input)
{
  vector<int> output;
  int temp = 0;
  int num = input;
  while(num != 0)
    {
      temp = num % 10;
      output.push_back(temp);
      num = num/10;
    }
  return output;
}

int sum_vector(vector<int> input)
{
  int output = 0;
  for (int i = 0; i < input.size(); i++) output += input.at(i);
  return output;
}

string vec_to_string(vector<int> input)
{
  string output = "";
  string temp;
  for(int i = input.size()-1; i >= 0; i--)
    {
      temp = to_string(input.at(i));
      output.append(temp);
    }
  return output;
}


int main() {
  int a = 0;
  int b = 0;
  cout << "Hello, please input a positive base and exponent." << endl;
  cin >> a;
  cin >>b;
  while (a < 0 || b < 0)
    {
      if (a < 0 || b < 0) cout << "Negative numbers are not supported. Please input a positive base and exponent." << endl;
      cin >> a;
      cin >>b;
    }
  int answer = 0;
  answer = pow(a,b);
  cout << a << "^" << b << " = " << answer << endl;
  int temp2 = answer;
  int acc = 0;
  while (temp2 >= 1)
    {
      temp2 /= 10;
      acc += 1;
    }
  vector<int> temp(acc);
  temp = vectorize_digits(answer);
  answer = sum_vector(temp);
  string tempstr = vec_to_string(temp);
  cout << "Sum of " << tempstr << ": " << answer << endl;

  return 0;
}
