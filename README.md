## Getting Started With The mbed-os Example for the SPI Flash Block Device 

This is the mbed-os example for the SPIFBlockDevice driver. 
See the [spiflash-driver](https://github.com/armmbed/spiflash-driver) repository for more information.

This guide outlines the steps to get a SPI NOR flash part working on an mbed OS platform.

Please install [mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## Hardware Requirements

This example can be used on an mbedos platform with a SPI NOR part connected to the SPI pins (on the Arduino header, for example).

This document uses the K64F as an example. Simply change the relevant options (e.g. -m K64F) to be appropriate for your target.

## Create the Example Application

From the command-line, import the example:

```
mbed import mbed-os-example-spiflash-driver
```

You should see: 

	[mbed] Importing program "mbed-os-example-spiflash-driver" from "https://github.com/ARMmbed/mbed-os-example-spiflash-driver" at latest revision in the current branch
	[mbed] Adding library "mbed-os" from "https://github.com/ARMmbed/mbed-os" at rev #f4864dc6429e

Move into the newly created directory:

```
cd mbed-os-example-spiflash-driver
```
	
If the mbed-os library was not automatically added (see trace above), do the following to import mbed-os:

```
mbed new .
```

Add the spiflash-driver repository: 

```
mbed add spiflash-driver
```

## Build the Example

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`). For example, for the GCC_ARM toolchain:

```
mbed compile -m K64F -t GCC_ARM
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

	[snip]
	todo: paste snippet here
	
## <a name="run-the-example-binary-on-the-k64f"></a> Run the Example Binary on the K64F 

Copy the binary from `<root_dir>/mbed-os-example-spiflash-driver/BUILD/K64F/GCC_ARM/main.bin` to the K64F:

1. Connect your mbed device to the computer over USB.
1. Copy the binary file to the mbed device.
1. Press the reset button to start the program.
1. Open the UART of the board in your favorite UART viewing program. For example, `screen /dev/ttyACM0`.

After connecting a serial console and resetting the target, the following trace should be seen:

	spif test
	spif size: 2097152
	spif read size: 1
	spif program size: 1
	spif erase size: 4096
	Hello World!


# Troubleshooting

1. Make sure `mbed-cli` is working correctly and its version is newer than `1.0.0`.

 ```
 mbed --version
 ```

 If not, update it:

 ```
 pip install mbed-cli --upgrade
 ```
 
