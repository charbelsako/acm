#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void display(double total, int possibilities);

int main()

{
  float n, d, r, gems;
  double total = 0;
  int possibilities = 0;

  do
  {
    cin >> n >> d >> r;

  } while (n < 1 || d > 500 || r < 1 || r > n);

  gems = n + d;

  if (n == 1 && d != 0)
  {
    total = gems;
    possibilities = n;
    display(total, possibilities);
    return 0;
  }
  else if (d == 0)
  {
    total = r;
    possibilities = 1;
    display(total, possibilities);
    return 0;
  }

  else
  {

    if ((int)gems % 2 != 0)
    {
      possibilities = n * n;

      for (int i = 0; i < n; i++)
      {
        total += (double)(gems - 1 - i) * n;
      }
      cout << "total is: " << total << endl;
      cout << "possibilities = " << possibilities << endl;
      // +n == 12.2
      cout << "other total " << (float)(total + n - r + d / r) / (possibilities) << endl;
    }
    else
    {
      possibilities = n * n + 1;
      total = (double)((gems - 1) * (n * n) + (r * r));
    }
  }

  display(total, possibilities);
  return 0;
}

void display(double total, int possibilities)
{
  printf("%.7lf\n", (double)((total) / possibilities));
}