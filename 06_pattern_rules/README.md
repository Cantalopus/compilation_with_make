# 06: Stage pattern rules

This is a focused reference baseline. There is no need to redo every previous exercise. The next active lesson is **07_build_folders**.

Focus: replace duplicated stage recipes with three patterns. `%` matches a shared filename stem, such as `main` or `helper`. Linking remains explicit. The `main.i helper.i: helper.h` line records the header dependency.

From this directory, use:

```sh
make -r
./example
echo $?
```

Expected status: `12`. `-r` disables built-in implicit rules so the three written patterns control `.c -> .i -> .s -> .o`. `.SECONDARY:` keeps generated intermediates after the build. Continue using `make -r` for this lesson.

Optional dependency check: `touch helper.h`, then `make -r`. Both translation units and the executable should rebuild.
