#!/bin/bash

read -p "Enter the storage used on server1 (GB): " Server1
read -p "Enter the storage used on server2 (GB): " Server2
read -p "Enter the storage used on server3 (GB): " Server3

# Correcting the variable assignment and calculation
Total_Storage_used=$((Server1 + Server2 + Server3))

echo "Total Storage used: $Total_Storage_used GB"

