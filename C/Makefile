#!/usr/bin/env make -f
#
# Copyright (C) 2019 Dream Property GmbH, Germany
#                    https://dreambox.de/
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

CFLAGS = $(shell pkg-config --cflags libcrypto) -Wall -Werror -ggdb
CPPFLAGS = -Iinclude
LDLIBS = $(shell pkg-config --libs libcrypto)

example: buffer.o tpm_crypt.o tpmd_socket.o random.o

.PHONY: random.bin
random.bin:
	dd if=/dev/urandom bs=32 count=1 >$@ 2>/dev/null

%.o: %.bin
	$(LD) -r -b binary -o $@ $^

clean:
	$(RM) $(wildcard *.bin *.o example)
