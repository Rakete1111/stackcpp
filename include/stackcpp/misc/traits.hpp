#ifndef STACKCPP_TRAITS_HPP
#define STACKCPP_TRAITS_HPP

#include "stackcpp/misc/types.hpp"

#include <type_traits>



namespace stackcpp {

struct generic_data_t;
struct data_t;
struct search_data_t;



template<typename T, typename = void> struct is_valid_data final { static constexpr bool value = false; };

// Workaround for the fact that generic_data_t's as_map() is protected.
template<> struct is_valid_data<generic_data_t> final { static constexpr bool value = true; };

template<typename T> struct is_valid_data<T, decltype(std::declval<T>().as_map(), void())> final { static constexpr bool value = true; };



template<typename T> struct sort_data final { using type = data_t; };

template<> struct sort_data<search_sort> final { using type = search_data_t; };

template<typename T> using sort_data_t = typename sort_data<T>::type;
}

#endif
