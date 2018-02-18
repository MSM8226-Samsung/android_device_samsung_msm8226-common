# Basic dexpreopt
ifeq ($(HOST_OS),linux)
      #We need this otherwise WIFI causes a bootloop on each connect!
      WITH_DEXPREOPT := true

endif
