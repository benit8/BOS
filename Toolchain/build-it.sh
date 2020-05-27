#!/bin/bash
set -e # Exit on any error

BINUTILS_VERSION=2.34
GCC_VERSION=10.1.0

DIR="$( builtin cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TARGET=i386-elf
PREFIX="$DIR/local"
NPROC=${1:-$(nproc)} # First argument or maximum number of cores

mkdir -p "$DIR/tarballs"

pushd "$DIR/tarballs"
	if [ ! -e "binutils-$BINUTILS_VERSION.tar.gz" ]; then
		wget "http://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.gz"
	fi

	if [ ! -e "gcc-$GCC_VERSION.tar.gz" ]; then
		wget "http://ftp.gnu.org/gnu/gcc/gcc-$GCC_VERSION/gcc-$GCC_VERSION.tar.gz"
	fi

	if [ ! -d "binutils-$BINUTILS_VERSION" ]; then
		tar -xf "binutils-$BINUTILS_VERSION.tar.gz"
	fi

	if [ ! -d "gcc-$GCC_VERSION" ]; then
		tar -xf "gcc-$GCC_VERSION.tar.gz"
	fi
popd

mkdir -p $PREFIX
mkdir -p "$DIR/build/binutils"
mkdir -p "$DIR/build/gcc"

pushd "$DIR/build/"
	pushd binutils
		$DIR/tarballs/binutils-$BINUTILS_VERSION/configure \
			--target=$TARGET \
			--prefix=$PREFIX \
			--enable-interwork \
			--enable-multilib \
			--disable-nls \
			--disable-werror
		make -j $NPROC
		make install
	popd

	pushd gcc
		$DIR/tarballs/gcc-$GCC_VERSION/configure \
			--target=$TARGET \
			--prefix=$PREFIX \
			--disable-nls \
			--disable-libssp \
			--enable-languages=c,c++ \
			--without-headers
		make -j $NPROC all-gcc all-target-libgcc
		make install-gcc install-target-libgcc
	popd
popd

echo ""
echo "BOS toolchain built successfully!"
echo "---------------------------------"
echo "Append this to your .bashrc:"
echo "export PATH=\"\$PATH:$PREFIX/bin\""