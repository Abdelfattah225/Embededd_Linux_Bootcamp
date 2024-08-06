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
