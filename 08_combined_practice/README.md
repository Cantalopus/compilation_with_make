# 08: Combined practice

Cumulative practice using skills already covered: folders, variables, automatic variables, explicit header dependencies, stage patterns, static archives, `all`, `clean`, and `.SECONDARY`. No new Make feature is introduced. Lesson 07 stays unchanged.

`Makefile` starts empty for your reconstruction. `Makefile.reference` is a complete comparison copy. Run commands from this lesson directory; use `make -r` consistently so built-in rules cannot bypass your stages.

## Rebuild checklist

- Set `CC = gcc`; make `all` the default goal and mark `all clean` phony.
- Keep each source's `.c -> .i -> .s -> .o` stages visible under mirrored `build/app/` and `build/lib/` folders.
- Use separate app/lib preprocessing patterns and known `mkdir -p` paths; use automatic variables in recipes.
- Share the assembly and object patterns. In `build/%.s`, the stem can be `app/main` or `lib/helper`; the prerequisite becomes `build/app/main.i` or `build/lib/helper.i`.
- Record the header prerequisite for all three `.i` targets; all three sources include it.
- Keep intermediates with `.SECONDARY:`.
- Archive only `build/lib/helper.o` and `build/lib/extra.o` into `build/libnumbers.a`.
- Link `build/app/main.o` before the archive to produce `bin/example`.
- Make `clean` remove only this lesson's `build` and `bin` directories.

The source includes use the same relative-path approach as lesson 07. The preprocessing recipes create output directories before the later stages use them.

## Predict, then check

1. Which files should the archive contain? Does it contain `main.o`?
2. When main calls only `get_number()`, which archive member is needed?
3. After changing only main, which stages rebuild and is the archive rebuilt?
4. What changes when main returns `get_number() + extra_number()`?

After reconstructing your Makefile:

```sh
make -r
./bin/example
echo $?
ar t build/libnumbers.a
nm bin/example
make -r
```

Expected: program status `12`, archive members `helper.o` and `extra.o`, and the executable's symbols include `get_number` but not `extra_number`. The program prints nothing. The second Make invocation needs no build recipes. Check `echo $?` immediately after running the program.

For the reference build, substitute `make -r -f Makefile.reference` for `make -r`. Both Makefiles use the same outputs.

Change main's return expression to `get_number() + extra_number()`, then:

```sh
make -r
./bin/example
echo $?
nm bin/example
```

Expected: main's stages and linking rerun, the unchanged archive is reused, the program status is `111`, and both function symbols appear in the executable.

Optional fresh-start check: `make -r clean`, then `make -r`. With the reference, use `make -r -f Makefile.reference clean` and `make -r -f Makefile.reference`. These commands remove and rebuild only generated output folders.
