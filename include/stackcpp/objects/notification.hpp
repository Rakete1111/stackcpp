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



#ifndef STACKCPP_NOTIFICATION_HPP
#define STACKCPP_NOTIFICATION_HPP

#include "stackcpp/misc/flags.hpp"
#include "stackcpp/misc/types.hpp"
#include "stackcpp/objects/site.hpp"

#include <rapidjson/document.h>
#include <string>



namespace stackcpp {

inline namespace objects { struct notification; }
notification parse_notification(const rapidjson::Value&);



inline namespace objects {
struct notification final {
    std::string content() const noexcept { return content_; }
    date_t creation() const noexcept { return creation_; }
    bool unread() const noexcept { return unread_; }
    notification_type type() const noexcept { return type_; }
    unique_id post_id() const noexcept { return post_id_; }
    objects::site site() const noexcept { return site_; }

private:
    friend notification stackcpp::parse_notification(const rapidjson::Value&);

    // See [dcl.fct.def.default]/4 and [dcl.init.aggr]/1 for rational.
    notification() noexcept {}

    std::string content_;
    date_t creation_;
    bool unread_{};
    notification_type type_{};
    unique_id post_id_;
    objects::site site_;
};
}
}

#endif
