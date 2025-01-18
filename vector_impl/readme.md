Vector implementation is interesting. Let's make it as lightweight and fast as possible

Need to track capacity (size_t, 8 bytes)
Need to track size (size_t, 8 bytes)
Need pointer to start (T\* 8 bytes always)

On the stack this will occupy 24 bytes of space

On the heap it will occupy 8 \* sizeof(T) bytes

I'm also going to implememtn a fast fast vector
