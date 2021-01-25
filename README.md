
## Operating Systems Project

## Project 1: Memory Management (Contiguous Memory Allocation)



**Memory** is dividing into several partitions – multiple-partition method. in this program we are going to see how to allocate the memory in 3 different progress and discuss each one of them.

## **First Fit (First method):**

P1 (25 KB), P2 (40 KB), P3 (120 KB), P4 (70 KB), P5 (90 KB)

|**Memory Partition** | **First Fit**|
|--|--|
| P1 , internal fragmentation|  P1 , internal fragmentation|
|Partition 2 (50 KB)|P2 , internal fragmentation|
|Partition 3 (70 KB)|P4 ,no fragmentation|
|Partition 4 (130 KB)|P3 , internal fragmentation|
|Partition 5 (30 KB)|External fragmentation|
|Partition 6 (25 KB)|External fragmentation||
|Partition 7 (80 KB)|External fragmentation|

First fit concept mainly depend on the first process will allocate in the first partition regardless of their sizes as we see in the previous example and the Rest of the partition will be considered if it can fit for another process or not.

So, we implement the program by implement two arrays one for the partition and the another one for process.

Obviously, the user will enter the data for both arrays to complement the allocation of both arrays.

The main idea of implement the part of First in depend on every process will begin from the first partition so that if the first process can not fit with the first partition will allocate the next partition and the next process will take this one. we use a small trick so we can determine the partition which not allocated to any process by using an array called **Allocator** have the same size of array of partition and marked the partition which not allocated by set **-1** for his part  and after allocate all process will check of this array and print the index of Allocator whose value is **-1** to print that this partition is **Empty .**

> **Input 1:**

Enter number of partitions: 4

Partition1 size: 50

Partition2 size: 70

Partition3 size: 15

Partition4 size: 30

Enter number of processes: 3

Process1 size: 40

Process2 size: 30

Process3 size: 20

> **Output:**

Partition 1 (50 KB) = Process 1 (40 KB), Rest of Partition 1 = (10 KB).

Partition 2 (70 KB) = Process 2 (30 KB), Rest of Partition 2 = (40 KB).

Partition 2 (70 KB) = Process 3 (20 KB), Rest of Partition 2 = (20 KB).

Partition 3 (15 KB) = Empty.

Partition 4 (30 KB) = Empty.

> **Screen shot**

