#!/bin/bash
#SBATCH --job-name=two_jobs         
#SBATCH --output=combined_output.log
#SBATCH --nodes=1                    
#SBATCH --cpus-per-task=2            
#SBATCH --time=00:10:00             

gcc -o question2-square question2_square.c
gcc -o question2_fact question2_fact.c

srun --exclusive -n 1 ./question2-square

srun --exclusive -n 1 ./question2-fact


