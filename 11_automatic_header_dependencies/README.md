# Automatic Header Dependencies
`-Isrc/lib/include`  -> tells the compiler to look here to find our `.h` files

`-MMd`  -> tell the compiler to create a list of dependencies(headers) for our source file, excluding systems headers.

`-MF <file>`  -> tell the compile which file to store our dependency information, from `-MMD` in. Example: `-MF $(@:.i=.d)`

`$(@:.i=.d)`  -> is Make syntax that would expand a file name like `build/main.i` into `build/main.d`.

`-MT <file>`  -> takes \<file\> and places it into the target position in our `.d` file. 

## `include` instruction command:

`include`  -> read the named files and interpret their content as Make instructions.

**The leading**`-`  -> don't report an error if those files are missing. This matters before the first build and/or after `make clean`. 

**The trailing**`\`**characters  -> continue the same statement onto the next line for readability. 

---