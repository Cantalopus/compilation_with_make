## Variable usage
    - $@ -> target
    - $< -> prerequisite 
    - $^ -> all prerequisites
    - CC -> C Compiler

## New commands
    - ar -> archiver.
        - r -> replace existing members, or insert them if they aren't there.
        - c -> expect to create the archive; suppress the notice normally printed when a new archive is created.
        - s -> create of update the symbols index, which helps the linker find definitions inside the archive. 
        - t -> display the table of contents.

# What We're Looking at:
Here, we create a static library `libhelper.a` and build 2 executables `./example` and `./second`. Both executables use the static library `libhelper.a`. 