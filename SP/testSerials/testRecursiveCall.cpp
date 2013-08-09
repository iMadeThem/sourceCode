#include <iostream>

class Forward {
    int i;

    public:
        Forward() : i(0) {}

        // Call to undeclared function:
        int f() const {
            return g() + 1;
        }

        int g() const {
            return i;
            // can compile, but will result in "segmentation fault 11"
            // return f() + 1;
        }

        // can compile, but will result in "segmentation fault 11"
        int h() const {
            return h() + 1;
        }

};
int main()
{
    Forward frwd;
    std::cout << frwd.f() << std::endl;
    std::cout << frwd.g() << std::endl;

    frwd.h();

}
///:
