# stackcpp

[![Travis CI build status](https://travis-ci.org/Rakete1111/stackcpp.svg?branch=master)](https://travis-ci.org/Rakete1111/stackcpp)

stackcpp is a C++11 asynchronous library for the [StackExchange API](https://api.stackexchange.com/docs).

## Usage

stackcpp is a static library, which relies on Boost. You'll need the following libraries to be able to link your project successfully:

- Boost.Iostreams
- Boost.System
- OpenSSL

In additional to any other libraries your environment might require (for Linux, you also need `pthread` and `crypto`).

Although it is not every day that StackExchange adds new sites to its network, it is possible that the site list of stackcpp becomes out of date. I'll include the site in the next release, but in the mean time, you can execute the `update` utility, which updates the site list if there are any new sites available.

## Examples

If you want to make a request, you need a `stackcpp::client` object. Every request result is wrapped in a [`std::future`](http://en.cppreference.com/w/cpp/thread/future), because every request is asynchronous, you the result might not be available immediately.

Here's an example of the library. More samples are available in the `samples` directory.

```c++
#include <iostream>
#include "stackcpp/client.h"

int main() {
    std::cout << "Input a user id: ";

    stackcpp::unique_id user_id;
    std::cin >> user_id;

    // You need to replace 'api_key' by a valid API key.
    stackcpp::client client{"api_key"};

    auto user = client.users(user_id).get();
    std::cout << user.name() << " has " << user.reputation() << " reputation!\n";
}
```

This example doesn't use the recommended practices of the API, like specifying a filter with only the fields you actually need. The examples in the `samples` directory do however follow every recommended practice, so you should follow them, and not this small example.

It is very highly recommended that you read the Wiki, as it provides a lot of information about common pitfalls using this library and some other stuff.

## Building

There are two different versions of stackcpp for Linux (not for Windows though), one with LTO, and one without. If you want to build without LTO, then you just need to execute

```bash
scons
```

For the LTO build, just specify the `--lto` flag to `scons`.

## Contributing

Thanks for wanting to contribute! If you found a bug or want to see a specific feature, you can create a new issue. For creating pull requests to any part of the library, please see the contributing file.

## Questions?

If you have any questions or enquiries, you can ask them on IRC freenode #stackcpp, or in the comment section of [stackcpp's StackApps post](https://stackapps.com/questions/7521/stackcpp-an-asynchronous-c11-library-for-the-stackexchange-api).
