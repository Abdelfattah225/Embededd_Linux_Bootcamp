#!/bin/bash

# Bash Script to Analyze Network Traffic

# Input: Path to the Wireshark pcap file
pcap_file=$1   # capture input from terminal.

# Function to extract information from the pcap file
analyze_traffic() {
    # Use tshark or similar commands for packet analysis.
    # Hint: Consider commands to count total packets, filter by protocols (HTTP, HTTPS/TLS),
    # extract IP addresses, and generate summary statistics.
    ##################################################################################3
  
  
    # 1. count total packets
    total_packets=$(tshark -r "$pcap_file" | wc -l )
    # 2. filter by protocols (HTTP, HTTPS/TLS)
    total_http_packets=$(tshark -r "$pcap_file" -Y "http" | wc -l )
    total_https_packets=$(tshark -r "$pcap_file" -Y "tls" | wc -l )
    others=$(expr "$total_packets" - "$total_http_packets" - "$total_https_packets")
    # 3. extract IP addresses



    # Output analysis summary
    echo "----- Network Traffic Analysis Report -----"
    # Provide summary information based on your analysis
    # Hints: Total packets, protocols, top source, and destination IP addresses.
    echo "1. Total Packets: $total_packets "
    echo "2. Protocols:"
    echo "   - HTTP: $total_http_packets packets"
    echo "   - HTTPS/TLS: $total_https_packets packets"
    echo "   - Others: $others packets"
    echo ""
    echo "3. Top 5 Source IP Addresses:"
    # Provide the top source IP addresses
    tshark -r "$pcap_file" -T fields -e ip.src  | \
    tr '\t' '\n' | \
    grep -E '^[0-9]' | \
    sort | \
    uniq -c | \
    sort -nr | \
    head -5 | \
    awk '{print $2 " : " $1 " packets"}'

    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    # Provide the top destination IP addresses
     #Converts tab-separated IP addresses to newline-separated addresses.
    ##Filters out any non-IP address lines (e.g., blank lines). 
    #Sorts the IP addresses.
    #Counts the occurrences of each unique IP address.
    # Sorts the output numerically in reverse order, showing the most frequent IPs first.
    #top 5 ips

    tshark -r "$pcap_file" -T fields -e ip.dst  | \
    tr '\t' '\n' | \
    grep -E '^[0-9]' | \
    sort | \
    uniq -c | \
    sort -nr | \
    head -5 | \
    awk '{print $2 " : " $1 " packets"}'

    echo ""

    echo "----- End of Report -----"
}

# Run the analysis function
analyze_traffic
