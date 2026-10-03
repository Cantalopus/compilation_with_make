# 07: Build output folders — next active lesson

This is a focused reference baseline. There is no need to redo every previous exercise. The next active lesson is **07_build_folders**.

Focus: keep sources at the lesson root and put generated files elsewhere. The explicit rules produce `.i`, `.s`, and `.o` files under `build/`, then link `bin/example`. Each recipe uses `mkdir -p` for its output directory; it also succeeds when that directory already exists.

From this directory:

```sh
make
./bin/example
echo $?
```

Expected status: `12`. A first build creates `build/` and `bin/`; a second `make` reports the executable is up to date. The source files stay at the root. Follow the paths in one rule at a time; no archives or pattern rules are involved.
