# Cum CLI documentation

## Usage

```bash
cum [command] [options] [files]

[]: optional
<>: required
```

## Commands

### `build` default command

Builds the given files.

#### Options

- `-o, --output <output>`: Output filename. Defaults to `./cum.exe`.
- `-of, --output-format <format>`: Output format. Defaults to `exe`. Possible values: `exe`, `dll`, `lib`.`
- `-a, --assembly`: Build as assembly. Disabled by default.
- `-i, --include <path>`: Add a directory to the include search path
- `-l, --lib <path>`: Add a directory to the library search path
- `-L, --link <library>`: Link with a library
- `--nostdlib` : Don't link with the standard library. Disabled by default.

### `help`

Displays help information.

### `version`

Displays version information.

## Examples

```bash
cum build -o ./cum.exe ./main.c
cum build -o ./cum.exe -of dll ./main.c
cum main.c lib.h
```
