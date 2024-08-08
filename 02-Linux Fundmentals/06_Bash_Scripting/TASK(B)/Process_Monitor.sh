#!/usr/bin/bash -i




# shellcheck source=somefile
. ProcessMonitor.cfg


update_interval="$UPDATE_INTERVAL"
cpu_threshold="$CPU_ALERT_THRESHOLD"
memory_threshold="$MEMORY_ALERT_THRESHOLD"


Log_file="Process_Monitor.log"

#function to log message.
Log_message()
{
    local message="$1"
    echo "$(date): $message" >> "$Log_file"
}


#function to check usage and alert if thresholds are exceeded
check_usage()
{
    local process_name=$1
    local pid=$2 
    local cpu_usage=$(ps -p "$pid" -o %cpu=)
    local memory_usage=$(ps -p "$pid" -o    rss=)


    if (($(echo "$cpu_usage > $cpu_threshold" | bc -l)));then

    Log_message "ALERT: CPU usage of $process_name (PID $pid) is $cpu_usage%, exceeding threshold of $cpu_threshold%"

    fi
    if((memory_usage>memory_threshold));then

        Log_message "ALERT: Memory usage of $process_name (PID $pid) is $memory_usage KB, exceeding threshold of $memory_threshold KB"

    fi
}


# Function to monitor processes
monitor_processes()
{

#main monitoring loop
while true; do
    
# Get list of monitored processes (e.g., by name)
    for pid in $(pgrep -f "process_name"); do
        check_usage "process_name" "$pid"
    done

    # Wait for the specified interval before the next check
    sleep "$update_interval"
done

}




#Function:
#list running processes
List_Running_Processes()
{
    ps aux
}
# Function : 
# display options for user.
Interactive_Mode()
{

    echo "************************************************************"
    echo "plz choose an option: "
    echo "1. View detailed information about a specific process."
    echo "2. Terminate a specific process."
    echo "3. View overall system process statistics."
    echo "4. Continuously monitor system processes with real-time updates."
    echo "5. Search and filter processes based on specific criteria."
    echo "************************************************************"

    read option

    case "${option}" in
        1)
            Process_Info
        ;;
        2)
            Kill_Process
        ;;
        3)
            Process_Statistics
        ;;
        4)
            Real_time_Monitoring
        ;;
        5)
            Search_and_filter_processes
        ;;
        *)
            echo "(none of above)"
            Interactive_Mode
        ;;
    esac
    
}

Process_Info()
{
    echo "plz enter process ID : "

    read process_id

    ps -p "${process_id}" -o pid,ppid,user,%cpu,%mem,comm

    echo "Process information displayed."
    Log_message "Process (PID: $process_id) information displayed successfully."
    Interactive_Mode
}

Kill_Process()
{
    echo " "
    echo "Please enter process ID: "
    read process_id

    # Attempt to kill the process and check if it was successful
    if sudo kill "${process_id}" 2>/dev/null; then
        echo "Process (PID: $process_id) terminated successfully."
        Log_message "Process (PID: $process_id) terminated successfully."
    else
        echo "Failed to terminate process (PID: $process_id)."
        Log_message "Failed to terminate process (PID: $process_id)."
    fi

    Interactive_Mode
}



Process_Statistics()
{
    # Command to display process statistics
        ps aux | wc -l             # Total number of processes
        free -m                   # Memory usage
        uptime                    # CPU load
    echo "Process statistics displayed successfully."    
    Log_message "Process statistics displayed successfully."
    Interactive_Mode
}

Real_time_Monitoring()
{
    Log_message "Open Real time Monitoring."
    top                      # Real-time process monitoring
    Log_message "Real time Monitoring are closed."
    Interactive_Mode

}




Search_and_filter_processes()
{

echo "NOTE:Press Enter then o (the letter 'o')."

echo "1. Type COMMAND=<process_name> and press Enter."

echo "Replace <process_name> with the name of the process you want to filter by"

echo "2. Type USER= and press Enter. Replace with the name of the user whose processes you want to filter"


echo "3. Type %CPU>10 and press Enter to filter for processes using more than 10% CPU. You can replace 10 with any other value as needed."

echo "4. Type %MEM>5 and press Enter to filter for processes using more than 5% memory. You can replace 5 with any other value as needed."

echo "5. To reset and remove all filters, press =."

read option

Real_time_Monitoring

}












main()
{

    List_Running_Processes
    Interactive_Mode    


}

main

