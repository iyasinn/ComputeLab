Vector implementation is interesting. Let's make it as lightweight and fast as possible

Need to track capacity (size_t, 8 bytes)
Need to track size (size_t, 8 bytes)
Need pointer to start (T\* 8 bytes always)
