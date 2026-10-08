# GDB Demo Run Sheet

https://github.com/dmihovch/cisc210-lectures.git

Build: `make` (7 programs, flags `-g -O0`). Clean: `make clean`.

| Command | Effect |
|---|---|
| gdb ./prog | load program |
| gdb -tui -q ./prog | load program with GDB's Terminal User Interface and Quietly |
| b: break func  //  break file:line | set breakpoint by function or file:line |
| r: run | start or restart |
| n: next | next line, over calls |
| s: step | next line, into calls |
| c: continue | run to next breakpoint |
| p: print expr | evaluate expression |
| info locals  //  info args | frame variables / arguments |
| bt: backtrace | print call stack |
| watch var | stop when var changes |
| d: delete | delete breakpoints |
| q: quit | exit |

`print` formats: `p/x` hex, `p/d` decimal, `p/t` binary.
`gdb -tui ./prog` or `layout src` shows source and current line.

## 01-stepping.c

Breakpoints: `main`, `add`, `01-stepping.c:24`.

1. `break main`, `run`.
2. `next` past `add(x, y)` (over the call). `print x`, `print y`.
3. `run`; `step` at `add(x, y)` (into the call). `info args` and `info locals` show `a`, `b`, `sum`.
4. `continue`. The line-24 breakpoint fires 3 times. `print i` each hit.

Line 24: `for (int i = 0; i < 3; i++)`. `next` keeps execution in `main`; `step` enters `add`.

## 02-callstack.c

Breakpoints: `main`, `plusTen`, `triple`.

1. `break main`, `break plusTen`, `break triple`, `run`. Stops at `main` entry.
2. `info locals` shows `start = 4`. `continue`.
3. At `plusTen`, `info args` shows `n = 4`. `print &n`. `continue`.
4. At `triple`, `info args` shows `n = 14`. `print &n` returns a different address than in `plusTen`.
5. `backtrace`: `triple` <- `plusTen` <- `main`.

Each call allocates its own frame; `n` is distinct storage per call.

## 03-pointers.c

Breakpoints: `03-pointers.c:25`.

1. `run`.
2. `print &value`, `print p`: same address. `p` holds `&value`.
3. `print *p` = 42. `print &p`: different address; `p` has its own location.
4. `print &other`: different address from `&value`.
5. `print sizeof(p)` = 8, `print sizeof(value)` = 4.
6. `next` past `*p = 99;`. `print value` = 99.

`&x` yields an address; `*p` reads or writes the object at that address.

## 04-array.c

Breakpoints: `04-array.c:18` or `main`.

1. `run`, `next` past the array declaration.
2. `print arr` = `print &arr[0]`. `print *arr` = 10.
3. `print arr[0]` = 10 ... `print arr[4]` = 50.
4. `print arr + 1` = `&arr[1]`, address 4 greater. `print *(arr + 2)` = 30.

`arr` decays to `&arr[0]`. `p + i` advances `i * sizeof(int)` bytes.

## 05-swap.c

Breakpoints: `swap_wrong`, `swap_right`.

1. `break main`, `run`. `print &x`, `print &y`.
2. `break swap_wrong`, `continue`. `info args`: `a = 1`, `b = 2`. `print &a`, `print &b`; `&a` != `&x`.
3. `continue`. `main` prints `x = 1, y = 2`.
4. `break swap_right`, `continue`. Arguments are `int *`. `print a` = `&x`, `print *a` = 1.
5. `continue`. `main` prints `x = 2, y = 1`.

Value parameters receive copies. Pointer parameters receive addresses, so writes through them reach the caller.

## 06-offbyone.c

Breakpoints: `sumArray`, `06-offbyone.c:12`.

1. `break sumArray`, `run`. `print n` = 4; valid indices 0..3.
2. `continue` to line 12. `print i` each iteration.
3. At `i` = 4, `i <= n` holds and `arr[4]` is read.
4. `print arr[4]` returns a value outside the array; `print total` != 30.
5. Change line 11 to `i < n`, rebuild. `total` = 30.

Line 11: `for (int i = 0; i <= n; i++)`. `arr[4]` is the first element past the array.

## 07-segfault.c

Breakpoints: none.

1. `run`. Stops with `SIGSEGV` at `07-segfault.c:9` (`*p = v;`).
2. `print p` = `(int *) 0x0`.
3. `backtrace`: `writeValue` <- `main`.
4. `break main`, `run`, `next` to `writeValue(p, 10)`, `print p` = 0x0.
5. Change line 17 to `writeValue(&x, 10)`, rebuild. No crash.

Dereferencing 0x0 faults. The backtrace gives the caller that passed the pointer.
