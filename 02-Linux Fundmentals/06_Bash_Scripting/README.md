# Bash Script Overview

This repository contains a comprehensive Bash script that demonstrates various aspects of Bash scripting. The script covers topics such as shell variables, file operations, string manipulation, flow control, file processing, and functions.

## Table of Contents

- [Script Overview](#Script-Overview)
- [Usage](#usage)
- [Topics Covered](#topics-covered)
  - [Shell Variables](#shell-variables)
  - [File Operations](#file-operations)
  - [Directories](#directories)
  - [String Operations](#string-operations)
  - [Flow Control](#flow-control)
  - [File Processing](#file-processing)
  - [Functions](#functions)
- [Additional Information](#additional-information)

## Script Overview

This script demonstrates various Bash scripting techniques, including:
- Using and managing shell variables.
- Performing file and directory operations.
- Handling string manipulations.
- Controlling the flow of execution with conditionals and loops.
- Defining and using functions.

## Usage

- To execute the script, run it from the terminal:

Change directory to the sript path.

Then, execute script for example {02_Advanced_bash.sh}.

Finally,run it.



> $ cd {script path}

> $ chmod +x 02_Advanced_bash.sh

> ./02_Advanced_bash.sh

## Topics Covered

### Shell Variables

- Local Variables:
  - Declaration, Assignment, Access, and Deletion:

```bash

# Declare a variable
declare NAME="ABDO"

# Assign a value
NAME="MOAWED"

# Access the variable
echo ${NAME}

# Delete the variable
unset NAME
```

- Environment Variables:

  - Exporting and Accessing:

```bash

# Export an environment variable
export env_name="shell_bash"

# Access the environment variable
echo ${env_name}

# Delete the environment variable
unset env_name
```
### File Operations
- Check if File Exists:

```bash
Copy code
if [ -f "$1" ]; then
    echo "File \"$1\" exists"
else
    echo "File does not exist"
fi
```

- Check if File Exists and Not Empty:

```bash
if [ -s "$1" ]; then
    echo "File \"$1\" exists and is not empty"
else
    if [ -f "$1" ]; then
        echo "File \"$1\" exists but is empty"
    else
        echo "File does not exist"
    fi
fi
```
- Check File Ownership and Group:

```bash
if [[ -O $1 ]]; then
    echo "`whoami` is the owner"
fi

if [[ -G $1 ]]; then
    echo "`whoami` is in the group"
fi
```

### Directories
- Check if Directory Exists:

```bash

if [ -d "$1" ]; then
    echo "Directory \"$1\" exists"
else
    echo "Directory does not exist"
fi
```

- Check Directory Ownership and Group:

```bash

if [[ -O $1 ]]; then
    echo "`whoami` is the owner"
fi

if [[ -G $1 ]]; then
    echo "`whoami` is in the group"
fi
```
### String Operations
- Substring Extraction:

```bash

declare string="Hello world"
echo "${string:3}"   # Output: "lo world"
echo "${string: -3}" # Output: "ld"
```

- Pattern Matching and Searching:


```bash

declare filename="hello.txt"
declare basic_name=${filename%.*}
echo $basic_name    # Output: "hello"

declare extension_=${filename##*.}
echo $extension_    # Output: "txt"

declare data="Hello world"
if [[ "${data}" == *"world"* ]]; then
    echo "${data} contains: world"
fi
```

### Flow Control

- Conditional Statements:

```bash

if [[ $X < $Y && $Y > $RESULT ]]; then
    echo "Y is greater"
else
    echo "Y is not greater"
fi
```

- Loops:

```bash

# While loop
declare -i A=0
while (( $A < 10 )); do
    echo $A
    ((A++))
done

# For loop
for filename in *; do
    echo $filename
done
```


- Switch Case Statements:


```bash

case "$os" in
    linux)
        echo "linux"
        ;;
    windows)
        echo "windows"
        ;;
    *)
        echo "error"
        ;;
esac

```

### File Processing
- Reading Files Line by Line:

```bash

# Method 1
cat $1 | while read line; do
    echo $line
done

# Method 2
while IFS= read -r line; do
    echo "$line"
done < $1

```

- Writing to Files:

```bash

# Overwrite file
echo "input" > file.txt

# Append to file
echo "text" >> file.txt

```

- Extracting Data from Files:

```bash

cat $1 | while read line; do
    declare os=${line%:*}
    echo "${os}"
done
```
### Functions
- Define and Use Functions:

```bash

name() {
    if (($# == 0)); then
        echo "Instruction: Number of arguments passed!"
    fi
    echo "Number of parameters: $#"
    echo "Hello $1"
}

name "argument1" "argument2"

```
- Scope and Return Values:

```bash

# Variable Scope
declare NAME="Terminal Scope"
echo ${NAME}

changeName() {
    NAME="Function Scope"
}
changeName
echo ${NAME}

# Return Number
ReturnNumber() {
    return 10
}
ReturnNumber
echo $?

# Return String
returnString() {
    echo "str"
}

declare R=$(returnString)
echo $R

```


### Additional Information
- Ensure the script is executable with chmod +x 02_Advanced_bash.sh.
- Customize the script based on your needs and usage scenarios.
- For further details on Bash scripting, refer to the Bash Reference Manual.
