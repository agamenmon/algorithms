# Implement the autotools into project
1 . Why is autotools?
    - the name GNU `autotools` commonly refers to the software refers to the software packages `Autoconf`, `automake`, `libtool`. They consist of a number of programs used by developers, among them `autoreconf`, `autoconf`, `autoheader`, `autoscan` (which come from `autoconf` package), `aclocal` and `automake`(which come from the `automake` package), and `libtoolize`(from `libtool` package)

## Demo: Create the simplest autotools for the simple C program:
 - Create folder `src`(source code) and `build`
 - Write the source code file and put it into `src` folder.
    Example: I write the main program and build the program with command below to make sure the file is correct
    `gcc main.c -o main.o`

    ```
        #include <stdio.h>
        
        int main(int argc, char *argv[])
        {
            printf("Hello World!");

            return 0;
        }
    ```
 - Create file Makefile.am with the content below:
    ```
    AUTOMAKE_OPTIONS = subdir-objects

    bin_PROGRAMS = simpleAutotools

    simpleAutotools_SOURCES = \
        src/main.c
    ```
 - Run command `autoscan` and the file `configure.scan` will be created, This file will be a template.
    Change the file from `configure.scan` to `configure.ac`
 - Add the line below on `configure.ac` to create Makefile
    ```
    AM_INIT_AUTOMAKE([-Wall -Werror foreign])
    ```
 - Run command `autoreconf -vi` to re-configure. and file `configure` created again.

 - Goto folder `build` and run the command `../configure`. The `Makefile` create in `build` folder
 - Run command `make` to build source code
 - Run command `./simpleAutotools` for running program;