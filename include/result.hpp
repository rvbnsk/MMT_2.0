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
    // NOLINTNEXTLINE(clang-analyzer-optin.cplusplus.UninitializedObject)
    explicit Ok(T value_){};
};

template <typename E>
struct Err : detail::Singleton<E> {
    explicit Err(E value_){};
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

    Result(const Result &) noexcept = default;
    Result(Result &&) noexcept = default;
    Result &operator=(const Result &) noexcept = default;
    Result &operator=(Result &&) noexcept = default;

    ~Result() = default;
    T &unwrap() & { return this->ok.value; }
    T &&unwrap() && { return this->ok.value; }
    const T &unwrap() const & { return this->ok.value; }
    const T &&unwrap() const && { return this->ok.value; }

    E &unwrap_err() & { return this->err.value; }
    E &&unwrap_err() && { return this->err.value; }
    const E &unwrap_err() const & { return this->err.value; }
    const E &&unwrap_err() const && { return this->err.value; }
};  // namespace mmt

}  // namespace mmt

#endif