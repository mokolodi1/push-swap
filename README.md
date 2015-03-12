# push_swap: a 42 project

This is a project that I did at Ecole 42. The subject for the project is here:
https://projects.intrav2.42.fr/uploads/document/document/69/push_swap.pdf

A quick English translation:
- the concept is that you have two stacks: A and B
- at the beginning B is blank and A contains a certain number of positive or negative integers, without repeats.
- the goal is to sort stack A only using a certain number of defined commands
  - sa: swap A: swap the first two elements on stack A
  - sb: sawp B: swap the first two elements on stack B
  - ss: do commands sa and sb at the same time
  - pb: push A to B: take the first element on A and move it to the beginning of B
  - pa: push B to A: take the first element on B and move it to the beginning of A
  - ra: rotate A: move all the elements on A and move them towards the beginning, moving the first element to the end
  - rb: rotate B: move all the elements on B and move them towards the beginning, moving the first element to the end
  - rr: do commands ra and rb at the same time
  - rra: reverse rotate A: move all the elements on A and move them towards the end, moving the last element to the beginning
  - rrb: reverse rotate B: move all the elements on B and move them towards the end, moving the last element to the beginning
  - rrr: do commands rra and rrb at the same time

Here's an example of the stacks in action: 

- Starting with:  
   A: 2 1 3 6 5 8  
   B: 

- sa  
   A: 1 2 3 6 5 8  
   B: 

- pb pb pb  
   A: 6 5 8  
   B: 3 2 1

- ra rb (aka rr)  
   A: 5 8 6  
   B: 2 1 3

- rra rrb (aka rrr)  
   A: 6 5 8  
   B: 3 2 1

- sa  
   A: 5 6 8  
   B: 3 2 1

- pa pa pa  
   A: 1 2 3 5 6 8  
   B:

My program uses two different algorithms:
- when the number of arguments is less than 7, I use a priority queue with a heuristic.
- when the number of arguments is 7 or greater, I recursively partition the array and then push the resulting values to the back of the stacks, with a merge of the two stacks at the end.

Example program usage:  
$ make  
made libft.a  
made push_swap  
$ ./push_swap 2 8 6 3  
pb sa rra pa

I have included a python testing script called testing.py. It makes sure the program is runing correctly by taking the result and performing the operations to the input and making sure the resulting array is sorted. It also has a linked Google Sheet where one can place part of the output to show the running time and average output length over different input lengths. 
