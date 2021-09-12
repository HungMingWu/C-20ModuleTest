module;
#include <utility>

export module small.traits:has_allocator;

export namespace small {
    template <typename T> 
    concept has_allocator_v = requires(T v) {
        { v.get_allocator() };
        { T::allocator_type };
    };
}