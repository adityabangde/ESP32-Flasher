# ESP32 Flasher

This repository provides a sample code implementation for flashing firmware from one ESP32 (master) to another ESP32 (target). It includes a detailed implementation of the firmware uploading process using SPIFFS and a custom flasher class. The provided `.ino` file demonstrates the essential wiring and flashing workflow, along with the key functions needed to test and execute the firmware upload.

---

## How It Works

### Master and Target Wiring
To set up the connections between the master and target ESP32 devices:

| **Master ESP32 Pin** | **Target ESP32 Pin** |
|-----------------------|----------------------|
| RX2 (GPIO 16)         | TX0                 |
| TX2 (GPIO 17)         | RX0                 |
| GND                   | GND                 |
| VIN                   | VIN                 |
| GPIO 25               | GPIO 0 (BOOT)       |
| GPIO 26               | EN                  |

Ensure all connections are secure before proceeding.

---

### Key Functions in the `master_code.ino`

1. **`setup()`**  
   This function initializes the master ESP32 and starts the firmware upload process:
   - Begins Serial communication for monitoring the process.
   - Initializes SPIFFS to access the firmware binary file (`firmware.bin`).
   - Sets up the flasher class (`ESP32Flasher`) and attempts to connect to the target ESP32.
   - Initiates the flashing of the firmware stored in SPIFFS to the target ESP32.

2. **`espFlasher::espFlasherInit()`**  
   Configures the master ESP32 to communicate with the target ESP32:
   - Sets up Serial communication using `Serial2`.
   - Configures GPIO pins to control the target ESP32 (GPIO 25 for BOOT and GPIO 26 for EN).

3. **`espFlasher::espFlashBinFile(const char* bin_file_name)`**  
   Handles the flashing process:
   - Locates the binary firmware file (`firmware.bin`) in the SPIFFS.
   - Verifies the file size and starts the flashing process using the `flashBinary()` function.
   - Ensures the target ESP32 is reset after successful flashing.

---

## How to Use

1. **Prepare the Firmware:**
   - Compile your test firmware code and generate the `.bin` file.
   - Copy the `.bin` file into the `data` folder of the master ESP32's code directory.

2. **Upload the Binary to SPIFFS:**
   - Use the **ESP32 File System Uploader** to upload the `.bin` file to the master ESP32's SPIFFS. 
   - If the tool is not available, follow the installation guide [here](https://github.com/me-no-dev/arduino-esp32fs-plugin).

3. **Connect the Master and Target ESP32 Devices:**
   - Wire the devices as specified in the wiring table above.

4. **Run the Master Code:**
   - Upload the `master_code.ino` to the master ESP32.
   - Monitor the Serial output to ensure the firmware is flashed successfully.

---

This repository demonstrates a straightforward approach for ESP32-to-ESP32 firmware flashing, making it ideal for testing and development purposes.
