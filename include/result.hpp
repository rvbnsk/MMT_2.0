#ifndef MMT_RESULT_HPP
#define MMT_RESULT_HPP

#include <utility>

#include "error.hpp"

namespace mmt {

struct Unit {
};

namespace detail {

template <typename T>
struct Singleton {
    static_assert(!std::is_void<T>::value, "use 'Unit' instead of 'void'");
    T value;
};

}  // namespace detail

template <typename T>
struct Ok : detail::Singleton<T> {
    // NOLINTNEXTLINE(hicpp-explicit-conversions)
    Ok(T);
};

template <typename E>
struct Err : detail::Singleton<E> {
    // NOLINTNEXTLINE(hicpp-explicit-conversions)
    Err(E);
};

template <typename T, typename E>
class Result {
    union {
        Ok<T> ok;
        Err<E> err;
    };
    bool is_ok_;

   public:
    // NOLINTNEXTLINE(hicpp-explicit-conversions)
    Result(Ok<T> &&ok) : ok{std::move(ok)}, is_ok_{true} {}
    // NOLINTNEXTLINE(hicpp-explicit-conversions)
    Result(Err<E> &&err) : err{std::move(err)}, is_ok_{false} {}
};  // namespace mmt

}  // namespace mmt

#endif