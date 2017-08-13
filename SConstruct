import os

env = Environment()

gcc = os.getenv("CXX_GCC") or "g++"
clang = os.getenv("CXX_CLANG") or "clang++"

if "TERM" in os.environ:
    env["ENV"]["TERM"] = os.environ["TERM"]
env["ENV"].update(x for x in os.environ.items() if x[0].startswith("CCC_"))

AddOption("--lto", action="store_const", dest="flags", const="-flto")
env.Append(CXXFLAGS=(GetOption("flags") or ""))
is_gcc = "-flto" in env["CXXFLAGS"]

env["CXX"] = gcc if is_gcc else clang
if is_gcc:
    env["AR"] = "gcc-ar"
    env["RANLIB"] = "gcc-ranlib"

suffix = "-lto" if is_gcc else ""

env.Append(CXXFLAGS="-std=c++11 -pedantic -pedantic-errors -Wall -Wextra -Werror -Wconversion -O3")
env.Append(CPPPATH=["include/"])
env.Append(LIBPATH=["."])
env.Append(LIBS=["stackcpp" + suffix, "boost_system", "crypto", "ssl", "boost_iostreams", "pthread"])

env.VariantDir("build/src", "src", duplicate=0)
env.VariantDir("build/test", "test", duplicate=0)
env.VariantDir("build/samples", "samples", duplicate=0)
env.VariantDir("build/utility", "utility", duplicate=0)

env.Library("stackcpp" + suffix, Glob("build/src/*.cpp"))
env.Program("bin/stackcpp-test" + suffix, "build/test/test.cpp")