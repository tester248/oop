#include <iostream>
using namespace std;

 class Demo
 {
    private:
        int a;
    public:
    Demo() {a = 10;}
    friend void display(Demo&);
 };

 void display(Demo& x)
 {
  cout << "a=" << x.a;
 }

 int main()
 {
	Demo obj;
	display(obj);
    return 0;
 }


