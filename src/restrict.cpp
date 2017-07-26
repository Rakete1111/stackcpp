// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.



#include "stackcpp/restrict.h"

#include "stackcpp/misc/types.hpp"

#include <boost/algorithm/string/join.hpp>


namespace stackcpp {

namespace {

constexpr const char* default_filter(const bool safe) noexcept {
    return safe ? "default" : "vqc7J";
}
}



generic_data_t filter(std::string filter) noexcept {
    generic_data_t data;
    data.values_["filter"] = std::move(filter);
    return data;
}

generic_data_t unsafe() noexcept {
    generic_data_t data;
    data.safe_ = false;
    return data;
}

data_t from_date(const date_t& value) noexcept {
    data_t data;
    data.values_["fromdate"] = parse_value(value);
    return data;
}

data_t to_date(const date_t& value) noexcept {
    data_t data;
    data.values_["todate"] = parse_value(value);
    return data;
}

data_t descending() noexcept {
    data_t data;
    data.values_["order"] = "desc";
    return data;
}

data_t ascending() noexcept {
    data_t data;
    data.values_["order"] = "asc";
    return data;
}



search_data_t search(std::string value) noexcept {
    search_data_t data;
    data.values_["q"] = std::move(value);
    return data;
}

search_data_t accepted(const bool value) noexcept {
    search_data_t data;
    data.values_["accepted"] = parse_value(value);
    return data;
}

search_data_t answers(const uinteger_t value) noexcept {
    search_data_t data;
    data.values_["answers"] = std::to_string(value);
    return data;
}

search_data_t body(std::string value) noexcept {
    search_data_t data;
    data.values_["body"] = std::move(value);
    return data;
}

search_data_t closed(const bool value) noexcept {
    search_data_t data;
    data.values_["closed"] = parse_value(value);
    return data;
}

search_data_t migrated(const bool value) noexcept {
    search_data_t data;
    data.values_["migrated"] = parse_value(value);
    return data;
}

search_data_t information(const bool value) noexcept {
    search_data_t data;
    data.values_["notice"] = parse_value(value);
    return data;
}

search_data_t nottagged(const std::vector<std::string>& values) noexcept {
    search_data_t data;
    data.values_["nottagged"] = boost::algorithm::join(values, delimiter);
    return data;
}

search_data_t nottagged(std::string value) noexcept {
    search_data_t data;
    data.values_["nottagged"] = std::move(value);
    return data;
}

search_data_t tagged(const std::vector<std::string>& values) noexcept {
    search_data_t data;
    data.values_["tagged"] = boost::algorithm::join(values, delimiter);
    return data;
}

search_data_t tagged(std::string value) noexcept {
    search_data_t data;
    data.values_["tagged"] = std::move(value);
    return data;
}

search_data_t title(std::string value) noexcept {
    search_data_t data;
    data.values_["title"] = std::move(value);
    return data;
}

search_data_t owner(const unique_id value) noexcept {
    search_data_t data;
    data.values_["user"] = std::to_string(value);
    return data;
}

search_data_t url(std::string value) noexcept {
    search_data_t data;
    data.values_["url"] = std::move(value);
    return data;
}

search_data_t views(const uinteger_t value) noexcept {
    search_data_t data;
    data.values_["views"] = std::to_string(value);
    return data;
}

search_data_t wiki(const bool value) noexcept {
    search_data_t data;
    data.values_["wiki"] = parse_value(value);
    return data;
}



void generic_data_t::try_assign(const generic_data_t& other) noexcept {
    safe_ |= other.safe_;

    auto it = other.values_.end();
    if ((it = other.values_.find("filter")) != other.values_.end())
        values_["filter"] = it->second;
}



map_t generic_data_t::as_map() const noexcept {
    auto it = values_.end();
    if ((it = values_.find("filter")) != values_.end())
        return values_;
    return {{"filter", default_filter(safe_)}};
}



data_t::data_t(generic_data_t value) noexcept : generic_data_t{std::move(value)} {}



data_t& data_t::operator|=(const generic_data_t& rhs) noexcept {
    try_assign(rhs);
    return *this;
}

data_t& data_t::operator|=(const data_t& rhs) noexcept {
    try_assign(rhs);

    auto it = rhs.values_.end();

    if ((it = rhs.values_.find("min")) != rhs.values_.end())
        values_["min"] = it->second;
    if ((it = rhs.values_.find("max")) != rhs.values_.end())
        values_["max"] = it->second;
    if ((it = rhs.values_.find("fromdate")) != rhs.values_.end())
        values_["fromdate"] = it->second;
    if ((it = rhs.values_.find("todate")) != rhs.values_.end())
        values_["todate"] = it->second;
    if ((it = rhs.values_.find("order")) != rhs.values_.end())
        values_["order"] = it->second;

    return *this;
}



map_t data_t::as_map() const noexcept {
    map_t map = generic_data_t::as_map();
    map.insert(values_.cbegin(), values_.cend());
    return map;
}



search_data_t::search_data_t(generic_data_t value) noexcept : generic_data_t{std::move(value)} {}



search_data_t& search_data_t::operator|=(const generic_data_t& rhs) noexcept {
    try_assign(rhs);
    return *this;
}

search_data_t& search_data_t::operator|=(const search_data_t& rhs) noexcept {
    try_assign(rhs);

    auto it = rhs.values_.end();

    if ((it = rhs.values_.find("q")) != rhs.values_.end())
        values_["q"] = it->second;
    if ((it = rhs.values_.find("accepted")) != rhs.values_.end())
        values_["accepted"] = it->second;
    if ((it = rhs.values_.find("answers")) != rhs.values_.end())
        values_["answers"] = it->second;
    if ((it = rhs.values_.find("body")) != rhs.values_.end())
        values_["body"] = it->second;
    if ((it = rhs.values_.find("closed")) != rhs.values_.end())
        values_["closed"] = it->second;
    if ((it = rhs.values_.find("migrated")) != rhs.values_.end())
        values_["migrated"] = it->second;
    if ((it = rhs.values_.find("notice")) != rhs.values_.end())
        values_["notice"] = it->second;
    if ((it = rhs.values_.find("nottagged")) != rhs.values_.end())
        values_["nottagged"] = it->second;
    if ((it = rhs.values_.find("tagged")) != rhs.values_.end())
        values_["tagged"] = it->second;
    if ((it = rhs.values_.find("title")) != rhs.values_.end())
        values_["title"] = it->second;
    if ((it = rhs.values_.find("user")) != rhs.values_.end())
        values_["user"] = it->second;
    if ((it = rhs.values_.find("url")) != rhs.values_.end())
        values_["url"] = it->second;
    if ((it = rhs.values_.find("views")) != rhs.values_.end())
        values_["views"] = it->second;
    if ((it = rhs.values_.find("wiki")) != rhs.values_.end())
        values_["wiki"] = it->second;
    return *this;
}



map_t search_data_t::as_map() const noexcept {
    map_t map = generic_data_t::as_map();
    map.insert(values_.cbegin(), values_.cend());
    return map;
}



template<typename T, typename U>
restrict<T, U, typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value>::type>::restrict(T sort) noexcept : sort_{std::move(sort)} {}

template<typename T, typename U>
restrict<T, U, typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value>::type>::restrict(U data) noexcept : data_{std::move(data)} {}

template<typename T, typename U>
restrict<T, U, typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value>::type>::restrict(generic_data_t data) noexcept : data_{std::move(data)} {}



template<typename T, typename U> map_t restrict<T, U, typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value>::type>::as_map() const noexcept {
    map_t map = data_.as_map();
    map.emplace(std::make_pair("sort", parse_enum(sort_)));
    return map;
}



template<typename T, typename U>
restrict<T, U, typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value>::type>&
        restrict<T, U, typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value>::type>::operator|=(const restrict& rhs) noexcept {
    data_ |= rhs.data_;
    return *this;
}



generic_data_t operator|(generic_data_t lhs, const generic_data_t& rhs) noexcept {
    lhs.try_assign(rhs);
    return lhs;
}

data_t operator|(data_t lhs, const data_t& rhs) noexcept {
    return lhs |= rhs;
}

search_data_t operator|(search_data_t lhs, const search_data_t& rhs) noexcept {
    return lhs |= rhs;
}

data_t operator|(data_t lhs, const generic_data_t& rhs) noexcept {
    return lhs |= rhs;
}

data_t operator|(const generic_data_t& lhs, data_t rhs) noexcept {
    return rhs |= lhs;
}

search_data_t operator|(search_data_t lhs, const generic_data_t& rhs) noexcept {
    return lhs |= rhs;
}

search_data_t operator|(const generic_data_t& lhs, search_data_t rhs) noexcept {
    return rhs |= lhs;
}



template<typename T, typename U> restrict<T, U> operator|(restrict<T, U> lhs, const restrict<T, U>& rhs) noexcept {
    return lhs |= rhs;
}

template<typename T, typename U>
typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value, restrict<T, sort_data_t<T>>>::type operator|(T lhs, const U& rhs) noexcept {
    return restrict<T, sort_data_t<T>>{std::move(lhs)} |= rhs;
}

template<typename T, typename U>
typename std::enable_if<std::is_enum<T>::value && is_valid_data<U>::value, restrict<T, sort_data_t<T>>>::type operator|(const U& lhs, T rhs) noexcept {
    return restrict<T, sort_data_t<T>>{std::move(rhs)} |= lhs;
}

template<typename T, typename U> restrict<T, U> operator|(restrict<T, U> lhs, const U& rhs) noexcept {
    return lhs |= rhs;
}

template<typename T, typename U> restrict<T, U> operator|(const U& lhs, restrict<T, U> rhs) noexcept {
    return rhs |= lhs;
}



// Template instantiations, because we know which types are going to be used with them.
// It's better to increase compilation time for this library than to do it for the users.
// This sacrifice unfortunately includes a large amount of duplication. :(
template class restrict<user_sort, data_t>;
template class restrict<answer_sort, data_t>;
template class restrict<badge_sort, data_t>;
template class restrict<comment_sort, data_t>;
template class restrict<favorite_sort, data_t>;
template class restrict<activity_sort, data_t>;
template class restrict<post_sort, data_t>;
template class restrict<question_sort, data_t>;
template class restrict<suggested_edit_sort, data_t>;
template class restrict<tag_sort, data_t>;
template class restrict<search_sort, search_data_t>;
template class restrict<synonym_sort, data_t>;

template restrict<user_sort, data_t> operator|(restrict<user_sort, data_t>, const restrict<user_sort, data_t>&) noexcept;
template restrict<answer_sort, data_t> operator|(restrict<answer_sort, data_t>, const restrict<answer_sort, data_t>&) noexcept;
template restrict<badge_sort, data_t> operator|(restrict<badge_sort, data_t>, const restrict<badge_sort, data_t>&) noexcept;
template restrict<comment_sort, data_t> operator|(restrict<comment_sort, data_t>, const restrict<comment_sort, data_t>&) noexcept;
template restrict<favorite_sort, data_t> operator|(restrict<favorite_sort, data_t>, const restrict<favorite_sort, data_t>&) noexcept;
template restrict<activity_sort, data_t> operator|(restrict<activity_sort, data_t>, const restrict<activity_sort, data_t>&) noexcept;
template restrict<post_sort, data_t> operator|(restrict<post_sort, data_t>, const restrict<post_sort, data_t>&) noexcept;
template restrict<question_sort, data_t> operator|(restrict<question_sort, data_t>, const restrict<question_sort, data_t>&) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(restrict<suggested_edit_sort, data_t>, const restrict<suggested_edit_sort, data_t>&) noexcept;
template restrict<tag_sort, data_t> operator|(restrict<tag_sort, data_t>, const restrict<tag_sort, data_t>&) noexcept;
template restrict<search_sort, search_data_t> operator|(restrict<search_sort, search_data_t>, const restrict<search_sort, search_data_t>&) noexcept;
template restrict<synonym_sort, data_t> operator|(restrict<synonym_sort, data_t>, const restrict<synonym_sort, data_t>&) noexcept;

template restrict<user_sort, data_t> operator|(user_sort, const data_t&) noexcept;
template restrict<answer_sort, data_t> operator|(answer_sort, const data_t&) noexcept;
template restrict<badge_sort, data_t> operator|(badge_sort, const data_t&) noexcept;
template restrict<comment_sort, data_t> operator|(comment_sort, const data_t&) noexcept;
template restrict<favorite_sort, data_t> operator|(favorite_sort, const data_t&) noexcept;
template restrict<activity_sort, data_t> operator|(activity_sort, const data_t&) noexcept;
template restrict<post_sort, data_t> operator|(post_sort, const data_t&) noexcept;
template restrict<question_sort, data_t> operator|(question_sort, const data_t&) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(suggested_edit_sort, const data_t&) noexcept;
template restrict<tag_sort, data_t> operator|(tag_sort, const data_t&) noexcept;
template restrict<search_sort, search_data_t> operator|(search_sort, const search_data_t&) noexcept;
template restrict<synonym_sort, data_t> operator|(synonym_sort, const data_t&) noexcept;

template restrict<user_sort, data_t> operator|(const data_t&, user_sort) noexcept;
template restrict<answer_sort, data_t> operator|(const data_t&, answer_sort) noexcept;
template restrict<badge_sort, data_t> operator|(const data_t&, badge_sort) noexcept;
template restrict<comment_sort, data_t> operator|(const data_t&, comment_sort) noexcept;
template restrict<favorite_sort, data_t> operator|(const data_t&, favorite_sort) noexcept;
template restrict<activity_sort, data_t> operator|(const data_t&, activity_sort) noexcept;
template restrict<post_sort, data_t> operator|(const data_t&, post_sort) noexcept;
template restrict<question_sort, data_t> operator|(const data_t&, question_sort) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(const data_t&, suggested_edit_sort) noexcept;
template restrict<tag_sort, data_t> operator|(const data_t&, tag_sort) noexcept;
template restrict<search_sort, search_data_t> operator|(const search_data_t&, search_sort) noexcept;
template restrict<synonym_sort, data_t> operator|(const data_t&, synonym_sort) noexcept;

template restrict<user_sort, data_t> operator|(restrict<user_sort, data_t>, const data_t&) noexcept;
template restrict<answer_sort, data_t> operator|(restrict<answer_sort, data_t>, const data_t&) noexcept;
template restrict<badge_sort, data_t> operator|(restrict<badge_sort, data_t>, const data_t&) noexcept;
template restrict<comment_sort, data_t> operator|(restrict<comment_sort, data_t>, const data_t&) noexcept;
template restrict<favorite_sort, data_t> operator|(restrict<favorite_sort, data_t>, const data_t&) noexcept;
template restrict<activity_sort, data_t> operator|(restrict<activity_sort, data_t>, const data_t&) noexcept;
template restrict<post_sort, data_t> operator|(restrict<post_sort, data_t>, const data_t&) noexcept;
template restrict<question_sort, data_t> operator|(restrict<question_sort, data_t>, const data_t&) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(restrict<suggested_edit_sort, data_t>, const data_t&) noexcept;
template restrict<tag_sort, data_t> operator|(restrict<tag_sort, data_t>, const data_t&) noexcept;
template restrict<search_sort, search_data_t> operator|(restrict<search_sort, search_data_t>, const search_data_t&) noexcept;
template restrict<synonym_sort, data_t> operator|(restrict<synonym_sort, data_t>, const data_t&) noexcept;

template restrict<user_sort, data_t> operator|(const data_t&, restrict<user_sort, data_t>) noexcept;
template restrict<answer_sort, data_t> operator|(const data_t&, restrict<answer_sort, data_t>) noexcept;
template restrict<badge_sort, data_t> operator|(const data_t&, restrict<badge_sort, data_t>) noexcept;
template restrict<comment_sort, data_t> operator|(const data_t&, restrict<comment_sort, data_t>) noexcept;
template restrict<favorite_sort, data_t> operator|(const data_t&, restrict<favorite_sort, data_t>) noexcept;
template restrict<activity_sort, data_t> operator|(const data_t&, restrict<activity_sort, data_t>) noexcept;
template restrict<post_sort, data_t> operator|(const data_t&, restrict<post_sort, data_t>) noexcept;
template restrict<question_sort, data_t> operator|(const data_t&, restrict<question_sort, data_t>) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(const data_t&, restrict<suggested_edit_sort, data_t>) noexcept;
template restrict<tag_sort, data_t> operator|(const data_t&, restrict<tag_sort, data_t>) noexcept;
template restrict<search_sort, search_data_t> operator|(const search_data_t&, restrict<search_sort, search_data_t>) noexcept;
template restrict<synonym_sort, data_t> operator|(const data_t&, restrict<synonym_sort, data_t>) noexcept;

template restrict<user_sort, data_t> operator|(user_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<answer_sort, data_t> operator|(answer_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<badge_sort, data_t> operator|(badge_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<comment_sort, data_t> operator|(comment_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<favorite_sort, data_t> operator|(favorite_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<activity_sort, data_t> operator|(activity_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<post_sort, data_t> operator|(post_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<question_sort, data_t> operator|(question_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(suggested_edit_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<tag_sort, data_t> operator|(tag_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<search_sort, search_data_t> operator|(search_sort lhs, const generic_data_t& rhs) noexcept;
template restrict<synonym_sort, data_t> operator|(synonym_sort lhs, const generic_data_t& rhs) noexcept;

template restrict<user_sort, data_t> operator|(const generic_data_t& lhs, user_sort rhs) noexcept;
template restrict<answer_sort, data_t> operator|(const generic_data_t& lhs, answer_sort rhs) noexcept;
template restrict<badge_sort, data_t> operator|(const generic_data_t& lhs, badge_sort rhs) noexcept;
template restrict<comment_sort, data_t> operator|(const generic_data_t& lhs, comment_sort rhs) noexcept;
template restrict<favorite_sort, data_t> operator|(const generic_data_t& lhs, favorite_sort rhs) noexcept;
template restrict<activity_sort, data_t> operator|(const generic_data_t& lhs, activity_sort rhs) noexcept;
template restrict<post_sort, data_t> operator|(const generic_data_t& lhs, post_sort rhs) noexcept;
template restrict<question_sort, data_t> operator|(const generic_data_t& lhs, question_sort rhs) noexcept;
template restrict<suggested_edit_sort, data_t> operator|(const generic_data_t& lhs, suggested_edit_sort rhs) noexcept;
template restrict<tag_sort, data_t> operator|(const generic_data_t& lhs, tag_sort rhs) noexcept;
template restrict<search_sort, search_data_t> operator|(const generic_data_t& lhs, search_sort rhs) noexcept;
template restrict<synonym_sort, data_t> operator|(const generic_data_t& lhs, synonym_sort rhs) noexcept;
}
