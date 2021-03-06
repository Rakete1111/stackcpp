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



#ifndef STACKCPP_SHALLOW_USER_HPP
#define STACKCPP_SHALLOW_USER_HPP

#include "stackcpp/misc/flags.hpp"
#include "stackcpp/misc/types.hpp"
#include "stackcpp/objects/badge_count.hpp"
#include "stackcpp/objects/user.hpp"

#include <rapidjson/document.h>
#include <string>



namespace stackcpp {

inline namespace objects { struct shallow_user; }
shallow_user parse_shallow_user(const rapidjson::Value&);



inline namespace objects {
struct shallow_user final {
    integer_t accept_rate() const noexcept { return accept_rate_; }
    badge_count badges() const noexcept { return badges_; }
    std::string name() const noexcept { return name_; }
    std::string url() const noexcept { return url_; }
    std::string avatar() const noexcept { return avatar_; }
    integer_t reputation() const noexcept { return reputation_; }
    unique_id id() const noexcept { return id_; }
    user_type type() const noexcept { return type_; }

private:
    friend shallow_user stackcpp::parse_shallow_user(const rapidjson::Value&);
    friend struct comment;
    friend struct answer;
    friend struct badge;
    friend struct question;
    friend struct post;
    friend struct suggested_edit;
    friend struct revision;
    friend struct question_timeline;
    friend struct search_excerpt;
    friend struct tag_score;
    friend struct tag_wiki;

    // See [dcl.fct.def.default]/4 and [dcl.init.aggr]/1 for rational.
    shallow_user() noexcept {};

    integer_t accept_rate_{};
    badge_count badges_;
    std::string name_;
    std::string url_;
    std::string avatar_;
    integer_t reputation_{};
    unique_id id_;
    user_type type_{};
};
}
}

#endif
