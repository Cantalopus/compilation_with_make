# 05: Static library reuse

This is a focused reference baseline. There is no need to redo every previous exercise. The next active lesson is **07_build_folders**.

Focus: put reusable object files in `libnumbers.a`. Rules remain explicit: every C file passes through `.i`, `.s`, and `.o`. `ar` packages `helper.o` and `extra.o`; the link command places the archive after `main.o`.

From this directory:

```sh
make
ar t libnumbers.a
./example
echo $?
```

The archive lists `helper.o` and `extra.o`; the program status is `12`. `main` needs `get_number`, so the ordinary static link extracts `helper.o`. It does not need the separate `extra.o` member containing the function that returns `99`.

Optional reuse check:

```sh
touch main.c
make
```

Only main’s three compilation stages and the executable link should run; the unchanged archive is reused. No second program is needed for this example.
