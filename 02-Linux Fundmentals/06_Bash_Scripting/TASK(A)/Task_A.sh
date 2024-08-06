#!/usr/bin/bash

#create subdirectory

subdir()
{
    #Take path of directory
    DIRECTORY=$1
    #Extract extention form each file
    declare Extension="sds"

     cd "${DIRECTORY}"
    
    shopt -s dotglob #include hidden files

    for item in "${DIRECTORY}"/*; do
    
    Extension=${item#*.}

    if [[ "${Extension}" == "jpg" ]]; then
            
            mkdir "${Extension}"
            mv "$item" "./$Extension"

    elif [[ "${Extension}" == "txt" ]]; then
              mkdir "${Extension}"
              mv "$item" "./$Extension"

    elif [[ "${Extension}" == "pdf" ]]; then
              mkdir "${Extension}"
              mv "$item" "./$Extension"

    else
              mkdir "misc"
              mv "$item" "./misc"

    fi
    
    done



}

# main function
main()
{
    #create subdirectory
    subdir $1


}
 #take the directory path
main $1