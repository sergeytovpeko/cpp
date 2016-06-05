#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <string>

// TODO: implement std::copy for std::array.
// Like example in http://en.cppreference.com/w/cpp/container/array
//
// implement Tuple (to find out how parameter pack, initializer_list work)
//
// http://en.cppreference.com/w/cpp/language/parameter_pack
//
// http://nerdparadise.com/forum/openmic/5712/

namespace my {

template<typename T, std::size_t N>
struct array
{
    T data[N];

    void init(T *data)
    {
        return;
    }
    template<typename FirstType, typename ...Type>
    void init(T *data, FirstType first, Type... others)
    {
        *data = first;

        init(++data, others...);
    }

    template<typename ...Type>
    array(Type... t) { init(data, t...); };


    void out()
    {
        for (size_t i = 0; i < N; ++i) {
            std::cout << data[i] << std::endl;
        }
    }
};


} // ~my


int main()
{
   my::array<int, 3> a;
   my::array<int, 3> b(10, 20, 30);

   b.out();

   my::array<std::string, 1> str("hello");

   return 0;
}
