Vector implementation is interesting. Let's make it as lightweight and fast as possible

Need to track capacity (size_t, 8 bytes)
Need to track size (size_t, 8 bytes)
Need pointer to start (T\* 8 bytes always)

On the stack this will occupy 24 bytes of space

On the heap it will occupy 8 \* sizeof(T) bytes

I'm also going to implememtn a fast fast vector

This will be super light, and I will compare the throghput.

To test the throughput i might need to test pushing one elment and removing one element

Or do this test with like size 1, 2, 3, 4, 5

At one point there will be a problem with pushing / pulling and it will cause us to be a bit slower
