import os

env = Environment()

if "TERM" in os.environ:
    env["ENV"]["TERM"] = os.environ["TERM"]
env["ENV"].update(x for x in os.environ.items() if x[0].startswith("CCC_"))

AddOption("--lto", action="store_const", dest="flags", const="-flto")
env.Append(CXXFLAGS=(GetOption("flags") or ""))
env["CXX"] = "g++" if "-flto" in env["CXXFLAGS"] else "clang++"

suffix = "-lto" if "-flto" in env["CXXFLAGS"] else ""

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