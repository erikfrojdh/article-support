# article-support

Small code sample that are featured on erikfrojdh.com. 

### build

The examples are located in src/ and can be built directly 
using 
```bash
g++ source.cpp -std=c++[version].
```

To build all examples and the tests use cmake 

```bash
git clone https://github.com/erikfrojdh/article-support.git
mkdir build
cd build
cmake ../article-support
make -j4
```