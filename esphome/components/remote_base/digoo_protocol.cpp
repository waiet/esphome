#include "digoo_protocol.h"
#include "esphome/core/log.h"

namespace esphome {
namespace remote_base {

static const char *TAG = "remote.digoo";

static const uint32_t HEADER_HIGH_US = 3502;
static const uint32_t HEADER_LOW_US = 1750;
static const uint32_t BIT_HIGH_US = 502;
static const uint32_t BIT_ZERO_LOW_US = 400;
static const uint32_t BIT_ONE_LOW_US = 1244;


optional<DigooData> DigooProtocol::decode(RemoteReceiveData src ) {
    *humidity = NAN;
    *temperature = NAN;
    DigooData out{
            .address = 0,
            .command = 0,
    };
    ESP_LOGD(TAG, "Received Digoo: decode");


//TODO getting packet from src
//    uint64_t packetpaket =

    float temperature, humidity;

//    int16_t t = packet >> 12 & 0x0FFF;
//    t = 0x0800 & t ? 0xF000 | t  : t;
//    temperature = float(t) / 10;
//    humidity =  out_data & 0xFF;

    this->temperature_sensor_->publish_state(temperature);
    this->humidity_sensor_->publish_state(humidity);

    return out;
}

void DigooProtocol::dump(const DigooData &data) {
  ESP_LOGD(TAG, "Received Panasonic: address=0x%04X, command=0x%08X", data.address, data.command);
}

}  // namespace remote_base
}  // namespace esphome
