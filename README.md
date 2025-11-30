# gdb_examples

# compiling with debug notations
The purpose of -g: Explain that without it, GDB can't show source lines or variable names.

# coredump files


gcc --version
g++ --version
gdb --version

docker run \
    -it \
    -v "${PWD}":/workdir -w /workdir \
    --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
    debian:13 bash


explanation:
- SYS_PTRACE is a Linux capability that allows a process to trace other processes using system calls like ptrace()
- seccomp (Secure Computing Mode) is a Linux kernel security facility that allows a process to restrict the set of available system calls it can make. Docker applies a default seccomp profile to containers that blocks potentially dangerous system calls.
  - unconfined tells Docker to disable the default seccomp security profile for this container.
  