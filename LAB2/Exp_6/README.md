## Experiment 6 — False Sharing

When threads write to different variables that happen to sit on the same cache line (64 bytes), the CPU keeps invalidating that line across cores even though the data is logically independent. This is false sharing.

Two programs demonstrate this:

---

### Struct-based test (false_sharing_struct.cpp)

| Config        | Time (s) |
|---------------|----------|
| False Sharing | 0.158    |
| Padded        | 0.133    |

### Array-based test (false_sharing_array.cpp)

| Config   | Time (s) |
|----------|----------|
| Unpadded | 0.381    |
| Padded   | 0.054    |

The array test shows the bigger difference — 7x speedup just from padding. In the struct test the gap is smaller (~1.2x), probably because the struct's access pattern gives the cache slightly more breathing room.

![False Sharing Comparison](./Graph1.png)

---

### Why it matters

False sharing is sneaky because the code looks correct and the variables are independent. But the hardware sees them on the same cache line and forces expensive coherence traffic. Padding each thread's data to sit on its own cache line fixes it completely.

