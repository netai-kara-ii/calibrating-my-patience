# The real overhead of dynamic polymorphism

## How much overhead is associated with dynamic polymorphism and runtime virtual function mechanisms in ```c++```?

Implementation details of the virtual function mechanism depend on
the compiler's internals, so there is no exact answer. In general,
though, the best compilers in the market have remarkably low
overhead for dynamic polymorphism.

A common implementation mechanism of runtime virtual functions is
to store the addresses of virtual functions in a compiler-generated 
table at a location that could be either in static RAM or program
code (no mention of this, but i am guessing most compiler suites
(let's say both GCC and clang) will be able to do both and switch
depending on whether we are optimising for code size or speed).

Generally, each virtual function costs about one chunk of memory 
large enough to hold a function pointer [1]. 

Here, memory requirements change based on platform (e.g., 32-bit/
64-bit systems will usually allocate 4-bytes/8-bytes), calling 
conventions, and compiler options [these three are recurring topics 
in software optimisation --- see [2] for detailed notes]. 

Looking at a practical example: 

Consider an 8-bit platform. If a function pointer requires two bytes
on this platform and a derived class has three virtual functions,
then the implementation of the derived class requires six bytes of
storage for its virtual function table.

So we have that compilers typically will implement virtual functions
via a Virtual Table (vtable) which stores pointers to virtual
functions. Then, on a per-class basis, each class in a hierarchy
with virtual functions has its own vtable, and on a per-object
basis, each polymorphic object stores a Virtual Pointer (vptr),
which points to its class vtable. Therefore each vptr adds to
each polymorphic object the size of one function pointer.

Calling a virtual function is fast because all the compiler needs
to do is select the proper entry from the virtual function table
and call it. In itself, this is only slightly slower than a normal
function call. Since we are using a pointer reference to find the entry 
point at callsite, it introduces one indirection (deferencing) to
access the function address, but the time complexity of such operation 
is constant regardless of inheritance depth.the call overhead of a 
virtual function remains the same regardless of how many levels of 
inheritance there are [1]

So we can see that runtime polymorphism through virtual functions
is not as bad as it may seem, if memory is not a strong contraint. 

To give an example of where it is unsuitable, we can think of low
level drivers that are called very often (especially for real-time
applications, for high-frequency interrupts). In these cases, 
procedural methods or static polymorphism aare better options for
extremely time-critical code [1].

" Functions in the application layer that are less time critical
  greatly benefit from well-designed class hierarchies because
  the advantages of dynamic polymorphism usually far outweigh its
  modest costs " [1].


References:

    [1] Kormanyos, Christopher (2021). Real-Time C++: Efficient
        Object Oriented and Template Microcontroller Programming.
        10.1007/978-3-662-6292996-3. [pp. 60-61]

    [2] Fog, Agnor (2004). Revised in 2024. Thechnical University 
        of Denmark. https://www.agner.org/optimize/optmizing_cpp.pdf.
