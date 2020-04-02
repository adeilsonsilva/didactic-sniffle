# Use same shell accross diferent systems
SHELL=/bin/bash    # Using "/bin/sh" causes different behavior for the commands below

# Compilers
CC=gcc
RUSTC=rustc

# Compilers flags
CFLAGS=-ansi -pedantic -lm # Use ANSI C standards
RUSTFLAGS=

# Paths
C_FOLDER_PATH=./C
C_BIN_PATH=${C_FOLDER_PATH}/bin
RUST_FOLDER_PATH=./rustlang
RUST_BIN_PATH=${RUST_FOLDER_PATH}/bin

# TMP
all: c.exe rust.exe

c.exe:
	@for chapter in {1..8}; do \
		# loop trough all files with C extension \
		for file in $$(find ${C_FOLDER_PATH}/$$chapter -maxdepth 1 -name *.c -type f ! -size 0 | sort -V); do \
			# Strip file path, keeping only exercise number \
			number=$$(basename $$file .c); \
			echo "$(CC) $$file $(CFLAGS) -o ${C_BIN_PATH}/$$chapter-$$number"; \
			# Main compilation command \
			$(CC) $$file $(CFLAGS) -o ${C_BIN_PATH}/$$chapter-$$number; \
		done \
	done

	# Some examples are special...
	$(CC) C/4/11/main.c C/4/11/getop.c C/4/11/stack.c C/4/11/getch.c $(CFLAGS) -o ${C_BIN_PATH}/4-11


rust.exe:
	@for chapter in {1..8}; do \
		# loop trough all files with Rust extension \
		for file in $$(find ${RUST_FOLDER_PATH}/$$chapter -maxdepth 1 -name *.rs -type f ! -size 0 | sort -V); do \
			# Strip file path, keeping only exercise number \
			number=$$(basename $$file .rs); \
			echo "$(RUSTC) $$file $(RUSTFLAGS) -o ${RUST_BIN_PATH}/$$chapter-$$number"; \
			# Main compilation command \
			$(RUSTC) $$file $(RUSTFLAGS) -o ${RUST_BIN_PATH}/$$chapter-$$number; \
		done \
	done

	# Some examples are special...
	rustc ./rustlang/4/11/main.rs  -o ./rustlang/bin/4-11

# Delete everything
.PHONY: clean

clean:
	@echo "Cleaning everything inside ${C_BIN_PATH} and ${RUST_BIN_PATH}"
	find ${C_BIN_PATH} -type f ! -size 0 -print0 | xargs -0 rm; \
	find ${RUST_BIN_PATH} -type f ! -size 0 -print0 | xargs -0 rm; \
