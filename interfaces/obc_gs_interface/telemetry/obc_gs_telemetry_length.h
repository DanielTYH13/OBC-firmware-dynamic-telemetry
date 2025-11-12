#pragma once

typedef enum {
  /* Used to indicate that the telemetry data is invalid.
     It should not have a pack function. */
  TELEM_NONE = 0,

  // Temperature values
  TELEM_CC1120_TEMP = sizeof(float),
  TELEM_COMMS_CUSTOM_TRANSCEIVER_TEMP = sizeof(float),
  TELEM_OBC_TEMP = sizeof(float), 
  TELEM_ADCS_MAG_BOARD_TEMP = sizeof(float),
  TELEM_ADCS_SENSOR_BOARD_TEMP = sizeof(float),
  TELEM_EPS_BOARD_TEMP = sizeof(float),
  TELEM_SOLAR_PANEL_1_TEMP = sizeof(float),
  TELEM_SOLAR_PANEL_2_TEMP = sizeof(float),
  TELEM_SOLAR_PANEL_3_TEMP = sizeof(float),
  TELEM_SOLAR_PANEL_4_TEMP = sizeof(float),

  // Current values
  TELEM_EPS_COMMS_5V_CURRENT = sizeof(float),
  TELEM_EPS_COMMS_3V3_CURRENT = sizeof(float),
  TELEM_EPS_MAGNETORQUER_8V_CURRENT = sizeof(float),
  TELEM_EPS_ADCS_5V_CURRENT = sizeof(float),
  TELEM_EPS_ADCS_3V3_CURRENT = sizeof(float),
  TELEM_EPS_OBC_3V3_CURRENT = sizeof(float),

  // Voltage values
  TELEM_EPS_COMMS_5V_VOLTAGE = sizeof(float),
  TELEM_EPS_COMMS_3V3_VOLTAGE = sizeof(float),
  TELEM_EPS_MAGNETORQUER_8V_VOLTAGE = sizeof(float),
  TELEM_EPS_ADCS_5V_VOLTAGE = sizeof(float),
  TELEM_EPS_ADCS_3V3_VOLTAGE = sizeof(float),
  TELEM_EPS_OBC_3V3_VOLTAGE = sizeof(float),

  TELEM_OBC_STATE = sizeof(uint8_t),
  TELEM_EPS_STATE = sizeof(uint8_t),

  TELEM_NUM_CSP_PACKETS_RCVD = sizeof(uint32_t),
} telemetry_data_length_t;
