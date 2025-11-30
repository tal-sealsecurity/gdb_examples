# gdb_examples

Examples for gdb

## Documentation

- [GDB Commands Reference](docs/gdb_commands.md) - Guide to GDB commands and usage
- [Coredump Files](docs/coredump_files.md) - Guide to working with core dumps for debugging crashes
- [Debugging Alternatives](docs/alternatives.md) - Overview of alternative debugging tools and GUI frontends

# setup 
```sh
docker build -t gdb_container .
docker run -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined gdb_container bash
```
explanation:
- SYS_PTRACE is a Linux capability that allows a process to trace other processes using system calls like ptrace()
- seccomp (Secure Computing Mode) is a Linux kernel security facility that allows a process to restrict the set of available system calls it can make. Docker applies a default seccomp profile to containers that blocks potentially dangerous system calls.
  - unconfined tells Docker to disable the default seccomp security profile for this container.
  
run dependencies

# validation

gcc --version
g++ --version
gdb --version

