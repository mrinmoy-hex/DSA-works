# Comparison of Queue Conventions in C

---

# 1. Your Original Queue Convention

## Core Idea

```text
front points BEFORE first element
rear points TO last element
```

---

## Initial State

```c
front = -1;
rear = -1;
```

```text
Queue is empty because:
front == rear
```

---

## After First Enqueue

```c
rear++;
arr[rear] = value;
```

State:

```text
front = -1
rear  = 0
```

Array:

```text
Index:   0
        ----
arr -> | 10 |
        ----
```

---

## Dequeue

```c
front++;
value = arr[front];
```

After dequeue:

```text
front = 0
rear  = 0
```

Queue becomes empty again because:

```text
front == rear
```

---

## Traversal

Traversal starts from:

```c
front + 1
```

because front stays BEFORE first element.

---

# Characteristics

| Feature | Meaning |
|---|---|
| `front` | before first element |
| `rear` | last element |
| Empty condition | `front == rear` |
| First insertion | only `rear++` needed |
| Traversal starts | `front + 1` |

---

---

# 2. Deque Convention (Fixed Code)

## Core Idea

```text
front points TO first element
rear points TO last element
```

---

## Initial State

```c
front = -1;
rear = -1;
```

meaning:

```text
queue is empty
```

---

## After First Insertion

First valid array index is:

```text
0
```

So:

```c
front = rear = 0;
arr[0] = value;
```

---

## Visual

```text
Index:   0
        ----
arr -> | 10 |
        ----

front = 0
rear  = 0
```

Both point to same element because only one element exists.

---

## Dequeue From Front

```c
front++;
```

Suppose:

```text
front = 0
rear  = 2
```

Queue:

```text
10 20 30
```

After dequeue:

```text
front = 1
rear  = 2
```

Queue becomes:

```text
20 30
```

---

## Empty Condition

When:

```text
front > rear
```

queue becomes empty.

Example:

```text
front = 3
rear  = 2
```

means:

```text
no elements left
```

because front crossed rear.

---

# Characteristics

| Feature | Meaning |
|---|---|
| `front` | first element |
| `rear` | last element |
| Empty condition | `front > rear` OR `front == -1` |
| First insertion | `front = rear = 0` |
| Traversal starts | `front` |

---

# Why Your Deque Had Problems

You accidentally mixed both conventions.

You used:

```text
front == rear
```

from first convention,

BUT also used direct front insertion/removal logic from second convention.

That caused inconsistencies.

---

# Biggest Conceptual Difference

| Concept | Original Queue | Fixed Deque |
|---|---|---|
| `front` points to | before first element | first element |
| first insertion | only move rear | set both to 0 |
| empty condition | `front == rear` | `front > rear` |
| traversal begins from | `front + 1` | `front` |

---

# Easy Mental Shortcut

## Original Queue

```text
front stays behind queue
```

---

## Deque Style

```text
front directly touches first element
```