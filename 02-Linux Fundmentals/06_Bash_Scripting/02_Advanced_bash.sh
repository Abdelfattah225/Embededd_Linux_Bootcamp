#!/usr/bin/bash


#advanced variable operations: 

: << 'END_OF_COMMENT'  

#               1. Variable_name:-<default_value>
#               2. Variable_name:=<default_value> 
#               3. Variable_name:?<default_value>

echo "Advanced Bash Topics"

declare NAME=""

echo "${NAME:-abdo}" #variable is empty --> NAME="abdo"
echo "${NAME:=abdo}" #variable is not declare --> 1. define variable 2. set variable
echo "${NAME:?abdo}" #Variable is not declare --> raise error

END_OF_COMMENT

######################################## Advanced string operations##############################################


#string operations : 

#       1. check string --> done in basics
#     sub string   2. get sub string --> string 

: << 'END_OF_COMMENT'  

declare string="Hello world"

echo "${string:3}" # cutting operations : cut 3 chracters form the begining

echo "${string: -3}" # cutting operations : cut 3 characters form the end  

END_OF_COMMENT

#       3. matching pattern--> searching pattern inside string and extract

: << 'END_OF_COMMENT'  

    declare filename="hello.txt"

#3.1 Extract part from the string
    #3.1.1 Extract form the begining
        #basic name 
            declare basic_name=${filename%.*}
            echo $basic_name
    #3.1.1 Extract form the end
        #extension
            declare extension_=${filename##*.}
            echo $extension_ 
END_OF_COMMENT

: << 'END_OF_COMMENT'  

#3.2 Searching 
    declare data="Hello world"
    #3.2.1 grep commmand --> grep<pattern>
        #echo data | grep "world"
        if [[ "${data}" == *"world"* ]]; then
            echo "${data} contains: world"
        fi
        
END_OF_COMMENT

#################################### Flow control ############################################


# 1.                        if.... else --> done in basics
# 2.                        Loops --> 1. while............ 2. for
: << 'END_OF_COMMENT'  

declare -i A=0
while (($A < 10)); do
    echo $A
    ((A++))
done

END_OF_COMMENT


: << 'END_OF_COMMENT'  

#case1:iterative for dirctory
#method 1
for filename in `ls`; do
    echo $filename
done
#method 2

for filename in *; do
    echo $filename
done




#case2:iterative for sequence number

#method 1

for filename in `seq 10`; do
    echo $filename
done

#method 2

for ((i=0 ; i<10 ; i++)); do
    echo $i
done
END_OF_COMMENT



# 3. switch case --> create user menu
: << 'END_OF_COMMENT'  

declare os=$1

: << 'END_OF_COMMENT'  
if [ $os == "linux" ]; then
     echo "linux"
elif [ $os == "windows" ]; then
     echo "windows"
else
     echo "error"
fi

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

END_OF_COMMENT




#######################3 select ( testing - flashing) #############################
: << 'END_OF_COMMENT'  


declare os=$1

select os in "linux" "windows"; do 
echo $os ; done

END_OF_COMMENT
#######################3 processing Files #############################


#1. Read file line by line 

: << 'END_OF_COMMENT'  
# Method 1
cat $1 | while read line; do
    echo $line
done

# Method 2

while IFS= read -r line; do
    echo "$line"
done < $1
END_OF_COMMENT



#2. Write file --> redirection

: << 'END_OF_COMMENT'  

#2.1 :  overwrite
echo "input" > ./file.txt # overwrite 
#2.2 : Append
echo "linux" >> ./file.txt  
END_OF_COMMENT




#3. Extrat from file
    #a. open File
    #b. read file
    #c. extract file

: << 'END_OF_COMMENT'  

    cat $1 | while read line; do
        declare os=${line%:*}
        echo "${os}"
    done
END_OF_COMMENT



############################## Functions #########################################

# Function:
#1. declare / define 
#2. call function
#3. define functions with parameter
#4. call function with arrguments
#5. scope variables . $1 ..$n 
#--> for each function
# --> local keyword
#6. return value --> string or number


: << 'END_OF_COMMENT'  

#1. declare / define 


#requirement : print Hello {NAME}
#function must recieve at least one parameter 
name() {
    #operations.
    #special variables shell (bash) define it for each function.
        #$1 $2 $3 $4.....$n


#control number of arrguments to this function
if (($# == 0)); then
    
    #echo error 
    #exit
    echo "instu. Number of arrguments passed!"
fi


    echo "Number of parameter : $#"
    echo "Hello $1"
}

#2. call function with parameter
name "abdo" "mohammed" "ahmed"
END_OF_COMMENT


################################# scope ###############################


: << 'END_OF_COMMENT'  

declare NAME="Terminal Scope"

echo ${NAME}

changeName() {
    #variable scope is global

    NAME="function change"

    #change scope --> local.
    #local NAME="function change"
    }
changeName

echo ${NAME}
END_OF_COMMENT





################################# Return Value ###############################



: << 'END_OF_COMMENT'  
ReturnNumber() {
    return 10
    }

    ReturnNumber #Identfiy status of execuation
    echo $?


returnString() {

    echo "str"
}

declare R=`returnString` #command substuation
echo $R
END_OF_COMMENT








