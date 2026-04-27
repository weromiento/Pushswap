*This project has been created as part of the 42 curriculum by yflohic, romgutie.*

DESCRIPTION     :

        This project's goal is to learn how to manage an algorithm complexity. We have to fast sort a list of numbers, with two stack (a & b), and a handful of allowed moves, using four disctinct sorting strategies, with different complexities (O(n²), O(n√n), or O(n log n)).

INSTRUCTIONS    :

        Use the command 'make' to execute the program. Then, use './pushswap', an optionnal strategy selector (--simple, --medium, --complex, --adaptive), with a list of numbers (the stack).
        You can also use the benchmark mode (--bench) to get more informations (uses the 'adaptive' strategy).

RESSOURCES      :
        - YouTube videos for linked lists
        - Many websites, to understand better different concepts
        - AI was used to explain few concepts more deeply
        - Help from some 42 students

EXPLANATION OF ALGORITHMS :

        - Min / Max extraction method   (O n²) :
                Sorts a list of numbers by searching the lower number of stack a, and put it into stack b, until a is empty. Then, we put all element from b to a, one by one.

        - Chunk-based sorting   (O n√n) :
                Divide the list of numbers into √n 'chunks'. Take every number of a under √n fort the first round, and put them into b. Then take every number of a under √n*2, for the second round, and put them into b..., until a is empty.
                Sort the chunks into b, while merging them to a.

        - Radix sort    (O (n log n)) :
                Assigns a normalized index (0 to n-1) to each element, then sorts by examining each bit of those indices, from lowest bit to the highest.
                For each bit position: elements whose current bit is 0 are pushed to stack b, others stay in a and are rotated. Once all elements are processed, everything is pushed back to a.

        - Adaptive sort :
                Use one of the above algorithms, based on the 'disorder'. The 'disorder' is a number between 0 and 1 that tells how far the initial stack is sorted. If the numbers are already sorted, the 'disorder' is 0, and 1 if they are is the worst possible order. Anything between means that the stack is partially sorted, but not completely.
                        (       disorder < 0.2 -> --simple
                         0.2 <= disorder < 0.5 -> --medium
                         0.5 <= disorder       -> --complex)

CONTRIBUTION    :

        romgutie :
                - Libft
                - Architecture
                - Memory leaks
                - Sub algorithm

        yflohic :
                - Sorting algorithms implementation
                - Parsing
                - Global verification
                - Error handling