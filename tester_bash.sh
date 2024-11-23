#!/bin/bash

# Nombre de tests à effectuer
NUM_TESTS=1000

# Plage de nombres pour générer les listes aléatoires
MIN=0
MAX=500
NUM_COUNT=500

# Variables pour les résultats
TOTAL_MOVES=0
SUCCESS_COUNT=0
FAIL_COUNT=0

# Fichiers de sortie
OUTPUT_FILE="summary_results.txt"
FAILED_ARGS_FILE="failed_args.txt"

# Effacer les fichiers précédents s'ils existent
> $OUTPUT_FILE
> $FAILED_ARGS_FILE

# Couleurs pour l'affichage
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
NC="\033[0m" # Sans couleur

# Vérification du mode
if [[ $# -ne 1 || ( "$1" != "checker" && "$1" != "checker_linux" && "$1" != "both" ) ]]; then
    echo -e "${RED}Usage: $0 [checker|checker_linux|both]${NC}"
    exit 1
fi

MODE=$1
echo -e "${YELLOW}Running $NUM_TESTS tests in mode: $MODE${NC}"

for ((i = 1; i <= NUM_TESTS; i++)); do
    # Générer une liste aléatoire
    ARG=$(shuf -i $MIN-$MAX -n $NUM_COUNT | tr '\n' ' ')

    # Exécuter push_swap et capturer les mouvements
    MOVES=$(./push_swap $ARG)
    MOVE_COUNT=$(echo "$MOVES" | wc -l | tr -d ' ')

    # Calculer le total des mouvements
    TOTAL_MOVES=$((TOTAL_MOVES + MOVE_COUNT))

    # Initialiser les résultats des checkers
    CHECKER_RESULT=""
    CHECKER_LINUX_RESULT=""

    # Mode : checker
    if [[ "$MODE" == "checker" ]]; then
        CHECKER_RESULT=$(echo "$MOVES" | ./checker $ARG)
        if [[ "$CHECKER_RESULT" == "OK" ]]; then
            SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
            printf "${GREEN}Test %3d/%d: OK (Checker) - %6d moves${NC}\n" "$i" "$NUM_TESTS" "$MOVE_COUNT"
        else
            FAIL_COUNT=$((FAIL_COUNT + 1))
            printf "${RED}Test %3d/%d: KO (Checker) - %6d moves${NC}\n" "$i" "$NUM_TESTS" "$MOVE_COUNT"
            echo -e "$ARG\n\n\n" >> $FAILED_ARGS_FILE
        fi

    # Mode : checker_linux
    elif [[ "$MODE" == "checker_linux" ]]; then
        CHECKER_LINUX_RESULT=$(echo "$MOVES" | ./checker_linux $ARG)
        if [[ "$CHECKER_LINUX_RESULT" == "OK" ]]; then
            SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
            printf "${GREEN}Test %3d/%d: OK (Checker_linux) - %6d moves${NC}\n" "$i" "$NUM_TESTS" "$MOVE_COUNT"
        else
            FAIL_COUNT=$((FAIL_COUNT + 1))
            printf "${RED}Test %3d/%d: KO (Checker_linux) - %6d moves${NC}\n" "$i" "$NUM_TESTS" "$MOVE_COUNT"
            echo -e "$ARG\n\n\n" >> $FAILED_ARGS_FILE
        fi

    # Mode : both (compare les deux checkers)
    elif [[ "$MODE" == "both" ]]; then
        CHECKER_RESULT=$(echo "$MOVES" | ./checker $ARG)
        CHECKER_LINUX_RESULT=$(echo "$MOVES" | ./checker_linux $ARG)

        if [[ "$CHECKER_RESULT" == "$CHECKER_LINUX_RESULT" ]]; then
            if [[ "$CHECKER_RESULT" == "OK" ]]; then
                SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
                printf "${GREEN}Test %3d/%d: OK (Both Checkers) - %6d moves${NC}\n" "$i" "$NUM_TESTS" "$MOVE_COUNT"
            else
                FAIL_COUNT=$((FAIL_COUNT + 1))
                printf "${RED}Test %3d/%d: KO (Both Checkers) - %6d moves${NC}\n" "$i" "$NUM_TESTS" "$MOVE_COUNT"
                echo -e "$ARG\n\n\n" >> $FAILED_ARGS_FILE
            fi
        else
            FAIL_COUNT=$((FAIL_COUNT + 1))
            printf "${RED}Test %3d/%d: ERROR (Checker Mismatch)${NC}\n" "$i" "$NUM_TESTS"
            echo -e "$ARG\n\n\n" >> $FAILED_ARGS_FILE
            echo "Checker: $CHECKER_RESULT, Checker_linux: $CHECKER_LINUX_RESULT" >> $OUTPUT_FILE
        fi
    fi
done

# Calculer la moyenne des coups
AVERAGE=$(echo "scale=2; $TOTAL_MOVES / $NUM_TESTS" | bc)

# Résumé des résultats
printf "\n${YELLOW}Summary:${NC}\n"
printf "Number of tests: %s\n" "$NUM_TESTS"
printf "${GREEN}Successful tests (OK): %s${NC}\n" "$SUCCESS_COUNT"
printf "${RED}Failed tests (KO): %s${NC}\n" "$FAIL_COUNT"
printf "${YELLOW}Average moves: %.2f${NC}\n" "$AVERAGE"

# Écrire le résumé dans un fichier
echo "Summary:" >> $OUTPUT_FILE
echo "Number of tests: $NUM_TESTS" >> $OUTPUT_FILE
echo "Successful tests (OK): $SUCCESS_COUNT" >> $OUTPUT_FILE
echo "Failed tests (KO): $FAIL_COUNT" >> $OUTPUT_FILE
echo "Average moves: $AVERAGE" >> $OUTPUT_FILE

if [[ $FAIL_COUNT -ne 0 ]]; then
    echo -e "${RED}Failed arguments have been saved in $FAILED_ARGS_FILE${NC}"
else
    echo -e "${GREEN}All tests passed successfully!${NC}"
fi