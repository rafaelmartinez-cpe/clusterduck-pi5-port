# ClusterDuck Protocol on Raspberry Pi 5 (Project EAGLE)

This is our Cal Poly SLO senior capstone. Our team of 5 took the [ClusterDuck Protocol](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol) (CDP), an open source LoRa mesh network for disaster response, and got it running on Raspberry Pi 5s with Linux instead of ESP32 boards. The project was sponsored by OWL Integrations.

This repo is a copy of our final code from the CDP 5.0 branch. I removed the git history, build files, and the AWS keys before putting it up. The CDP code and license (Apache 2.0) belong to the CDP project. Our changes were not merged into the official repo.

## What we changed

- Got MamaDuck and PapaDuck running on a Pi 5 with a Waveshare SX1262 LoRa/GNSS HAT
- Swapped the ESP32 radio code for RadioLib using a Pi hardware layer (lgpio)
- Replaced or removed Arduino only code like Update.h, MemoryFree, and the timers so it builds with g++
- PapaDuck sends the packets it receives as JSON over MQTT (TLS) to OWL's device management system

## Building it

You need g++ (C++17), RadioLib installed to /usr/local, lgpio, and the Eclipse Paho C++ MQTT library.

```bash
cp src/include/secrets.example.h src/include/secrets.h   # add your own AWS IoT info
cd src
make    # builds MamaDuck
```

Pins we used (BCM): CS 21, DIO1 16, RST 18, BUSY 20, TXEN 6

## What I worked on

My roles on the team were the Linux port, system bring up, and documentation. Everyone helped on the final product but these are the parts I was most involved in:

- The Linux build. I was SSH'd into the Pi working on the Makefile and compiler flags, linking RadioLib, lgpio, and pthread, and fixing the build errors from missing headers and Arduino/ESP32 only files.
- Getting the code building and running on our Pi 5 test units.
- Testing. I co-owned the verification test for the backend packet logic, which included checking the 27 byte packet header (8 byte source ID, 8 byte destination ID, 4 byte message ID, topic, duck type, hop count, and a 4 byte CRC).
- Documentation for the project charter, reports, and final presentation.

My teammates handled the RadioLib install, the board setup, the GPS, and the cloud side.

The original commits were all made from a shared team account, so the git history wouldn't show who did what anyway.

## Team

Blake Stewart, Hayden Buscher, Matthew Vang, Mathew Yen, and Rafael Martinez

Original CDP readme: [docs/UPSTREAM_README.md](docs/UPSTREAM_README.md)
