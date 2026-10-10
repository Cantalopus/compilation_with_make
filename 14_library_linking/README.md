## Variable usage
    - $(@) -> target
    - $(<) -> prerequisite 
    - $(^) -> all prerequisites
    - CC -> C Compiler
    - %  -> matching
    

## New commands
`ar` -> archiver.
        - r -> replace existing members, or insert them if they aren't there.  
        - c -> expect to create the archive; suppress the notice normally printed when a new archive is created.  
        - s -> create of update the symbols index, which helps the linker find definitions inside the archive.   
        - t -> display the table of contents.  

`make` -> builds top target as default
        - -r -> disables build rules that will skip generating intermediate files, like .i .s files. This command works in concert with .SECONDARY(inside Makefile): which keeps intermediate files that make creates.  

`ldd` -> show which libraries the program depends on
        - -v -> will show verbose output. showing not just the libraries our program depends on, but showing the libraries our program depends on plus the libraries that they may depend on.  

`ls -l <exe>`  -> show the last time the executable was touched, and will show how many bytes that the executable occupies in memory.  

`-### `-> use this command before your compiler commands to show which commands the compiler would use if the compiler was running this command. example: gcc -### -E main.c -o main.i  

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