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

# What We're Looking at:
This looks at how to link shared libraries during the linking stage, how to link shared libraries as static libraries, and how to view there size and generating commands.   