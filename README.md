# YTC

[![Actions Status][actions badge]][actions link]
[![Coverage Status][coverage badge]][coverage link]
[![Codacy Badge][codacy badge]][codacy link]
[![License: MIT][license badge]](./LICENSE)

YTC is a Yaml Template Class example. The main goal of this project is to show a possible strategy to
convert user data types using [yaml-cpp][yaml-cpp link].

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for
development and testing purposes.

### Prerequisites

To build YTC you need the following requirements:

- A C compiler such as  [Gcc][gcc link] >= 7.0.0, [Clang][clang link] >= 5.0.0 or [Apple Clang][apple link] >= 10.0.0
- [cmake][cmake link] 3.11 or later
- [conan][conan link] decentralized package manager with a client-server architecture

For the full dependency list see `conanfile.txt` file located in the sources root.

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
