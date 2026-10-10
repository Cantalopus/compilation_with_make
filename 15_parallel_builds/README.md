## Variable usage
    - $(@) -> target
    - $(<) -> prerequisite 
    - $(^) -> all prerequisites
    - CC   -> C Compiler
    - %    -> matching
    - \    -> new line
    
## Make functions
`$(patsubst old, new, text)` -> cycles through replacing old text with new text.  

`$(wildcard pattern1 pattern2 pattern3)` -> Uses globbing to returns any file names that match the patter. You can also supply exact matches. 
- `*`	Zero or more characters within a filename component	bolt*.c matches bolt.c and bolt_order.c
- `?`	Exactly one character	part?.c matches part1.c, but not part12.c
- `[abc]`	One character from the listed choices 
- `part[123].c` matches part1.c, part2.c, or part3.c  

## New commands
`ar` -> archiver.
- `r` -> replace existing members, or insert them if thearen't there.  
- `c` -> expect to create the archive; suppress thnotice normally printed when a new archive is created.  
- `s` -> create of update the symbols index, which helpthe linker find definitions inside the archive.   
- `t` -> display the table of contents.  

`make` -> builds top target as default
- `-r` -> disables build rules that will skip generatinintermediate files, like .i .s files. This commanworks in concert with .SECONDARY(inside Makefile)which keeps intermediate files that make creates.  
- `-j4` -> processing up to 4 jobs at once. Example `-j1`, will perform 1 task at a time, `-j2` will process 2 jobs at once, and so on... 

`ldd` -> show which libraries the program depends on
- `-v` -> will show verbose output. showing not just thlibraries our program depends on, but showing thlibraries our program depends on plus the librariethat they may depend on.  

`ls -l <exe>`  -> show the last time the executable watouched, and will show how many bytes that thexecutable occupies in memory.  

`-### `-> use this command before your compilecommands to show which commands the compiler would usif the compiler was running this command. example: gc-### -E main.c -o main.i  
  
`-Isrc/lib/include`  -> tells the compiler to look here to find our `.h` files

`-MMd`  -> tell the compiler to create a list of dependencies(headers) for our source file, excluding systems headers.

`-MF <file>`  -> tell the compile which file to store our dependency information, from `-MMD` in. Example: `-MF $(@:.i=.d)`

`$(@:.i=.d)`  -> is Make syntax that would expand a file name like `build/main.i` into `build/main.d`.

`-MT <file>`  -> takes \<file\> and places it into the target position in our `.d` file.  
  
`include`  -> read the named files and interpret their content as Make instructions.

**The leading**`-`  -> don't report an error if those files are missing. This matters before the first build and/or after `make clean`. 

**The trailing**`\`**characters  -> continue the same statement onto the next line for readability


# What We're Looking at:
This looks at how to link shared libraries during the linking stage, how to link shared libraries as static libraries, and how to view there size and generating commands.  