mkdir build > /dev/nul 2>&1 &
cd build
cmake ..
make
./startRenderer
pwd
cp main.tga ../tools/WebViewer/
