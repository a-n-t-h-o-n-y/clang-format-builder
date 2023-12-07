#!/bin/bash

# Define the path to the .clang-format and the source file to be formatted
CLANG_FORMAT_FILE="./.clang-format"
SOURCE_FILE="./source_code.cpp"
OUTPUT_FILE="./output.cpp"

# Ensure inotifywait and clang-format are installed
if ! command -v inotifywait &> /dev/null
then
    echo "inotifywait could not be found. Please install inotify-tools."
    exit 1
fi

if ! command -v clang-format &> /dev/null
then
    echo "clang-format could not be found. Please install clang-format."
    exit 1
fi

# Function to generate a default .clang-format file
generate_default_clang_format() {
    clang-format -style=llvm -dump-config > $CLANG_FORMAT_FILE
    echo "Generated default .clang-format file using LLVM style."
}

# Function to apply clang-format to the source file
format_source_code() {
    clang-format -style=file $SOURCE_FILE >| $OUTPUT_FILE
    echo "Formatted $SOURCE_FILE to $OUTPUT_FILE using .clang-format"
}

# Check if .clang-format exists, if not, generate a default one
if [ ! -f $CLANG_FORMAT_FILE ]; then
    generate_default_clang_format
fi

# Format the source file once with the current .clang-format before monitoring
format_source_code

# Monitor .clang-format for changes and apply formatting
echo "Monitoring $CLANG_FORMAT_FILE for changes. To stop, press Ctrl+C."
while inotifywait -e close_write $CLANG_FORMAT_FILE; do
    format_source_code
done

