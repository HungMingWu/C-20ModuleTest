module;
#include <utility>

export module small.traits:is_pair;

export namespace small {
    /// Check if type is a pair
    template <typename> struct is_pair : std::false_type {};

    template <typename T, typename U> 
    struct is_pair<std::pair<T, U>> : std::true_type {};

    template <class T> constexpr bool is_pair_v = is_pair<T>::value;
}