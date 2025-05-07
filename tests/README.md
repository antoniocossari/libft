# Test Suite for libft

This directory contains the unit tests for the libft project.


## Prerequisites

- The `libft.a` library must be built in the project root.
- Ensure the test runner is executable:
	```bash
	chmod +x tests/run_tests.sh


## Running All Tests

From the project root, run:

make fclean && make bonus \
  && make -C tests clean && make -C tests \
  && tests/run_tests.sh


## What each step does:

- make fclean
	Removes all root object files and the libft.a archive.

- make bonus
	Rebuilds libft.a including bonus sources from your latest code.

- make -C tests clean 
	Cleans all test objects and executables.

- make -C tests
	compiles and links each test_ft_*.c against the fresh libft.a.

- tests/run_tests.sh 
	Runs every test, printing OK/FAIL and a final summary.


## Example output:

👉 Running test_ft_atoi          ... OK
👉 Running test_ft_bzero         ... OK
...
✅ ALL TESTS PASSED! ✅

