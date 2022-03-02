hashing
=======

This is a C project to compare hash functions. I might rewrite it in Zig at some point. Right now the only hash it knows is [one that simply XORs everything together](./xor.c). Compile with `make` and run `./hashing <text>` to see, on average, what fraction of the output bits are flipped by changing one bit of that input.

```sh
$ ./hashing monke
0.648438
```

I haven't (yet) checked that this value is actually correct. There will hopefully be more here soon.

![a man with a beret and a paintbrush](./artistraf.png)
