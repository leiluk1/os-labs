#!/bin/bash

gcc -Wall publisher.c -o publisher
gcc -Wall subscriber.c -o subscriber
tmux new-session -d -s ex2
tmux send-keys -t ex2 "./publisher $1" ENTER
for i in $(seq $1)
do
    tmux split-window -d -h "./subscriber"
done
tmux a
