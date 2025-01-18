So I'm trying to test my cache, but I'm having some problems

- The opeartions I'm using are too expensive, and so they don't let me actually observe the cache
- I have no control over compiler optimizations. I'm not sure if this is a good thing or not

- I need core affinity so that my thread exists on one core. The issue is I don't have control over that in nmac
