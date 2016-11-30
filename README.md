# Custom Memory Management implementation
A custom malloc implementation in C, made for [CSC369H (Operating Systems)](https://mcs.utm.utoronto.ca/~peters43/369/) - Fall 2014 - University of Toronto

## References
Useful readings, suggested by the professor:
- [Memory API](http://pages.cs.wisc.edu/~remzi/OSTEP/vm-api.pdf)
- [Free Space Management](http://pages.cs.wisc.edu/~remzi/OSTEP/vm-freespace.pdf)
- [How do malloc() and free() work (StackOverflow)](http://stackoverflow.com/questions/1119134/how-do-malloc-and-free-work)
- [Hoard: A Scalable Memory Allocator for Multithreaded Applications (Berger et al.)](http://dl.acm.org/citation.cfm?id=379232)
- [Doug Lea's article on optimizing malloc](http://gee.cs.oswego.edu/dl/html/malloc.html)

## How it works


##### 1. Data Structure
The data structure is located before each chunk of memory, to keep track of its status (metadata). Through the linked list of this data structure, it is possible to access the address of any memory block in the list, its size, availability, the next and previous chunks of adjacent memory and the end of the block. With this attributes, it’s possible to manage and manipulate the memory using the algorithm quickly described above.

##### 2. Algorithm
It uses the [“first fit” strategy](https://www.quora.com/What-are-the-first-fit-next-fit-and-best-fit-algorithms-for-memory-management/answer/Varun-Agrawal-1). The algorithm search the list from the beginning to end, until it finds the first big enough (greater or equal the size requested) chunk of memory (splitting it in two, in case it’s bigger than needed), and finally return its adress to the user. If there is no more space in the heap, the algorithm then extends it, using the sbrk system call. To free memory, the algorithm changes the “available” state of the chunk’s metadata (struct), releasing it to further allocation. After that, the freed chunk is merged with the previous block (if this one is also freed), this is useful to avoid memory fragmentation in small sized blocks (it can happens after some splittings).
