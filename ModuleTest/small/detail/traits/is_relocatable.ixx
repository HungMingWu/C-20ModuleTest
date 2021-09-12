module;
#include <utility>

export module small.traits:is_relocatable;

namespace small {
    /// \brief True type if a type is relocatable
    /// We use this only for trivially copyable types, but one can
    /// use this as an extension point to make their vectors faster.
    /// Almost any data structure without internal pointers is
    /// relocatable.
    template <class T>
    struct is_relocatable : std::conjunction<std::is_trivially_copy_constructible<T>,
        std::is_trivially_copy_assignable<T>, std::is_trivially_destructible<T>> {
    };

    export
    template <class T> constexpr bool is_relocatable_v = is_relocatable<T>::value;

}