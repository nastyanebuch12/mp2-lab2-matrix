#include <gtest.h>
#include <utmatrix.h>

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  /*TVector<int> v1(4), v2(4, 2), v3;
  int ind,el;
  cin >> v1;
  cin >> v2;
  cout << "startindex v2: " << v2.GetStartIndex();
  cout << "index: "; cin >> ind; cout << "element: "; cin >> el;
  v1[ind] = el; cout << "new v1: " << v1;
  if (v1 == v2) cout << "1";
  if (v1 != v2) cout << "0";
  v3 = v1; cout << "v3: " << v3;
  v3 = v1+v2; cout << "v3=v1+v2=: " << v3;
  v3 = v1-v2; cout << "v3=v1-v2=: " << v3;
  v3 = v1 * v2; cout << "v3=v1*v2=: " << v3;
  v3 = v1+3; cout << "v3=v1+3=: " << v3;
  v3 = v1 -5; cout << "v3=v1-5=: " << v3;
  v3 = v1 *(-1); cout << "v3=v1*(-1)=: " << v3;*/


}
