# Compilers
CC=gcc
RUSTC=rustc

# Compilers flags
CFLAGS=-ansi -pedantic # Use ANSI C standards
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
	    for file in $$(find ${C_FOLDER_PATH}/$$chapter -name *.c -type f ! -size 0); do \
			# Strip file path, keeping only exercise number \
			number=$$(basename $$file .c); \
			echo "$(CC) $$file $(CFLAGS) -o ${C_BIN_PATH}/$$chapter-$$number"; \
			# Main compilation command \
			$(CC) $$file $(CFLAGS) -o ${C_BIN_PATH}/$$chapter-$$number; \
		done \
	done

rust.exe:
	@for chapter in {1..8}; do \
		# loop trough all files with Rust extension \
	    for file in $$(find ${RUST_FOLDER_PATH}/$$chapter -name *.rs -type f ! -size 0); do \
			# Strip file path, keeping only exercise number \
			number=$$(basename $$file .rs); \
			echo "$(RUSTC) $$file $(RUSTFLAGS) -o ${RUST_BIN_PATH}/$$chapter-$$number"; \
			# Main compilation command \
			$(RUSTC) $$file $(RUSTFLAGS) -o ${RUST_BIN_PATH}/$$chapter-$$number; \
		done \
	done

# Delete everything
.PHONY: clean

clean:
	@echo "Cleaning everything inside ${C_BIN_PATH} and ${RUST_BIN_PATH}"
	find ${C_BIN_PATH} -type f ! -size 0 -print0 | xargs -0 rm; \
	find ${RUST_BIN_PATH} -type f ! -size 0 -print0 | xargs -0 rm; \
