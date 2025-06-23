#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}***********************************************"
echo -e "TEST #1 => 1 800 200 200 =${RED} not eat${NC}"
./philo 1 800 200 200

echo -e "${BLUE}***********************************************"
echo -e "TEST #2 => 4 310 200 200 = ${RED}die${NC}"
sleep 2
./philo 4 310 200 200

echo -e "${BLUE}***********************************************"
echo -e "TEST #3 => 5 800 200 200 7 =${GREEN} end after 7 meals${NC}"
sleep 2
./philo 5 800 200 200 7

echo -e "${BLUE}***********************************************"
echo -e "TEST #3 => 4 410 200 200 =${GREEN} NOT DIE${NC}"
sleep 2
./philo 4 410 200 200