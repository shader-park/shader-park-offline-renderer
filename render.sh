cat src/head.cpp $1 src/tail.cpp > src/generated/full.cpp
cd build
cmake ..
make
./render
cd ..
