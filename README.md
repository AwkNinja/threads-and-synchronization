# threads-and-synchronization
A program to see how you get undesired results if you use an unsynchronized counter with multithreading. This program can run one or more threads, each thread increments the counter number of times given by the user. After all threads are finished executing the value of the count is printed and compared to what we should have ideally received. The user inputs the number of threads and the number of increments each thread should increment the count by. Generally when you give a large number of increments you will see a difference e.g 10000

![test run image](https://i.imgur.com/Y9Gzc1n.png)
