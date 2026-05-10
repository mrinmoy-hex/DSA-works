# Double Pointers in C

## Important Idea

A pointer is also a normal variable.

So when a pointer is passed to a function, C still passes a **copy** of that pointer.

---

## Example

```c
int *p;

func(p);
```

The function receives a copy of `p`.

Changing `p` inside the function does NOT change the original pointer.

---

# Why Double Pointers Are Used

Suppose:

```c
Node *front = NULL;
```

If we want a function to modify `front` itself, we must pass its address.

```c
enqueue(&front);
```

Since `front` is of type:

```c
Node *
```

its address becomes:

```c
Node **
```

---

# Important Difference

## Single Pointer (`Node *`)

Can modify the data stored at an address.

Example:

```c
*p = 10;
```

But cannot modify the original pointer variable itself.

---

## Double Pointer (`Node **`)

Can modify the original pointer variable itself.

Example:

```c
*front = newNode;
```

This changes the actual `front` pointer in `main()`.

---

# Example

```c
void func(Node **front) {
    *front = newNode;
}
```

Here:

```c
*front
```

refers to the original `front` variable from `main()`.

---

# Memory Visualization

```text
Node *front = NULL;
```

Memory:

```text
front
+------+
| NULL |
+------+
```

`&front` gives the address of this pointer variable.

Passing `&front` allows the function to directly modify the original pointer.

---

# Shortcut

| Want to modify | Pass |
|---|---|
| normal variable | pointer |
| pointer variable | double pointer |

Examples:

```c
int x;       // pass int *
Node *p;     // pass Node **
```