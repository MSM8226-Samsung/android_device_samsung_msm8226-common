# Camera
BOARD_CAMERA_SENSORS := s5k4h5_8196 imx175 # Dont know if s5k4h5_8226 exists
BOARD_GLOBAL_CFLAGS += -DCAMERA_VENDOR_L_COMPAT # Do we really need this???

#TARGET_NEEDS_PLATFORM_TEXT_RELOCATIONS := true
TARGET_USE_VENDOR_CAMERA_EXT := true # Dont know what this does but everyone else uses it :)
TARGET_HAS_LEGACY_CAMERA_HAL1 := true
