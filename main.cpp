/* mbed Microcontroller Library
 * Copyright (c) 2016 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Here's an example using the MX25R SPI flash device on the K82F
#include "mbed.h"
#include "SPIFBlockDevice.h"

/* This configuration of the SPI Flash Driver pins is for
 * the the SPI pins on the Arduino header to the SPI NOR part.
 */
SPIFBlockDevice spif(D11, D12, D13, D10);


int main() {
    printf("spif test\n");

    // Initialize the SPI flash device and print the memory layout
    spif.init();
    printf("spif size: %llu\n",         spif.size());
    printf("spif read size: %llu\n",    spif.get_read_size());
    printf("spif program size: %llu\n", spif.get_program_size());
    printf("spif erase size: %llu\n",   spif.get_erase_size());

    // Write "Hello World!" to the first block
    char *buffer = (char*) malloc(spif.get_erase_size());
    sprintf(buffer, "Hello World!\n");
    spif.erase(0, spif.get_erase_size());
    spif.program(buffer, 0, spif.get_erase_size());

    // Read back what was stored
    spif.read(buffer, 0, spif.get_erase_size());
    printf("%s", buffer);

    // Deinitialize the device
    spif.deinit();
}
