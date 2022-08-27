# test_light
Testing my ability to run minimal Beaglebone code using Rust


# Compile Instructions 

```make
  make
```


# Run Instructions



## blinkExternalLED.c

### For Beagle Bone AI

```sh
echo stop > /sys/class/remoteproc/remoteproc5/state # Stop 1st PRU 2nd Core
cp blinkExternalLED.pru1_1.out /lib/firmware/am57xx-pru1_1-fw 
echo am57xx-pru1_1-fw > /sys/class/remoteproc/remoteproc5/firmware # Make sure firmware is found (PRU searches for this name)
echo start > /sys/class/remoteproc/remoteproc5/state # Start 1st PRU 2nd Core
dmesg -Hw  # Confirm that it says a pru is up
```

Note: there is a requirement to use the `resource_table_empty.h` file so that the remoteproc probe can function correctly, but is serves no other purpose
