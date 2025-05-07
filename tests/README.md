# Test Suite for libft

This directory contains the unit tests for the libft project.


## Prerequisites

The `libft.a` library must be built in the project root.


## Running All Tests

From the project root, run:

make clean && make \
  && make -C tests clean && make -C tests \
  && tests/run_tests.sh


## What each step does:

- make clean
	removes all root object files and the libft.a archive.

- make
	rebuilds libft.a from your latest code.

- make -C tests clean 
	cleans all test objects and executables.

- make -C tests
	compiles and links each test_ft_*.c against libft.a.

- tests/run_tests.sh 
	runs every test, printing OK/FAIL and a final summary.


## Example output:

Running test_ft_atoi ... OK
Running test_ft_bzero ... OK
…
All tests passed!
