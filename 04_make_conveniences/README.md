# 04: Make conveniences

This is a focused reference baseline. There is no need to redo every previous exercise. The next active lesson is **07_build_folders**.

Focus: shorten the same explicit build rules. `CC` names the compiler; `$@` is the target, `$<` the first prerequisite, and `$^` all prerequisites. The `.c -> .i -> .s -> .o -> executable` stages stay visible.

`all` groups the default build. `.PHONY` marks `all` and `clean` as actions rather than files.

From this directory:

```sh
make all
./example
echo $?
make clean
```

Expected status: `12`. `clean` removes only the named generated files; sources remain. `make` builds them again. To select a compiler, use `make CC=gcc`.
