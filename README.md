# Lab 5: Process & Thread Memory
### 50 Points

**Objective:** Establish memory protection between threads and processes

In this lab, you will need to refactor your code from Lab 3 so that you can more accurately simulate memory references. Specifically, here is how the memory layout will differ:

+ All memory in the `data` field will be requested when the OS memory is allocated. This will be based of the maximum number of processes you want to allow to be created. 
+ Each process will have one heap and up to seven threads stacks. (The process itself operates as a container for threads and will not have its own stack only its threads will.)
+ Processes and threads can be killed. This will not call `free()` but rather it will simply flag their regions of memory as available. **Hint**: I recommend using `pid` and `tid` of `0` to denote unoccupied regions of process space and unoccupied regions of thread space. 
+ In this lab you *do not* need to use PThreads (Guess what next lab will be).


If you have any questions, feel free to ask. 
