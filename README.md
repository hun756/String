# String
## The C++ String Library Implementation using Unique Ptr

### Building

Cmake is required to build the project.

```console
mkdir build
cd build

cmake .. -G "Put your options"
```

or you can using ninja build.
```
cmake .. -G ninja

ninja -C build
ninja -C build install
```

### Usage

```cpp
#include <string.hpp>
#include <iostream>

int main() {
    kor::String str {"hi everyone"};

    (void)fprintf(stdout, "%s", str.c_str());
}
```

```cpp
kor::String str {"Put some string here...!"};

for (auto val = str.begin(); val != str.end(); ++val) {
    // make your operations here ...
}

for (auto value = str.rbegin(); value != str.rend(); ++value)
{
    // put your code here..!
}
```

```cpp
auto _val /* : std::unique_ptr<char_type[]> */ = str.toCharArray();

for (size_t i = 0; i < str.size(); ++i) {
    std::cout << _val[i] << std::endl;
}

```

### Compatibility with the standard library.

```cpp

#define ENABLE_COMPABILITY_W_STD_VECTOR
#define ENABLE_COMPABILITY_W_STD_STRING

#include "string.hpp"
// compability with string

kor::String str {"Put some string here...!"};

std::string STDstr = dtr;
// return std::string(str.c_str())

std::vector<char> vecStr = str;
// returns std::vector<char>({...str chars})

```

## LICENSE

MIT License

Copyright (c) 2020 Mehmet Ekemen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.