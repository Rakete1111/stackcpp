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



#ifndef STACKCPP_FLAG_OPTION_HPP
#define STACKCPP_FLAG_OPTION_HPP

#include "stackcpp/misc/types.hpp"

#include <rapidjson/document.h>
#include <string>
#include <vector>



namespace stackcpp {

inline namespace objects { struct flag_option; }
flag_option parse_flag_option(const rapidjson::Value&);



inline namespace objects {
struct flag_option final {
    integer_t count() const noexcept { return count_; }
    std::string description() const noexcept { return description_; }
    std::string dialog_title() const noexcept { return dialog_title_; }
    bool has_flagged() const noexcept { return has_flagged_; }
    unique_id id() const noexcept { return id_; }
    bool requires_comment() const noexcept { return requires_comment_; }
    bool requires_question_id() const noexcept { return requires_question_id_; }
    bool requires_site() const noexcept { return requires_site_; }
    std::vector<flag_option> sub_flags() const noexcept { return sub_flags_; }
    std::string title() const noexcept { return title_; }

private:
    friend flag_option stackcpp::parse_flag_option(const rapidjson::Value&);

    // See [dcl.fct.def.default]/4 and [dcl.init.aggr]/1 for rational.
    flag_option() noexcept {}

    integer_t count_{};
    std::string description_;
    std::string dialog_title_;
    bool has_flagged_{};
    unique_id id_;
    bool requires_comment_{};
    bool requires_question_id_{};
    bool requires_site_{};
    std::vector<flag_option> sub_flags_;
    std::string title_;
};
}
}
#endif
