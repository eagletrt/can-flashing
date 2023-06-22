SHELL := /bin/bash

.PHONY: build

.ONESHELL:
build:
	mkdir -p build
	mkdir -p bin

	cd build
	cmake ..
	make -j${shell nproc}
	cd ..

clean:
	rm -rf ./build ./bin