![first fit screen 1](https://i.imgur.com/LOj4W33.png)


> **Input  2:**

Enter number of partitions: 4

Partition1 size: 20

Partition2 size: 70

Partition3 size: 15

Partition4 size: 30

Enter number of processes: 3

Process1 size: 40

Process2 size: 30

Process3 size: 20

> **Output :**


Partition 2 (30 KB) = Process 2 (30 KB), Rest of Partition 2 = (0 KB).

Partition 3 (15 KB) = Empty.

Partition 4 (30 KB) = Empty.

> **Screen shot**

![First fit screen 2](https://i.imgur.com/zt4LwLU.png)


## **Worst Fit (second method):**

P1 (25 KB), P2 (40 KB), P3 (120 KB), P4 (70 KB), P5 (90 KB)




|**Memory Partition** | **Worst Fit**|
|--|--|
| Partition 1 (100 KB) | P2 , internal fragmentation |
|Partition 2 (50 KB)|External fragmentation|
|Partition 3 (70 KB)|External fragmentation|
|Partition 4 (130 KB)|P1 ,internal fragmentation|
|Partition 5 (30 KB)|External fragmentation|
Partition 6 (25 KB)|External fragmentation|
|Partition 7 (80 KB)|P4 , internal fragmentation|

**Worst** Fit concept mainly depend on biggest partition will be allocate for the process. So that every process will allocate in the biggest partition. we will use the same two arrays but the difference here that a condition will determine the biggest partition for this process and after that will allocate the process in it. As we use in the previous progress an array called **Allocator,** we will use it again her to achieve the part of **Empty** partition.

> **Input:**

Enter number of partitions: 4

Partition1 size: 50

Partition2 size: 70

Partition3 size: 15

Partition4 size: 30

Enter number of processes: 3

Process1 size: 40

Process2 size: 30

Process3 size: 20

> **Output:**

Partition 1 (50 KB) = Process 2 (30 KB), Rest of Partition 1 = (20 KB).

Partition 2 (70 KB) = Process 1 (40 KB), Rest of Partition 2 = (30 KB).

Partition 2 (70 KB) = Process 3 (20 KB), Rest of Partition 2 = (10 KB).

Partition 3 (15 KB) = Empty.

Partition 4 (30 KB) = Empty.

> **Screen shot**

![worth fit 1](https://i.imgur.com/vYvSMMQ.png)

> **Input 2 :**

Enter number of partitions: 4

Partition1 size: 100

Partition2 size: 75

Partition3 size: 25

Partition4 size: 80

Enter number of processes: 3

Process1 size: 60

Process2 size: 50

Process3 size: 70

> **Output:**

Partition 1 (100 KB) = Process 1 (60 KB), Rest of Partition 1 = (40 KB).

Partition 2 (75 KB) = Process 2 (50KB), Rest of Partition 2 = (25 KB).

Partition 4 (80 KB) = Process 3 (70 KB), Rest of Partition 4 = (10 KB).

Partition 3 (25 KB) = Empty.

> **Screenshot**

![worth fit 2](https://i.imgur.com/mK7Lui1.png)
Best Fit (third method):

P1 (25 KB), P2 (40 KB), P3 (120 KB), P4 (70 KB), P5 (90 KB)

|**Memory Partition**|**Best Fit**|
|--|--|
|Partition 1 (100 KB)|P2 , internal fragmentation|
|Partition 2 (50 KB)|External fragmentation|
|Partition 3 (70 KB)|External fragmentation|
|Partition 4 (130 KB)|P1 ,internal fragmentation|
|Partition 5 (30 KB)|External fragmentation|
|Partition 6 (25 KB)|External fragmentation|
|Partition 7 (80 KB)|P4 , internal fragmentation|

## Best Fit (third Method)


**Best** Fit concept mainly depend on that every process allocate in smallest partition can fit in it. Unlike the **Worst Fit** we will use the same two arrays but the difference here that a condition will determine the smallest partition for this process and after that will allocate the process in it. As we use in the previous progress an array called **Allocator,** we will use it again her to achieve the part of **Empty** partition.

> **Input 1:**

Enter number of partitions: 4

Partition1 size: 50

Partition2 size: 70

Partition3 size: 15

Partition4 size: 30

Enter number of processes: 3

Process1 size: 40

Process2 size: 30

Process3 size: 20

> **Output:**

Partition 1 (50 KB) = Process 1 (40 KB), Rest of Partition 1 = (10 KB).

Partition 2 (70 KB) = Process 3 (20 KB), Rest of Partition 2 = (50 KB).

Partition 3 (15 KB) = Empty.

Partition 4 (30 KB) = Process 2 (30 KB), Rest of Partition 4 = (0 KB).

> **Screen shot**

![Best Fit 1](https://i.imgur.com/mWTnrMH.png)

> **Input 2:**

Enter number of partitions: 4

Partition1 size: 100

Partition2 size: 75

Partition3 size: 25

Partition4 size: 80

Enter number of processes: 3

Process1 size: 60

Process2 size: 50

Process3 size: 70

> **Output :**

Partition 2 (75 KB) = Process 1 (60 KB), Rest of Partition 2 = (15 KB).

Partition 4 (80 KB) = Process 2 (50 KB), Rest of Partition 4 = (30 KB).

Partition 1 (100 KB) = Process 3 (70 KB), Rest of Partition 1 = (30KB).

Partition 3 (25 KB) = Empty.

> **Screenshot**

![Best fit 2](https://i.imgur.com/yHfNQPT.png)



 - ## **[Tarek AbdAlmajed Idrees](https://github.com/TarekIdrees) implement the First Fit part.**
 - ## **[Mohamed AbdAlmajed Idrees](https://www.facebook.com/Mohamadidrees18) implement the worst Fit part.**
 - ## **[Mohamed Mahmoud Ali](https://www.facebook.com/mohamed.thesnak.official1) implement the Best Fit part.**

> Licence of Readme to Thesnak , Tarek Idrees 
