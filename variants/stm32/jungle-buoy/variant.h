#ifndef _VARIANT_JUNGLE_BUOY_
#define _VARIANT_JUNGLE_BUOY_

#define USE_STM32WLx

// I/O
#define LED_POWER PA15 // Green LED
#define LED_STATE_ON 1
#define BUTTON_PIN PH3 // Shared with BOOT0
#define BUTTON_NEED_PULLUP

// TP4057 charger status (open-drain, active-low)
#define EXT_CHRG_DETECT PA0 // CHRG
#define EXT_CHRG_DETECT_MODE INPUT_PULLUP
#define EXT_PWR_DETECT PB5 // DONE/STDBY
#define EXT_PWR_DETECT_MODE INPUT_PULLUP

#define BATTERY_PIN PB2
#define ADC_MULTIPLIER 1.51 // 100k/200k divider, worst-case 1% tolerance
#define ADC_CTRL PB4
#define ADC_CTRL_ENABLED LOW  // LOW grounds the divider
#define ADC_CTRL_SETTLE_MS 40 // 100nF filter cap settle time
// PB3 (solar voltage divider, shares ADC_CTRL above): no Meshtastic support yet

// Bosch Sensortec BME280 (DNP by default)
#define HAS_SENSOR 1
#define PIN_WIRE_SDA PA11
#define PIN_WIRE_SCL PA12

// Serial1 must exist even though PB6/PB7 are unused (GPS.cpp/SerialModule.cpp
// reference it unconditionally)
#define ENABLE_HWSERIAL1
#define PIN_SERIAL1_RX PB6
#define PIN_SERIAL1_TX PB7

// Debug serial (USART2)
#define ENABLE_HWSERIAL2
#define PIN_SERIAL2_TX PA2
#define PIN_SERIAL2_RX PA3

// LoRa
/*
 * RAK3172   (-20-85°C) -> No TCXO
 * RAK3172-T (-40-85°C) -> 3.0V TCXO
 * https://github.com/RAKWireless/RAK-STM32-RUI/blob/e5a28be8fab1a492bd9223dd425ca33a8a297d90/variants/WisDuo_RAK3172-T_Board/radio_conf.h#L91
 */
#define TCXO_OPTIONAL
#define SX126X_DIO3_TCXO_VOLTAGE 3.0

// Required to avoid Serial1 conflicts due to board definition here:
// https://github.com/stm32duino/Arduino_Core_STM32/blob/main/variants/STM32WLxx/WL54CCU_WL55CCU_WLE4C(8-B-C)U_WLE5C(8-B-C)U/variant_RAK3172_MODULE.h
#define RAK3172

#define HAS_LSE 1
#define STM32WL_LSE_DRIVE RCC_LSEDRIVE_LOW

#endif
