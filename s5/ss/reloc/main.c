#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_RECORD_SIZE 10
#define MAX_BITMASK_SIZE 12
#define MAX_PROGRAM_NAME_SIZE 6
#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

typedef struct {
    FILE *input_file;
    FILE *output_file;
    int program_start_address;
} RelocationState;

bool initialize_relocation(RelocationState *relocation_state);
void cleanup_relocation(RelocationState *relocation_state);
bool process_object_file(RelocationState *relocation_state);
bool process_header_record(FILE *input_file);
bool process_text_record(RelocationState *relocation_state);
void relocate_and_output_instruction(RelocationState *relocation_state, int current_address, int instruction_opcode, int instruction_operand, char relocation_bit);

int main(void) {
    RelocationState relocation_state = {0};
    
    if (!initialize_relocation(&relocation_state)) {
        cleanup_relocation(&relocation_state);
        return EXIT_FAILURE;
    }

    if (!process_object_file(&relocation_state)) {
        cleanup_relocation(&relocation_state);
        return EXIT_FAILURE;
    }

    cleanup_relocation(&relocation_state);
    return EXIT_SUCCESS;
}

bool initialize_relocation(RelocationState *relocation_state) {
    printf("Enter the program's starting address: ");
    if (scanf("%d", &relocation_state->program_start_address) != 1) {
        fprintf(stderr, "Error: Invalid input for program starting address.\n");
        return false;
    }

    relocation_state->input_file = fopen(INPUT_FILENAME, "r");
    if (!relocation_state->input_file) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return false;
    }

    relocation_state->output_file = fopen(OUTPUT_FILENAME, "w");
    if (!relocation_state->output_file) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        return false;
    }

    return true;
}

void cleanup_relocation(RelocationState *relocation_state) {
    if (relocation_state->input_file) fclose(relocation_state->input_file);
    if (relocation_state->output_file) fclose(relocation_state->output_file);
}

bool process_object_file(RelocationState *relocation_state) {
    char record_type[MAX_RECORD_SIZE];

    while (fscanf(relocation_state->input_file, "%s", record_type) == 1 && strcmp(record_type, "E") != 0) {
        if (strcmp(record_type, "H") == 0) {
            if (!process_header_record(relocation_state->input_file)) return false;
        } else if (strcmp(record_type, "T") == 0) {
            if (!process_text_record(relocation_state)) return false;
        } else {
            fprintf(stderr, "Error: Unknown record type '%s'\n", record_type);
            return false;
        }
    }

    return true;
}

bool process_header_record(FILE *input_file) {
    char program_name[MAX_PROGRAM_NAME_SIZE], program_size[MAX_RECORD_SIZE];
    if (fscanf(input_file, "%s %s", program_name, program_size) != 2) {
        fprintf(stderr, "Error: Invalid header record format\n");
        return false;
    }
    return true;
}

bool process_text_record(RelocationState *relocation_state) {
    int text_start_address, instruction_opcode, instruction_operand;
    char relocation_bitmask[MAX_BITMASK_SIZE];

    if (fscanf(relocation_state->input_file, "%d %s", &text_start_address, relocation_bitmask) != 2) {
        fprintf(stderr, "Error: Invalid text record format\n");
        return false;
    }

    text_start_address += relocation_state->program_start_address;

    for (size_t i = 0; i < strlen(relocation_bitmask); i++) {
        if (fscanf(relocation_state->input_file, "%d %d", &instruction_opcode, &instruction_operand) != 2) {
            fprintf(stderr, "Error: Invalid instruction format\n");
            return false;
        }
        relocate_and_output_instruction(relocation_state, text_start_address, instruction_opcode, instruction_operand, relocation_bitmask[i]);
        text_start_address += 3;  // Assuming 3-byte instructions
    }

    return true;
}

void relocate_and_output_instruction(RelocationState *relocation_state, int current_address, int instruction_opcode, int instruction_operand, char relocation_bit) {
    int relocated_operand = (relocation_bit == '1') ? instruction_operand + relocation_state->program_start_address : instruction_operand;
    fprintf(relocation_state->output_file, "%d\t%d%d\n", current_address, instruction_opcode, relocated_operand);
    printf("%d\t%d%d\n", current_address, instruction_opcode, relocated_operand);
}