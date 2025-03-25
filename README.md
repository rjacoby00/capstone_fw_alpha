# CPE-450 Capstone [`hw-alpha`](https://github.com/Yexall/CPE-450.Capstone/tree/main/Hardware/hw_alpha) bringup and hardware validation firmware

This firmware is meant to develop zephyr board port of
[custom hardware](https://github.com/Yexall/CPE-450.Capstone/tree/main/Hardware/hw_alpha)
and provide a framework to turn on all hardware peripherals and develop any
needed custom drivers.

## Building

Make sure you have Zephyr installed: 
[Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html).

Follow through the end of "Get Zephyr and install Python dependencies"

To initialize the workspace and install dependancies, run the following:

```shell
west init -m https://github.com/rjacoby00/capstone_fw_alpha --mr main capstone_fw
cd capstone_fw
west update
```

*Note:* `west.yml` will prevent any unnecessary dependanceis from being pulled
with the Zephyr SDK.

`capstone_fw` will contain the Zephyr source and other required dependances;
this project will be pulled into `capstone_fw/fw_alpha`, following the 
[T2 topology](https://docs.zephyrproject.org/latest/develop/west/workspaces.html#west-t2).

To build, run the following:

```shell
cd fw_alpha
west build -p always -b hw_alpha app
```

Build artifacts are placed under `build/`. Install `build/zephyr/zephyr.bin`
using JTAG programer; automated script using `west flash` WIP.
