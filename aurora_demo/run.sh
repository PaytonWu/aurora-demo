#! /bin/bash

# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

cd capi_lib
rm -rf capi.o libcapi.a
g++ lib.cpp -c -fPIC -o capi.o
ar crs libcapi.a capi.o

cd ../test/
rm -rf libcapi.a t
cp ../capi_lib/libcapi.a .

g++ main.cpp -o t -I . -L. libaurora_engine.so libcapi.a 
./t