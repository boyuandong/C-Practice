// Main.cpp
#include "figure.h"
int main()
{
    Triangle t;
    Square s;
    Circle c;
    t.set_dim(10.0, 5.0);
    t.show_area();
    s.set_dim(10.0, 5.0);
    s.show_area();
    c.set_dim(9.0);
    c.show_area();
}