#include <array>
#include <iostream>
#include <list>
#include <vector>


template <typename T, typename _ = void>
struct is_container : std::false_type {};

template <typename... Ts> struct is_container_helper {};

template <typename T>
struct is_container<
    T, typename std::conditional<
           false,
           is_container_helper<typename T::value_type, typename T::size_type,
                               typename T::iterator, typename T::const_iterator,
                               decltype(std::declval<T>().size()),
                               decltype(std::declval<T>().begin()),
                               decltype(std::declval<T>().end()),
                               decltype(std::declval<T>().cbegin()),
                               decltype(std::declval<T>().cend()),
                               decltype(std::declval<T>().empty())>,
           void>::type> : public std::true_type {};

template <typename Container>
auto operator<<(std::ostream &os, const Container &con) ->
    typename std::enable_if<is_container<Container>::value,
                            std::ostream &>::type {
    if (con.empty())
        return os << "[]";
    auto it = con.cbegin();
    os << '[' << *it++;
    while (it != con.cend())
        os << ", " << *it++;
    return os << ']';
}


int main() {
    std::vector<float> f;
    std::cout << "empty vector: " << f << '\n';

    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "vector: " << vec << '\n';
    
    std::list<int> ls{6, 7, 8};
    std::cout << "list: " << ls << '\n';

    std::array<double, 5> arr{9., 10., 11., 12., 13.};
    std::cout << "array: " << arr << '\n';
}
