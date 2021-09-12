import small.traits;
import small.vector;

#include <iostream>
#include <utility>
#include <vector>

template <class R>
void print(R&& v)
{
    for (const auto& x : v) {
        constexpr bool x_is_pair = small::is_pair_v<std::decay_t<decltype(x)>>;
        if constexpr (not x_is_pair) {
            std::cout << x << ' ';
        }
        else {
            std::cout << '<' << x.first << ',' << x.second << '>' << ' ';
        }
    }
    std::cout << "\n";
}

int main()
{
    // Vector as usual
    small::vector<int> v1{ 1, 2, 3, 4, 5 };
    print(v1); // 1 2 3 4 5
	return 0;
}