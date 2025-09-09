# SimpleGE
Simple game engine/library developed for the sake of development

For now the only dependency is cmake (and everything cmake depends on, including c++ compiler -  for now I'll just assume you've already got it installed)

Build and test with
```console
builder:~$ cmake --preset=debug && cmake --build build/
builder:~$ cd build && ctest
```
