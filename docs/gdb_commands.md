# GDB Commands Reference

## Starting GDB

```bash
# Start GDB with a program
gdb ./program

# Start GDB and run program immediately
gdb --args ./program arg1 arg2

# Start GDB with core dump
gdb ./program core
```

## Running Programs

```
run [args]          # Run the program with optional arguments
run                 # Run the program (shortcut: r)
continue            # Continue execution (shortcut: c)
next                # Execute next line, step over functions (shortcut: n)
step                # Execute next line, step into functions (shortcut: s)
finish              # Continue until current function returns
until               # Continue until a line past the current line
```

## Breakpoints

```
break <location>    # Set breakpoint (shortcut: b)
break main          # Break at function main
break 10            # Break at line 10
break file.c:15     # Break at line 15 in file.c
break *0x400500     # Break at memory address

info breakpoints    # List all breakpoints (shortcut: info b)
delete <num>        # Delete breakpoint number (shortcut: d)
delete              # Delete all breakpoints
disable <num>       # Disable breakpoint
enable <num>        # Enable breakpoint
clear <location>    # Clear breakpoint at location
```

## Conditional Breakpoints

```
break 10 if i == 5          # Break at line 10 when i equals 5
condition <num> i > 10       # Add condition to existing breakpoint
```

## Watchpoints

```
watch variable              # Break when variable is written
watch -l variable          # Watch local variable
rwatch variable            # Break when variable is read
awatch variable            # Break when variable is read or written
info watchpoints           # List all watchpoints
```

## Examining Variables and Memory

```
print <expr>               # Print value of expression (shortcut: p)
print variable             # Print variable value
print $1                   # Print value from history
print/x variable           # Print in hexadecimal
print/d variable           # Print in decimal
print/t variable           # Print in binary
print/c variable           # Print as character

display variable           # Auto-display variable at each stop
undisplay <num>            # Stop auto-displaying
info display               # List auto-display expressions

x/<format> <address>       # Examine memory
x/10x $sp                 # Examine 10 words in hex from stack pointer
x/10i $pc                 # Examine 10 instructions from program counter
x/s string                # Examine as string
x/d address               # Examine as decimal
```

## Stack and Frames

```
backtrace                  # Show call stack (shortcut: bt)
frame <num>                # Select frame number (shortcut: f)
up                         # Move up one frame
down                       # Move down one frame
info frame                 # Info about current frame
info locals                # Show local variables
info args                  # Show function arguments
```

## Source Code

```
list                       # Show source code (shortcut: l)
list 10                    # Show code around line 10
list main                  # Show code around function main
list 5,15                  # Show lines 5 to 15
list +                     # Show next lines
list -                     # Show previous lines
```

## Disassembly

```
disassemble                # Disassemble current function (shortcut: disas)
disassemble main           # Disassemble function main
disassemble 0x400500       # Disassemble at address
disassemble /m              # Mixed source and assembly
```

## TUI Mode and Layouts

TUI (Text User Interface) mode provides a split-screen view of your code, assembly, and registers.

### Entering TUI Mode

```bash
# Start GDB with TUI mode
gdb -tui ./program
```

```
# Toggle TUI mode inside GDB
Ctrl + X A
```

### TUI Commands

```
tui enable                 # Turn on TUI mode
tui disable                # Turn off TUI mode
```

### Layout Options

| Command        | Meaning                  |
| -------------- | ------------------------ |
| `layout src`   | Show only source code    |
| `layout asm`   | Show only assembly       |
| `layout split` | Show source + assembly   |
| `layout regs`  | Show registers           |
| `layout next`  | Cycle to next layout     |
| `layout prev`  | Cycle to previous layout |

### How to Enter TUI Mode

You can start gdb with TUI:

```bash
gdb -tui a.out
```

Or toggle inside gdb:

```
Ctrl + X A
```

## Threads

```
info threads               # List all threads
thread <id>                 # Switch to thread
thread apply all <command> # Apply command to all threads
```

## Changing Variables

```
set variable i = 10        # Set variable i to 10
set var i = 10             # Shorter form
```

## Information Commands

```
info registers             # Show all registers
info program               # Show program execution status
info breakpoints           # List breakpoints
info watchpoints           # List watchpoints
info locals                # Show local variables
info args                  # Show function arguments
info variables             # Show all variables
```

## Useful Settings

```
set print pretty on        # Pretty print structures
set print array on         # Print arrays nicely
set print null-stop        # Stop printing strings at null
set print elements 0       # Print all elements (no limit)
set listsize 20            # Number of lines to show with list
```

## Exiting GDB

```
quit                       # Exit GDB (shortcut: q)
```

## Example Session

```bash
# Compile with debug symbols
gcc -g -o example example.c

# Start GDB
gdb ./example

# Inside GDB:
(gdb) break main           # Set breakpoint at main
(gdb) run                  # Run the program
(gdb) next                 # Step to next line
(gdb) print a              # Print variable a
(gdb) print sum            # Print variable sum
(gdb) break 12             # Set breakpoint at line 12
(gdb) continue             # Continue to next breakpoint
(gdb) print sum > a + b    # Evaluate expression
(gdb) quit                 # Exit GDB
```

## Tips

- Use `help <command>` to get help on any command
- Use Tab completion for commands and variable names
- Use `Enter` to repeat the last command
- Use `Ctrl+C` to interrupt a running program
- Use `Ctrl+D` or `quit` to exit GDB

