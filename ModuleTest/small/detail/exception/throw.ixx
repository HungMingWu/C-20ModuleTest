module;
#include <exception>
#include <type_traits>
#include <utility>

export module small.exception:throw_context;

#ifndef cpp_exceptions
#define SMALL_DISABLE_EXCEPTIONS
#endif

export namespace small {
    /// \brief Throw an exception but terminate if we can't throw
    template <typename Ex> [[noreturn]] void throw_exception(Ex&& ex) {
#ifndef SMALL_DISABLE_EXCEPTIONS
        throw static_cast<Ex&&>(ex);
#else
        (void)ex;
        std::terminate();
#endif
    }

    /// \brief Construct and throw an exception but terminate otherwise
    template <typename Ex, typename... Args> [[noreturn]] void throw_exception(Args &&...args) {
        throw_exception(Ex(std::forward<Args>(args)...));
    }

    /// \brief Throw an exception but terminate if we can't throw
    template <typename ThrowFn, typename CatchFn> void catch_exception(ThrowFn&& thrower, CatchFn&& catcher) {
#ifndef SMALL_DISABLE_EXCEPTIONS
        try {
            return static_cast<ThrowFn&&>(thrower)();
        }
        catch (std::exception&) {
            return static_cast<CatchFn&&>(catcher)();
        }
#else
        return static_cast<ThrowFn&&>(thrower)();
#endif
    }

} // namespace small