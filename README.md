This project has been created as part of the 42 curriculum by Kaichan

# Minitalk

## Description

Minitalk is a small data exchange program that enables communication between a client and a server using only UNIX signals (`SIGUSR1` and `SIGUSR2`). The project demonstrates low-level inter-process communication (IPC) without using traditional methods like pipes, sockets, or message queues.

The program converts messages into binary representation and transmits them bit-by-bit through signals. The server reconstructs the original message and displays it in real-time. This project emphasizes understanding signal handling, overcoming system race conditions via a synchronized handshake, and ensuring efficient data transmission under strict performance requirements.

## Instructions

### Compilation

```bash
make

```

This will compile both the `client` and `server` executables and automatically build the required `libft` library.

To clean object files:


```bash
make clean

```

To remove all compiled files:

```bash
make fclean

```

To recompile everything:

```bash
make re

```

### Execution

1. Start the server first (in Terminal 1):
```bash
./server

```


The server will print its PID, for example:
```text
12345

```


2. Send a message from the client (in Terminal 2):
```bash
./client <server_pid> "<message>"

```


Example:
```bash
./client 12345 "Hello World"

```


The message will appear on the server terminal.

## Requirements

* GCC or Clang compiler with `-Wall -Wextra -Werror` flags
* UNIX/Linux operating system
* `libft` library (included in the project)

## Technical Details

### How It Works

* **Signal-Based Communication:** The client converts each character into 8 bits and sends each bit as a signal:
  * `SIGUSR1` represents bit `0`
  * `SIGUSR2` represents bit `1`


* **Defensive PID Validation:** The client executes a null signal check using `kill(pid, 0)` to securely verify that the target server PID is valid and active before starting transmission.
* **Acknowledgment Handshake:** Rather than relying on fragile time delays, a strict bidirectional handshake synchronization is used. The client drops its flag to `0`, sends a bit, and pauses. The server receives it and pings back `SIGUSR1`. The client catches this acknowledgment, flips its flag, and instantly moves to the next bit.
* **Character Reconstruction:** The server accumulates 8 bits into a static `unsigned char`, reconstructs the complete character, and displays it immediately to prevent sign extension bugs with high-bit data.
* **Null Terminator:** The client sends a null byte (`\0`) at the end to signal message completion.

## Key Features

* Efficient bit-level communication using signals
* Robust acknowledgment mechanism to completely eliminate race conditions
* Real-time message display with no buffering delays
* Structural verification of target process via `kill(pid, 0)`
* Support for multiple sequential clients
* Full compatibility with complex multi-byte UTF-8 structures and emojis
* No memory leaks
* Single global variable per program (justified by signal handler requirements)
* Compliant with 42 Norm coding standards

## Testing

### Basic Tests

```bash
# Simple message
./client <PID> "Hello World"

# Numbers and special characters
./client <PID> "1234567890!@#$%^&*()_+-=[]{}|;:',.<>?/"

# Stress test (Heavy Multi-byte UTF-8 script and vibrant emojis)
./client <PID> "Café, mañana, naïve 🚀 🔥 Привет, Καλημέρα, ようこそ"

```

## Resources

### UNIX Signals Documentation

* **Minitalk GitBook Guide:** Core architecture strategies for bitwise shifting and structural workflows.
* **Oceano (YouTube):** Conceptual synchronization flow maps between separate client/server handlers.
* **The GNU C Library Manual (Signal Handling):** Reference documentation for configuring robust `sigaction` flags, signal masks, and secure cross-process communications.

## AI Usage

AI was used to:
* **Code Implementation:** Assisted in translating structural logic concepts into clean C code templates and refining the signal configuration.
* **Testing strategies:** Suggested comprehensive test cases for various character types and message lengths.
* **Documentation:** Assisted in writing clear and concise README and code comments.
* **Debugging:** Provided guidance on common signal handling pitfalls, timing issues, and fixing the handshake race condition.

All AI-assisted code was thoroughly reviewed, tested, and modified to ensure compliance with project requirements and the 42 Norm. Full understanding of the signal-based communication mechanism was maintained throughout the implementation.

***
