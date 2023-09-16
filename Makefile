COMPILER = g++
STRIP = strip
UPX = upx
REMOVE = del


clean:
	- $(REMOVE) stvm_test.exe

build: clean
	$(COMPILER) test/stvm_test.cpp \
	-o stvm_test.exe \
	-O2 \
	-std=c++11 \
	-I include/stdc++_implemented \
	-I src/ast \
	-I src/data_type \
	-lm

zip: stvm_test.exe
	$(STRIP) -s stvm_test.exe
	$(UPX) -9 stvm_test.exe

run: stvm_test.exe
	./stvm_test.exe