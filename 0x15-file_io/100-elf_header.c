#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void display_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                              ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("Data:                               ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("Version:                            %d (current)\n", header->e_ident[EI_VERSION]);
    printf("OS/ABI:                             ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Sun Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("IBM AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("SGI Irix\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("Compaq TRU64 UNIX\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Novell Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("ABI Version:                        %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                               ");
    switch (header->e_type) {
        case ET_NONE:
            printf("NONE (Unknown type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("Entry point address:                0x%llx\n", (unsigned long long)header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    char *elf_filename = argv[1];
    int fd = open(elf_filename, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error: Could not open ELF file %s\n", elf_filename);
        return 98;
    }

    Elf64_Ehdr header;
    ssize_t n = read(fd, &header, sizeof(header));
    
    if (n == -1 || n != sizeof(header) || memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: %s is not an ELF file\n", elf_filename);
        close(fd);
        return 98;
    }

    display_elf_header_info(&header);

    close(fd);
    return 0;
}

