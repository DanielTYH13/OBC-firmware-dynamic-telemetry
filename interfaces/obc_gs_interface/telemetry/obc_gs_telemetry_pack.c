#include "obc_gs_telemetry_pack.h"
#include "obc_gs_telemetry_data.h"
#include "obc_gs_telemetry_id.h"
#include "data_pack_utils.h"
#include "obc_gs_errors.h"

#include <stddef.h>
#include <stdint.h>

/* Declare all pack functions for telemetry data */
static void packObcTemp(const telemetry_data_t *data, uint8_t *buffer, uint32_t *offset);
static void packObcState(const telemetry_data_t *data, uint8_t *buffer, uint32_t *offset);
static void packPong(const telemetry_data_t *data, uint8_t *buffer, uint32_t *offset);

typedef void (*telemetry_pack_func_t)(const telemetry_data_t *, uint8_t *, uint32_t *);

static const telemetry_pack_func_t telemPackFns[] = {
    [TELEM_OBC_TEMP] = packObcTemp,
    [TELEM_OBC_STATE] = packObcState,
    [TELEM_PONG] = packPong,
};

obc_gs_error_code_t packTelemetry(const telemetry_data_t *telemData, const telemetry_header_t *headerData, uint8_t *buffer, size_t len, uint32_t *numPacked) {
  if (data == NULL || buffer == NULL || numPacked == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  if (len < MAX_TELEMETRY_DATA_SIZE + MAX_TELEMETRY_DATA_SIZE) {
    return OBC_GS_ERR_CODE_BUFF_TOO_SMALL;
  }

  if (telemPackFns[data->id] == NULL) {
    return OBC_GS_ERR_CODE_INVALID_ARG;
  }

  uint32_t offset = 0;  
 
  // Header start

  packUint8(telemData->id, buffer, &offset); // Pack the telemetry ID

  packUint8(headerData->length, buffer, &offset); // Pack the length

  packUint8(headerData->sequence, buffer, &offset); // Pack the sequence

  // Header end

  // Telemetry start

  packUint32(telemData->timestamp, buffer, &offset);  // Pack the timestamp

  telemPackFns[telemData->id](data, buffer, &offset); // Pack the telemetry parameters

  // Telemetry end

  *numPacked = offset;

  return OBC_GS_ERR_CODE_SUCCESS;
}

static void packObcTemp(const telemetry_data_t *data, uint8_t *buffer, uint32_t *offset) {
  packFloat(data->obcTemp, buffer, offset);
}

static void packObcState(const telemetry_data_t *data, uint8_t *buffer, uint32_t *offset) {
  packUint8(data->obcState, buffer, offset);
}

static void packPong(const telemetry_data_t *data, uint8_t *buffer, uint32_t *offset) {
  // Nothing to pack
}
