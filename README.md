# multiple-queues-in-single-array
This code is for my data structure practice.

This code reads commands from the input.txt file and executes these commands for the first or second queue, which are stored in a single array. You can enqueue, dequeue, and print for all queues.

The first queue starts at index 0, while the second queue starts at index 10. The challenge arises when dequeuing an item from the second queue, as it may cause a displacement. To address this, additional numbers can be added to the first queue. This allows for adjustments between the queues, compensating for any disruptions caused by changes in the second queue.
