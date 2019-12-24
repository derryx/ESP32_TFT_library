idf_component_register(SRCS "tft_demo.c"
                    INCLUDE_DIRS "."
                    )

#spiffs_create_partition_image(storage ../components/spiffs_image/image/images FLASH_IN_PROJECT)                    