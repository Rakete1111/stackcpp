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



#ifndef STACKCPP_TAG_WIKI_HPP
#define STACKCPP_TAG_WIKI_HPP

#include "stackcpp/misc/types.hpp"
#include "stackcpp/objects/shallow_user.hpp"

#include <rapidjson/document.h>
#include <string>



namespace stackcpp {

inline namespace objects { struct tag_wiki; }
tag_wiki parse_tag_wiki(const rapidjson::Value&);



inline namespace objects {
struct tag_wiki final {
    std::string content() const noexcept { return content_; }
    date_t last_content_edit() const noexcept { return last_content_edit_; }
    std::string excerpt() const noexcept { return excerpt_; }
    date_t last_excerpt_edit() const noexcept { return last_excerpt_edit_; }
    shallow_user last_content_editor() const noexcept { return last_content_editor_; }
    shallow_user last_excerpt_editor() const noexcept { return last_excerpt_editor_; }
    std::string name() const noexcept { return name_; }

private:
    friend tag_wiki stackcpp::parse_tag_wiki(const rapidjson::Value&);

    // See [dcl.fct.def.default]/4 and [dcl.init.aggr]/1 for rational.
    tag_wiki() noexcept {}

    std::string content_;
    date_t last_content_edit_;
    std::string excerpt_;
    date_t last_excerpt_edit_;
    shallow_user last_content_editor_;
    shallow_user last_excerpt_editor_;
    std::string name_;
};
}
}

#endif
