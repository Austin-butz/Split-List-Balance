#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int split(vector<int> l, int m, int i);
  int sum(vector<int> l, int a, int b);
//all values associated with the input vector and M are below
  vector<int> lis(5);
  lis.at(0) = 2;
  lis.at(1) = 3;
  lis.at(2) = 4;
  lis.at(3) = 5;
  lis.at(4) = 6;
  int m = 2;
/////////////////////////////////////////////////////////////
  if (m == lis.size()) //if m equals the vector's size the largest item will be the smallest max
    {
      int temp = 0;
      for (int i = 0; i < lis.size(); i++) if (lis.at(i) > temp) temp = lis.at(i);
      cout << "ans: " << temp << endl;
      return 0;
    }
  long int max = 9999999; //arbitrarily large number to hold smallest max
  for (int i = 0; i < lis.size()-m; i++)
    {
     int result = split(lis, m-1, i+1);
     if (result < max) max = result;
    }
  cout << "input: [";
  for (int i = 0; i < lis.size()-1; i++) cout << lis.at(i) << ", ";
  cout << lis.at(lis.size()-1) << "] " << "m: " << m << endl;
  cout << "ans: " << max << endl;
  return 0;
}

int split(vector<int> l, int m, int i) // splits a vector into all possible combination given m and l.size() and records the smallest possible max
{
  int sum(vector<int> l, int a, int b);
  for (int g = m; g > 0; g--) 
    if (m=1) return sum(l, i, l.size()); //base case
  else
    {
      int temp = split(l, m-1, i+1);
      int temp2 = sum(l, i, l.size()-m-i);
      if (temp < temp2) return temp; //checks if the call to split produced a smaller max
      else return temp2;
      
    }
}

int sum(vector<int> l, int a, int b) //iterates through a vector accumulating all values in sum
{
  int sum = 0;
  for (int i = a; i < b; i++) sum += l.at(i);
  return sum;
}
