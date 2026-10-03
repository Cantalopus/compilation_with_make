# 03: Separate compilation baseline

This is a focused reference baseline.

Focuses on: explicit rules for two translation units. Each follows `.c -> .i -> .s -> .o`; linking combines the two objects into `example`. The executable is the first target.

From this directory, run `make`. A first build shows six compilation-stage commands and one link command. A second `make` reports the executable is up to date.

Run the program and check its status immediately:

```sh
./example
echo $?
```

Expected status: `12`. The program prints nothing. `echo $?` after Make reports Make’s status instead.
