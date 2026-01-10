*This project has been created as part of the 42 curriculum by mait-tal.*

# Description
My goal is to write a C program called push_swap that sorts a list of integers using two stacks and a limited set of operations.

The program takes a list of integers and puts them in a stack. I have two stacks, a and b, and I can only use a limited set of operations to move and reorder the numbers. The program prints the instructions needed to sort the numbers in ascending order.

The challenge is to sort the numbers using as few operations as possible. To do this, I have to think about how to move the numbers efficiently between the two stacks.

This project helps me understand stacks, basic algorithms, and how to write clean and efficient C code.

# Instructions

## Compilation

To compile the project, run:

```
make
```

This will create the `push_swap` executable.

To clean object files:

```
make clean
```

To remove all generated files:

```
make fclean
```

To recompile everything:

```
make re
```

---

## Execution

Run the program by passing a list of integers as arguments:

```
./push_swap 3 2 1
```

The program will print the list of instructions needed to sort the numbers.

If the input is already sorted or no arguments are given, the program prints nothing.

In case of invalid input (non-integers, duplicates, or numbers outside integer limits), the program prints `Error` to standard error.

---

## Testing

You can test the output using the checker provided by 42:

```
ARG="3 2 1"; ./push_swap $ARG | ./checker_OS $ARG
```

If the result is correct, the checker will display `OK`. Otherwise, it will display `KO`.


# Resources

* 42 Push_swap subject and evaluation guidelines
* Stack data structure documentation
  [https://en.wikipedia.org/wiki/Stack_(abstract_data_type)](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)
* Algorithm complexity overview
  [https://en.wikipedia.org/wiki/Analysis_of_algorithms](https://en.wikipedia.org/wiki/Analysis_of_algorithms)
* Sorting algorithms basics
  [https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)

## AI Usage

I used AI as a support tool to help with understanding the project requirements, planning the program structure, and reviewing algorithm ideas.

All code and algorithm choices were written and understood by me, and AI-generated suggestions were always reviewed and adapted before use.