# vendor_qcom_camera

NOTE CHECKOUT AT 9503f77d4b29a20ffc80b8726ee7fd45a9935772 then use the parm_buffer and capability from b9a9b63f78999ea72aafecb5ad5f72b6b6f8f47a

Tooks used for decompiling / reverse engineering:
- Ghidra
- IDA PRO (free edition)

QCOM Camera HAL for Samsung qcom powered devices

This repo holds the semi-working version of a Qcom HAL (this is not working just for development purposes and how the overall Qcom camera system works)
Its primary for the S3Neo but should theoretically work for the msm8226 and msm8974 family.

Current state:
- sets up every parameters from server
- full m_pCapability (querycap) functionality
- parm_buffer_t matches samsung size (parm_type_t filles with int array to match samsung size)
- camera_open is modified to match samsung standarts
- initdefaultparameters() is modified as samsung doesnt use the parameters from server but hardcode them inside the HALs private Qcamera::Parameters class
- start_preview initializes correctly but fails at VIDIOC_STREAMON (buffer size may mismatch)


To-Do list:
- edit the QcameraHWI functions, they have some magic in them
- decompile the structs mm-camera-intf is using
- fix the server calls to kernel (our buffer is too large)
- get the full kernel IOCTL list the server is using including the I2C write arrays

Next Milestone:
- create mm-camera-intf which works with stock HAL so we can read the actual IOCTL's passing through it.
