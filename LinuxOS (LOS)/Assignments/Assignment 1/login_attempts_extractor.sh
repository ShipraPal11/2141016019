#!/bin/bash

# Set log file location based on OS
# Change to /var/log/secure if you're on CentOS/RHEL
LOGFILE="/var/log/auth.log"
OUTPUT_FILE="login_attempts_extracted.txt"

# Check if log file exists
if [ ! -f "$LOGFILE" ]; then
    echo "Log file $LOGFILE not found!"
    exit 1
fi

# Extract login attempts using grep, sed, and awk
grep -E "Failed password|Invalid user|Accepted password" "$LOGFILE" | \
awk '
{
    # Combine timestamp
    timestamp = $1 " " $2 " " $3;

    # Initialize fields
    user = "-";
    message = "";

    # Extract username from the log line
    for (i=1; i<=NF; i++) {
        if ($i == "for" && $(i+1) != "invalid") {
            user = $(i+1);
            break;
        } else if ($i == "user") {
            user = $(i+1);
            break;
        }
    }

    # Reconstruct the full message starting from the program name
    for (i=6; i<=NF; i++) {
        message = message " " $i;
    }

    # Output format: timestamp | username | message
    printf "%s | User: %s | Message:%s\n", timestamp, user, message;
}' > "$OUTPUT_FILE"

echo "Login attempts extracted to: $OUTPUT_FILE"
