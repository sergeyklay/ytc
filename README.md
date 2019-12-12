# YTC

[![Actions Status][actions badge]][actions link]
[![Coverage Status][coverage badge]][coverage link]
[![Codacy Badge][codacy badge]][codacy link]
[![License: MIT][license badge]](./LICENSE)

YTC (a Yaml Template Class example) is an `yaml-cpp` example project.
The main goal of this project is to show a possible strategy to convert user data types using
[yaml-cpp][yaml-cpp link].

This project build with following tools:
- C++ version: `C++17`
- C++ compiler: **Gcc**, **Clang** and **Apple Clang**
- Source: multiple files
- Package manager: [Conan][conan link]
- Build system: [CMake][cmake link]
- Libraries: STL, [`yaml-cpp`][yaml-cpp link]
- Code coverage report: [`lcov`][lcov link]
- [CodeCov][codecov link] (code coverage is measured by CodeCov)
- Testing framework: [Google Tests][gtest link]
- CI: [GitHub Actions][actions feature]

## How to try it out

These instructions will get you a copy of the project up and running on your local machine for
development and testing purposes.

### Prerequisites

To build YTC you need the following requirements:

- A C++ compiler such as [Gcc][gcc link] >= 7.0.0, [Clang][clang link] >= 5.0.0 or [Apple Clang][apple link] >= 10.0.0
- [CMake][cmake link] 3.11 or later
- [Conan][conan link] decentralized package manager with a client-server architecture

To enable test coverage reports you need the following requirements:
- `lcov`
- `genhtml`

For project dependencies list see `conanfile.txt` bundled with this project.

If you're using Ubuntu, you can install the required packages this way:
```shell script
sudo apt install gcc cmake build-essential
```

On macOS you most likely have a compiler so you'll need only cmake:
```shell script
brew install cmake
```

Please note that specific versions of libraries and programs at the time of reading this guide may vary.
The following dependencies is recommended install using [`pip`][pip link]:

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

### Running the tests

Tests expect `YTC_TESTS_ROOT` environment variable to use fixtures. This
variable should point to the tests directory root. Set this variable and
run the tests as follows:

```shell script
export YTC_TESTS_ROOT=$(pwd)/tests
cmake --build build --target check
```

### Generate HTML code coverage report

Follow these steps:

1. Configure with code coverage instrumentation enabled `-DCODE_COVERAGE=ON`
2. Build project
3. Execute the tests to generate the coverage data
4. Generate and customize reports as follows:

```shell script
# Create lcov report
lcov --directory build --capture --output-file ./build/coverage.info

# Filter out extra files
lcov \
    --remove ./build/coverage.info \
    '/usr/*'                       \
    "${HOME}"'/.conan/*'           \
    '*/tests/*'                    \
    --output-file ./build/coverage.info

# Output coverage data for debugging (Optional)
lcov --list ./build/coverage.info

# Create a directory to store HTML report 
mkdir ./build/coverage

# Generate HTML report
genhtml ./build/coverage.info --output-directory ./build/coverage
```

## Further Reading

- [CodeCov documentation][codecov docs]
- [Conan Examples][conan examples]
- [yaml-cpp tutorial][yaml tutor]

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

[actions link]: https://github.com/sergeyklay/ytc/actions
[actions badge]: https://github.com/sergeyklay/ytc/workflows/build/badge.svg
[codecov link]: https://codecov.io
[codecov docs]: https://docs.codecov.io
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
[cmake link]: https://cmake.org
[conan link]: https://conan.io
[conan examples]: https://github.com/conan-io/examples
[pip link]: https://pip.pypa.io
[gtest link]: https://github.com/google/googletest
[actions feature]: https://github.com/features/actions
[lcov link]: http://ltp.sourceforge.net/coverage/lcov.php
