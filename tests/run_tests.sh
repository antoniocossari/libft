# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acossari <acossari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:17:13 by acossari          #+#    #+#              #
#    Updated: 2025/05/09 23:18:08 by acossari         ###   ########.fr        #
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

# Formati per l’output:
#  - 36 caratteri di campo, poi " ... ", poi risultato
TEST_FMT="👉 Running %-20s               ... %b\n"
MEM_FMT="%-31s                 ... %b\n"

for exe in ./test_ft_*; do
  [ -x "$exe" ] || continue
  name="${exe#./}"

  # 1) test funzionale
  if "./$exe"; then
    printf "$TEST_FMT" "$name" "${GREEN}OK${RESET}"
  else
    printf "$TEST_FMT" "$name" "${RED}FAIL${RESET}"
    exit 1
  fi

  # 2) memcheck quiet
  if valgrind -q --leak-check=full --error-exitcode=1 "./$exe" &> /dev/null; then
    printf "$MEM_FMT" "🧠 (Memcheck)" "${GREEN}OK${RESET}"
  else
    printf "$MEM_FMT" "🧠 (Memcheck)" "${RED}MEMORY ERRORS${RESET}"
    exit 1
  fi

  # riga vuota di separazione
  echo
done

printf "\n%20s%b✅ ALL TESTS PASSED! ✅%b\n" "" "$GREEN" "$RESET"
