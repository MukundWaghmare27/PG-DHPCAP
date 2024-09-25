#!/usr/bin/perl -w
use strict;


my %tasks;

# Function to add a task
sub add_task {
    my ($task_name, $status) = @_;
    $tasks{$task_name} = $status;
}


for my $i (1..2) {
    print "Enter the name of task $i: ";
    chomp(my $task_name = <>);
    print "Enter the status of task $i (e.g., Completed, Pending): ";
    chomp(my $status = <>); 

    add_task($task_name, $status);
}


print "\nTasks and their statuses:\n";
foreach my $task (keys %tasks) {
    print "$task: $tasks{$task}\n";
}

