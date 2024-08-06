#!/usr/bin/bash

# 1. bash type --> bash(shebang)




# Inputs:
# Action (Entity Run script) : Devloper, script,  service management 
#         a. before script run (position parameter) Done
#         b. after run operation.                   Done


# a. before script run (position parameter)
# SHELL VARIABLES

#           $0 --> script name 
#           $1 --> first paramater
#           $2 --> second parameter


#echo $1


#         b. after run operation.  
#   read vaiable ==>  read NAME # hold input --> writen by user

                    # echo $NAME

#
#
# 



######################################################################################



#local :
# 1. declare --> (read only , read write)  ==> declare NAME="ABDO"

# 2. Assign value                          ==>NAME="MOAWED"

# 3. Acess vari                            ==> echo ${NAME}

# 4. Delete                                 =>  unset NAME


# env :
# 1. declare env -->  export
# 2. Assign value                          ==>export env_name="shell_bash" // declare -x env_name

# 3. Acess vari                            ==> echo ${env_name}

# 4. Delete                                 =>  unset NAME

# 5. print all env sys                          env

###########################################################
#operations:
# 1. variable
# 2. function--> do specific task
# 3. direct command
# 4. check condition 
# 5. Arth. operations


# Assignation variable : 

#       --> 1. direct value
#       --> 2. assign value form another command result (command substuation)


#declare NAME=`hostname`

#echo ${NAME}


#pstree

#anything



# 5. Arth. operations

#declare -i X=100
#declare -i Y=200

#declare -i RESULT=$(($X * $Y))

#echo ${RESULT}



# 4. check condition 

#IF ESLE STATEMENT


#   a.number

#if (( $X < $Y && $Y > $RESULT)); then
   #echo "Y is greater "

#else
    #echo ""Y is not greater ""

#fi

#   b.string

# shellcheck disable=SC1044



: << 'END_OF_COMMENT'  
declare str1=" "
declare str2="abdo"

if [[ "${str1}" == "${str2}" ]]; then
    echo "The two strings are the same"
fi

if [[ "${str1}" != "${str2}" ]]; then
    echo "The two strings are different"
fi

if [[ -z "${str1}" ]]; then
    echo "empty string"
fi

if [[ -n "${str1}" ]]; then
    echo "string is not empty"
fi

END_OF_COMMENT
#############################################################################
#   c.files 
# files operations :
# 1. Check file is exit
# file path: $1 --> check if file is exit

: << 'END_OF_COMMENT'  

if [ -f "$1" ]; then
    echo "File \"$1\" exists"
else
    echo "File not exists"

fi
END_OF_COMMENT


# 2. check file is exit and not empty


: << 'END_OF_COMMENT'  
if [ -s "$1" ]; then
    echo "$1\" exists and not empty"
else
    if [ -f "$1" ]; then
    echo "File \"$1\" exists and empty"
    else
    echo "File not exists"

fi
fi
END_OF_COMMENT



: << 'END_OF_COMMENT'  

# to do : 3. check owner file

if [[ -O $1]]

    echo "`who` id owner"
fi
# to do : 4. check inside group files 


if [[ -G $1]]

    echo "`who` is inside group"
fi
END_OF_COMMENT


#############################################################################
# Directoies:
# 1. check dir exit

: << 'END_OF_COMMENT'  
if [ -d "$1" ]; then
    echo "directory \"$1\" exists"
fi

if [ ! -d "$1" ]; then
    echo "directory \"$1\" not exists"
fi
END_OF_COMMENT


#2. check owner dir
# 3. check inside group dir 


: << 'END_OF_COMMENT'  

# to do :

if [[ -O $1]]

    echo "`who` id owner"
fi
# to do : 

if [[ -G $1]]

    echo "`who` is inside group"
fi
END_OF_COMMENT

###############################################################33



  #outputs: 
#   tow outpots :
#                   1. Exit status --> run normally or there is an issue
#                   2. print stdout--> 1. echo  --> command
#                                      2. printf--> report

: << 'END_OF_COMMENT'  
cd /anything
#outpupt --> 1. status ..change directory or not
   #         2. change directory

echo $?





   printf "%d %s \n" 1 "Hello world" 2 "Hello world 2"

END_OF_COMMENT




#return status for your process 





######################################################
#    important variable
# 1. path --> exectuable --> search path variable --> custom.
# 2. SHELL --> CUSTOM TERMINAL EMBEDDED SHELL (/BIN/BASH)


