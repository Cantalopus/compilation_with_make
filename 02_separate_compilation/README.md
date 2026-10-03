## Variable usage
    - $@ -> target
    - $< -> prerequisite 
    - $^ -> all prerequisites
    - CC -> C Compiler
    - %  -> matching

## New commands
    - ar -> archiver.
        - r -> replace existing members, or insert them if they aren't there.
        - c -> expect to create the archive; suppress the notice normally printed when a new archive is created.
        - s -> create of update the symbols index, which helps the linker find definitions inside the archive. 
        - t -> display the table of contents.
    - make -> builds top target as default
        - -r -> disables build rules that will skip generating intermediate files, like .i .s files. This command works in concert with .SECONDARY(inside Makefile): which keeps intermediate files that make creates. 

# What We're Looking at:
Here, we create a static library `libhelper.a` and build 2 executables `./example` and `./second`. Both executables use the static library `libhelper.a`. 