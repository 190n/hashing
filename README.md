hashing
=======

This is a C project to compare hash functions. I might rewrite it in Zig at some point. Right now the only hash it knows is [one that simply XORs everything together](./xor.c). Compile with `make` and run `./hashing <text>` to see, on average, what fraction of the output bits are flipped by changing one bit of that input.

```sh
$ ./hashing monke
0.648438
```

I haven't (yet) checked that this value is actually correct. There will hopefully be more here soon.

![a man with a beret and a paintbrush](./artistraf.png)

Hash functions I should try:

- [ ] [FNV-1a](https://craftinginterpreters.com/hash-tables.html#hashing-strings)
- [ ] [djb2](https://theartincode.stanis.me/008-djb2/)
- [ ] SPECK (implementation from CSE 13S)
- [ ] various ones from openssl/zig crypto (at least crc32, md5, sha1, sha256)
