# Contributing

This is for issues (which include bugs and feature requests) and pull requests. If you have any questions, please ask them on IRC freenode #stackcpp or on [stackcpp's post](https://stackapps.com/questions/7521/stackcpp-an-asynchronous-c11-library-for-the-stackexchange-api) on StackApps.

--------

## Bugs

If you want to report a bug make sure that it has not already been reported and/or fixed. Don't forget to also search for issues that are closed, as that specific bug could have already been fixed! After you made sure that it has not been reported yet, you can create a new issue.

It's important that you include every relevant information, like did you compile from source or if not which version are you using. Create a small example illustrating the problem and explain what you think should happen but does not.

## Feature requests

Same as for bugs, make sure that the feature request has not already been created and/or already implemented, and then create a new issue saying which feature you want to see.

## Code

For every pull request there has to be an issue. I'll try to review every pull request as fast as I can and provide feedback. If a pull request isn't active for an extended period of time, it will get closed. It is important that:

- You name commits in a pull request appropriately.
- You do not fix/implement multiple feature requests and/or bugs in a single pull request.
- You try to reduce commits like "Fixed typo", "Fixed typo again" and the like (you can squash them for example).

Any code submitted has to come with appropriate tests (only if applicable) and the code compiled with the Clang Static Analyzer. You also need to see if every test executed properly. Additionally, your code has to run through Clang Format, and adhere to the following style (most of it is checked by Clang Format, but not everything, like whitespace).

```c++
// Boost license text, followed by three empty lines.



// Header guards only for headers, and no #pragma once.
#ifndef STACKCPP_FILE_EXTENSION
#define STACKCPP_FILE_EXTENSION

// For source files, the main header file always comes first.
#include "file.h"

// Next come any includes that are not part of any library, and not already included in the header file.
#include "stackcpp/misc/types.hpp"

// Now come the other includes.
#include <string>
#include <vector>



// Note the three spaces again.
namespace stackcpp {

// No indentation for namespaces, and always leave space above.
// Indentation: Four spaces, absolutely no tabs!
// If you hadn't already noticed, comments have to be grammatically correct, and start with a single space.
// If something is only used in the source file, use an anonymous namespace to make the identifies have internal linkage (don't use static).
namespace {

// Use constexpr as far as possible (C++11 is rather limiting in this aspect).
constexpr int a = 0;



// Identifiers completely unrelated to one another are separated by three lines.
// If a function doesn't/shouldn't throw, mark it with noexcept.
// If the function is small, you can write it in one line.
std::string parse() noexcept {
    return "";
}

// Overloads are related so only one line in-between.
// Always mark variables that should not be modified as const (except return values of course).
std::string parse(const int integer) noexcept {
    return std::to_string(integer);
}
// No blank line here (before the end of any namespace).
}



// Unrelated, so three lines separation above.
// Every class function is considered unrelated and should be separated by three lines.
// If some of them are really the same (like constructors, overloads), separate them with one line.
// Class members have an underscore at the end, except if they are public (then they should not have anything).
foo::foo(const double value) noexcept : value_{value} {}

// No spaces in braced initializer lists.
foo::foo(const double value, const int age) noexcept : value_{value}, age_{age} {}



// Don't use move semantics and/or references for types that are part of the language.
// Only use move semantics if you or someone has to store the parameters.
void foo::move(std::string name, const int age, const std::string& team) noexcept {
    name_ = std::move(name); // Move.
    age_ = age; // No need for move semantics here.

    // No need for move semantics for team.
    if (team == "bar")
        age_ = 0;
}



// Mark functions that do not modify any parameters as const.
int foo::get() const noexcept {
    // Sending request to server...
    return result;
}



// Class definitions in header files only.
// Mark them as final if they shouldn't be used as base classes.
// Use class for an object, and struct for containers (there is no hard rule on this).
class foo {
public:
    // Really small functions can be inlined as follows.
    int get() const noexcept { return value_; }

    // Templates should only be defined in header files if you need to.
    // No space between template and <, always write out parameters (have to be the same in the definition).
    // Template definitions in header files are defined below.
    template<typename T>
    void test(T&& hello, const std::string& name, const int age) const noexcept;

    // Small template function/class/struct signature don't have to have template on a separate line.
    template<typename T> T bar() noexcept;

// Leave a space between different access scopes.
private:
    // Initialize members immediately if possible, using aggregate initialization if default initializing.
    int bar_ = 4;
    int bar2_{};
    // Every member has to be initialized correctly.
};



// Here you should define the templates.
template<typename T>
void foo::test(T&& hello, const std::string& name, const int age) const noexcept {
    // Something...
}



// No trailing spaces allowed, and use spaces appropriately:
// int a=4; This is not allowed.
// int a =4 ; Not allowed.
// Use an editor settings that strips trailing whitespaces (it helps).
template<typename T> T foo::bar() noexcept {
    return static_cast<T>(bar_ = 368);
}



struct container final {
    // No underscore because they are public.
    int data;
    std::string name;

    // Lines should not be longer than 180 characters. If they are, wrap around with eight spaces (this applies to everything).
    std::string really_long_function_name(const std::vector<std::string>& really_important_vector, const std::string& highly_valued_name, const std::string& another_name,
            const int integer) const noexcept;

private:
    // Stars and ampersands always on the type.
    int* pointer_;
};
// No space here, as always.
} // Don't put comments here, put add new line afterwards.

#endif // Same for here, and leave an empty blank line at the end.

```