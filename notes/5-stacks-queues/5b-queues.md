# Queues

Textbook sections:

- 5.4 Queue abstract data type (ADT)
- 5.5 Array-based queues
- 5.6 Queues using linked lists
- 5.7 Deque abstract data type (ADT)

## Queue ADT

Consider a line of people waiting to buy tacos from a taco truck.

There is a front of the line and a back of the line. The person in the front of the line gets served first, the person in the back of the line has to wait their turn. New people who show up have to join the back of the line.

This is an example of a queue data structure.

![](./assets/taco-queue.svg)

There are two basic operations you perform with queues:

- Enqueue: add an item to the back of the queue.
- Dequeue: remove an item from the front of the queue.

![](./assets/taco-queue.gif)

### FIFO

A queue has the characteristics of a FIFO data structure. FIFO stands for "First In, First Out". This means the first item in the queue will be the next item you remove from the queue.

This makes sense when you think about the taco truck analogy. The first person in line is the first person to get served.

![](./assets/taco-fifo.svg)

### Other operations

Enqueue and dequeue are the primary operations of a queue. The name of these operations may vary depending on the implementation.

You may find other operations as well, such as:

- Peek: check what's at the front of the queue, but don't remove it.
- IsEmpty: check if the queue is empty.
- GetLength/GetSize: check how many items are in the queue.

## Queues using arrays

As with stacks, both bounded and unbounded queues are possible. We'll look at a bounded queue here.

Consider the following code that creates an empty queue using an array:

```cpp
int frontIndex = 0;  // Where the queue starts.
int length = 0;      // Current number of items in the queue.
int maxLength = 7;   // Maximum number of items that are allowed.
int* queue = new int[maxLength];
```

The queue is currently empty. There is no item in the front of the queue.

![](./assets/5-queue-array-1.svg)

If we enqueue a new item, we can store it in the first slot in the array. You can use the `frontIndex` and the `length` variables to determine where the back of the queue is.

![](./assets/5-queue-array-2.svg)

![](./assets/5-queue-array-3.svg)

This pattern can continue until the queue is full.

![](./assets/5-queue-array-4.svg)

With a bounded queue, you cannot add any more items if the queue is full.

If we dequeue an item at this point, it gets removed from the front of the queue. The `fontIndex` variable is incremented accordingly.

![](./assets/5-queue-array-5.svg)

Is it possible to enqueue an item at this point? Yes! The queue will wrap around back to the beginning of the array.

![](./assets/5-queue-array-6.svg)

This is called a circular array. When you reach the end, you wrap back around to the beginning.

Enqueues and dequeues can continue indefinitely (of course with a bounded queue you can only enqueue as long as the queue is not full).

![](./assets/5-queue-array-7.svg)

![](./assets/5-queue-array-8.svg)

Using the variables `length`, `maxLength`, and `frontIndex`, we can always determine the index **where a new item will be enqueued**.

```cpp
int enqueueAt = (frontIndex + length) % maxLength;
```

Exercise: https://onecompiler.com/cpp/43brc4urf

- Implement the functions with `TODO` comments.

## Queues using linked lists

One possible implementation:

- `head` pointer points to front of queue.
- `tail` pointer points to back of queue.
- Enqueue appends item to back of linked list.
- Dequeue removes item from front of linked list.

![](./assets/5-queue-linked-list.svg)

Exercise: https://onecompiler.com/cpp/43bss3meh

- Implement the functions with `TODO` comments.

## Message queues

A real world application of queues in software development is the idea of a message or event queue.

![](./assets/5-message-queue.svg)

- Producer(s) generates messages or events and submits them to a queue.
- Consumer(s) monitor the queue and process messages as they come in.

There are many variations on this idea.

Example: a job system in a video game engine.

![](./assets/5-job-system.svg)

Interesting links:

- https://github.com/Game-Architecture/homework-1-queuing-eameres
- [Parallelizing the Naughty Dog Engine](https://gdcvault.com/play/1022186/Parallelizing-the-Naughty-Dog-Engine)
- https://github.com/hlavacs/ViennaGameJobSystem
- https://blog.molecular-matters.com/2015/08/24/job-system-2-0-lock-free-work-stealing-part-1-basics/
- [Multithreading the Entire Destiny Engine](https://www.youtube.com/watch?v=v2Q_zHG3vqg)

Example: a web application message queue

![](./assets/5-web-message-queue.svg)

Examples of messaging systems:

- [RabbitMQ](https://www.rabbitmq.com/)
- [Azure Service Bus](https://learn.microsoft.com/en-us/azure/service-bus-messaging/service-bus-messaging-overview)
- [Google Pub/Sub](https://cloud.google.com/pubsub/docs/overview)

## Deques

A deque (pronounced "deck") is a double-ended queue.

- You can push/pop from the front of the queue.
- You can push/pop from the back of the queue.

![](./assets/5-deque.svg)

Example: https://onecompiler.com/cpp/43bw6thp7

## Study guide

### General questions

- What does "FIFO" mean and what is an example of a FIFO data structure?
- What operations does a deque data structure support?
- If you implement a queue using a circular array, you may have multiple variables like `frontIndex`, `length`, and `allocationSize` to help keep track of the queue state. How would you determine the index to enqueue the next item at using these variables?
- Do worst-case runtime analyses of queue operations (i.e., find the Big O):
  - `enqueue()` when using an array implementation (bounded)
  - `dequeue()` when using a linked list implementation
  - `enqueue()` when using an array implementation (bounded)
  - `dequeue()` when using a linked list implementation

### Queue code example

Assume the `Queue` class is a custom queue data type that supports both `enqueue()` and `dequeue()` operations.

```cpp
Queue<char> q;
q.enqueue('a');

char c = s.dequeue();
q.enqueue(c);
q.enqueue(c);
q.enqueue('d');

c = s.dequeue();
q.enqueue(c);
q.enqueue(c);
q.enqueue('z');
```

- What does the queue contain after the code is executed?
- What is the value of the variable `c` after the code is executed?

### Queue code example

Assume the `Queue` class is a custom queue data type that supports `enqueue()`, `dequeue()`, and `isEmpty()` operations.

```cpp
Queue<int> q;
int x = 10;

for (int i = 0; i < 9; i++) {
  if (i % 3 != 0) {
    q.enqueue(i);
  }
  else if (!q.isEmpty()) {
    q.dequeue();
  }

  x = i;
}
```

- What does the queue contain after the code is executed?
- What is the value of the variable `x` after the code is executed?

### Queue enqueue/dequeue

Suppose you have a queue implemented with a linked list. You have `head` and `tail` pointers.

- Write C++ code that would enqueue a new item to the back of the queue.
- Write C++ code that would dequeue an item from the front of the queue.
