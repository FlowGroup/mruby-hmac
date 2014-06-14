mruby-hmac
==========

mruby GEM for HMAC-SHA-256/512 without any external dependencies

## Features

- Message Digest HMAC-SHA-256/512
- no external dependencies

## Usage

```ruby
key = "Jefe"
msg = "what do ya want for nothing?"

HMAC.sha256(key, msg)
# => "5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843"

HMAC.sha512(key, msg)
# => "164b7a7bfcf819e2e395fbe73b56e0a387bd64222e831fd610270cd7ea2505549758bf75c05a994a6d034f65f8f0e6fdcaeab1a34d4a6b4b636e070a38bce737"
```

## License

The SHA and HMAC Implementation is based on code from Olivier Gay:

Copyright (C) 2005 Olivier Gay <olivier.gay@a3.epfl.ch>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of the project nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.

The mruby GEM boilerplate code is licensed in the same way.

## Alternatives

This mruby GEM was created to provide HMAC Alghorithm without external dependencies. 
For a more featureful alternative with a dependency to libcrypto see:
  - mruby-digest (https://github.com/iij/mruby-digest)
