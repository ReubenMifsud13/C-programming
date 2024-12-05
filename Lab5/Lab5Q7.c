#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//union for IPv4
union IPv4{
    uint32_t address;
    uint8_t octets[4];
};

int main(){
    union IPv4 ip;
    char userInput[16]; //stores the user's address

    for(;;){
        printf("Insert your IPv4 address in octet format (including '.'): ex. 192.5.12.256\n");
        fgets(userInput, 16, stdin);

        //checking for invalid input
        if(sscanf(userInput, "%hhu.%hhu.%hhu.%hhu", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]) != 4){
            printf("Invalid format of input\n");
            continue;
        }
        break; //when input is correct, exit loop
    }

    printf("\nIPv4 in octet form: %u.%u.%u.%u", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);
    printf("\nIPv4 in hex form: 0x%08X\n", ip.address);
}