# push_swap

Sorting algorithm in C. The program will find a set of movements to sort the numbers recived as parameters using only two stacks.The arguments recieved are stored in the stack a, and when the program is finnished, all elements will be stored in stack a once again, but sorted. The movements used are the following:

- `pa` (push a): the first element in b becomes the first element in a
- `pb` (push b): the first element in a becomes the first element in b
- `sa`(swap a): the two top elemets in a swap places
- `sb`(swap b): the two top elemets in b swap places
- `ss`: swap a and swap b at the same time
- `ra` (rotate a): The first element in a becomes the last one
- `rb` (rotate b): The first element in b becomes the last one
- `rr`: rotate a and rotate b at the same timme
- `rra`(reverse rotate a): The last element in a becomes the first one
- `rrb`(reverse rotate b): The last element in b becomes the first one
- `rrr`: reverse rotate a and reverse rotate b at the same time

For 5 or less elements, the program will apply quick sorting. On the other hand, if it recieves more elements it will apply radix sort.

It will take a maximum of 2 movements to sort three elements, and a maximum of 10 movements to sort 5 elements. It is able to sort 100 random numbers in less than 900 movements, granting a 4/5 grading. It will take less than 5800 movements for the program to sort 500 random numbers, once again granting a 4/5 grading.