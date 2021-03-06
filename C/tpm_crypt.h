/*
 * Copyright (C) 2019 Dream Property GmbH, Germany
 *                    https://dreambox.de/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _tpm_crypt_h
#define _tpm_crypt_h

#include <stdbool.h>

/* crypto helper functions (V1) */
bool tpm_decrypt(unsigned char dest[128],
                 const unsigned char *src, unsigned int len,
                 const unsigned char mod[128]);
bool tpm_validate_cert(unsigned char dest[128],
                       const unsigned char *src, unsigned int len,
                       const unsigned char mod[128]);

/* crypto helper functions (V2) */
bool tpm2_validate_cert(const unsigned char *ca,
                        unsigned int calen,
                        const unsigned char *ica,
                        unsigned int icalen,
                        const unsigned char *leaf,
                        unsigned int leaflen);

#endif
