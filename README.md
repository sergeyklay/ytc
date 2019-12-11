# YTC

[![Actions Status][actions badge]][actions link]
[![Coverage Status][coverage badge]][coverage link]
[![Codacy Badge][codacy badge]][codacy link]
[![License: MIT][license badge]](./LICENSE)

YTC (a Yaml Template Class example) is an `yaml-cpp` example project.
The main goal of this project is to show a possible strategy to convert user data types using
[yaml-cpp][yaml-cpp link].

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for
development and testing purposes.

### Prerequisites

To build YTC you need the following requirements:

- A C compiler such as  [Gcc][gcc link] >= 7.0.0, [Clang][clang link] >= 5.0.0 or [Apple Clang][apple link] >= 10.0.0
- [cmake][cmake link] 3.11 or later
- [conan][conan link] decentralized package manager with a client-server architecture

For the full dependency list see `conanfile.txt` file located in the sources root.

If you're using Ubuntu, you can install the required packages this way:
```shell script
sudo apt install gcc cmake pkg-config build-essential
```

On macOS you will need to use brew with a command as follows:
```shell script
brew install cmake pkg-config
```

Please note that specific versions of libraries and programs at the time of reading this guide may vary.
The following dependencies is recommended install using [`pip`](https://pip.pypa.io):

- `conan`

They can be installed using pip as follows:

```shell script
pip install -r requirements.txt
```

### Building

First you'll need clone the project and fetch its modules:

```shell script
git clone https://github.com/sergeyklay/ytc
cd ytc
```

Then build project as follows:

```shell script
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Most likely, with clang 5.0 on Linux you'll need to specify `libstdc++`.
Use `_GLIBCXX_USE_CXX11_ABI` as follows:

```shell script
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug -D_GLIBCXX_USE_CXX11_ABI=ON
cmake --build build
```

## Running the tests

Tests expect `YTC_TESTS_ROOT` environment variable to use fixtures. This
variable should point to the test directory root. Set this variable and
run the tests as follows:

```shell script
export YTC_TESTS_ROOT=$(pwd)/tests
cmake --build build --target check
```

## Further Reading

- [Conan Examples][conan examples]
- [yaml-cpp tutorial][yaml tutor]

[actions link]: https://github.com/sergeyklay/ytc/actions
[actions badge]: https://github.com/sergeyklay/ytc/workflows/build/badge.svg
[coverage badge]: https://codecov.io/gh/sergeyklay/ytc/branch/master/graph/badge.svg
[coverage link]: https://codecov.io/gh/sergeyklay/ytc
[codacy badge]: https://api.codacy.com/project/badge/Grade/158b7d0c184147ce9d13e087f1983b6c
[codacy link]:  https://www.codacy.com/manual/klay/ytc?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=sergeyklay/ytc&amp;utm_campaign=Badge_Grade
[license badge]: https://img.shields.io/badge/License-MIT-blue.svg
[yaml-cpp link]: https://github.com/jbeder/yaml-cpp
[yaml tutor]: https://github.com/jbeder/yaml-cpp/wiki/Tutorial
[gcc link]: https://gcc.gnu.org
[clang link]: https://clang.llvm.org
[apple link]: https://apps.apple.com/us/app/xcode/id497799835
[cmake link]: https://cmake.org/
[conan link]: https://conan.io
[conan examples]: https://github.com/conan-io/examples
