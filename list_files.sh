#!/bin/bash

# Verzeichnisse, die durchsucht werden sollen
src_dir="./src"
include_dir="./includes"

# Funktion zum Auflisten der Dateien im angegebenen Verzeichnis
list_files() {
  local dir=$1
  find "$dir" -type f | while read -r file; do
    echo "$file \\"
  done
}

# Dateien im src-Verzeichnis auflisten
echo "SRC_FILES = \\"
list_files "$src_dir"

# Dateien im include-Verzeichnis auflisten
echo "INCLUDE_FILES = \\"
list_files "$include_dir"
