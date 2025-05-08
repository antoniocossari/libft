# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acossari <acossari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:17:13 by acossari          #+#    #+#              #
#    Updated: 2025/05/08 12:07:57 by acossari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env bash
set -e

# Move into this script’s directory
cd "$(dirname "$0")"

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

# Iterate over test executables
for exe in ./test_ft_*; do
  [ -x "$exe" ] || continue

  # Print test name
  printf "👉 Running %-20s ... " "${exe#./}"
  
  # 1) Run the test; capture success/failure
  if "./$exe"; then
    printf "${GREEN}OK${RESET}\n"
  else
    printf "${RED}FAIL${RESET}\n"
    exit 1
  fi

  # 2) Run the mem test (Valgrind)
  printf " 🧠 (Memcheck) 🧠 "
  if valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$exe" &> /dev/null; then
    printf "${GREEN}OK${RESET}\n"
  else
    printf "${RED}MEMORY ERRORS${RESET}\n"
    exit 1
  fi
done

printf "\n${GREEN}✅ ALL TESTS PASSED! ✅${RESET}\n"

