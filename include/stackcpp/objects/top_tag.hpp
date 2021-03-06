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



#ifndef STACKCPP_TOP_TAG_HPP
#define STACKCPP_TOP_TAG_HPP

#include "stackcpp/misc/types.hpp"

#include <rapidjson/document.h>
#include <string>



namespace stackcpp {

inline namespace objects { struct top_tag; }
top_tag parse_top_tag(const rapidjson::Value&);



inline namespace objects {
struct top_tag final {
    integer_t answers() const noexcept { return answers_; }
    integer_t answer_score() const noexcept { return answer_score_; }
    integer_t questions() const noexcept { return questions_; }
    integer_t question_score() const noexcept { return question_score_; }
    std::string name() const noexcept { return name_; }
    unique_id user_id() const noexcept { return user_id_; }

private:
    friend top_tag stackcpp::parse_top_tag(const rapidjson::Value&);

    // See [dcl.fct.def.default]/4 and [dcl.init.aggr]/1 for rational.
    top_tag() noexcept {}

    integer_t answers_{};
    integer_t answer_score_{};
    integer_t questions_{};
    integer_t question_score_{};
    std::string name_;
    unique_id user_id_;
};
}
}

#endif
