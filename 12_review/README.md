# Exercise 12: review with a larger source tree

Write the Makefile yourself, using the concepts from exercise 11.
The source files are supplied and ready to compile. There is no Makefile or
reference solution in this folder.

This project has nine C source files, four headers, two static libraries,
and three programs. The programs use invented stock and order counts and
return small totals as exit statuses. They do not print anything.

## Start here

1. Inspect the source tree and the includes in each C file.
2. Identify which sources belong to each library and each program.
3. Sketch the relationships between source files, objects, archives, and programs.
4. Write your Makefile. Build and inspect the results as you go.

Use the same explicit pipeline for every C source:

`.c -> .i -> .s -> .o`

At preprocessing, also generate a `.d` file describing the prerequisites
of the corresponding `.i` target. Read those files from the Makefile.

## Source locations

| Directory | Files |
| --- | --- |
| `src/apps/reports` | `stock_report.c`, `order_report.c` |
| `src/apps/checks` | `balance_check.c` |
| `src/lib/stock/panels` | `panel_stock.c` |
| `src/lib/stock/hardware` | `bolt_stock.c`, `nut_stock.c` |
| `src/lib/stock/include` | `stock.h`, `stock_levels.h` |
| `src/lib/orders/panels` | `panel_order.c` |
| `src/lib/orders/hardware` | `bolt_order.c`, `nut_order.c` |
| `src/lib/orders/include` | `orders.h`, `order_sizes.h` |

The headers already have include guards. You can use them as supplied.
Both header directories need to be available to preprocessing. You may use
more than one header search option in your existing preprocessor-flags variable.

Every C source has a different basename, so a flat `build` directory works:
for example, `src/lib/stock/panels/panel_stock.c` produces
`build/panel_stock.i`, `.s`, `.o`, and `.d`.

## Required libraries

| Archive | Object members |
| --- | --- |
| `build/libstock.a` | `panel_stock.o`, `bolt_stock.o`, `nut_stock.o` |
| `build/liborders.a` | `panel_order.o`, `bolt_order.o`, `nut_order.o` |

All object files live in `build`. Neither archive contains an application's
object file. The two libraries are independent: neither calls the other.

## Required programs

| Executable | Application object | Libraries | Expected exit status |
| --- | --- | --- | --- |
| `bin/stock_report` | `build/stock_report.o` | `build/libstock.a` | 120 |
| `bin/order_report` | `build/order_report.o` | `build/liborders.a` | 22 |
| `bin/balance_check` | `build/balance_check.o` | Both archives | 98 |

Keep using explicit archive paths in the linking commands, as in exercise 11.
The new library-search options from the proposed next lesson can wait.

## Makefile goals

- Plain `make` builds all three programs.
- Use variables for the compiler, preprocessor options, and C compiler options.
- Keep the warning and debugging options from exercise 11.
- Use pattern rules for the compilation stages and automatic variables in recipes.
- Preserve the intermediate `.i` and `.s` files for inspection.
- Have Make create `build` and `bin`, using order-only prerequisites.
- Generate and include a `.d` file for each C source; do not handwrite header dependencies.
- Put all generated files in `build` or `bin`.
- Make `all` and `clean` phony targets, and let `clean` remove `build` and `bin`.

No recursive Makefiles, source-discovery functions, shared libraries, or new
dependency-generation options are needed. Adjusting paths and repeating a
familiar pattern rule for another source directory is fine.

## Check your finished build

Start with a clean build, then run `make` again. The second run should have
nothing to do. Inspect the archives with `ar t` and inspect the generated
dependency files.

Run each program, then immediately inspect its status:

```bash
./bin/stock_report
echo $?
./bin/order_report
echo $?
./bin/balance_check
echo $?
```

Before each experiment below, start from an up-to-date build. Predict which
sources will be preprocessed, which archives will be updated, and which
programs will be relinked. Then make one change and run `make --trace`.
Record what you predicted and what actually happened.

1. Touch `src/apps/reports/stock_report.c`.
2. Touch `src/lib/stock/hardware/bolt_stock.c`.
3. Touch `src/lib/stock/include/stock_levels.h`.
4. Touch `src/lib/stock/include/stock.h`.
5. Touch `src/lib/orders/include/orders.h`.
6. Touch the `build` and `bin` directories.

These header tests matter: different headers are used by different groups
of sources. Let the generated `.d` files show you those relationships.

For a behavior check, change `PANEL_STOCK` from 40 to 41 in `stock_levels.h`.
After rebuilding, the expected statuses are 121, 22, and 99 respectively.
Restore 40 and rebuild afterward.

You can also repeat the unused-local-variable warning experiment, then remove
the variable and rebuild. If you want to revisit debugging, set a breakpoint
on `panel_stock` in `bin/stock_report`.

## Questions to answer in your own words

- Where is each recipe in the compilation, archiving, or linking process?
- Which recipe writes a `.d` file, and which target does its rule describe?
- How do those generated rules become part of Make's dependency information?
- Why can a program be relinked even when its own C source was not recompiled?
- Which headers affect one library, and which also affect application objects?
- What would stop working if the dependency-file inclusion was removed?

Take this in sections. A path typo or a missed prerequisite is something to
trace through the build, not a reason to discard your whole Makefile.
