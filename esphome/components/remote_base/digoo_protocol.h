#pragma once

#include "esphome/core/component.h"
#include "remote_base.h"

namespace esphome {
namespace remote_base {


struct DigooData {
    uint8_t address;
    uint8_t command;

};

class DigooProtocol : public RemoteProtocol<DigooData> {
 public:
  virtual optional<DigooData> decode(RemoteReceiveData src) override;
  void dump(const DigooData &data) override;

  void set_temperature_sensor(sensor::Sensor *temperature_sensor) { temperature_sensor_ = temperature_sensor; }
  void set_humidity_sensor(sensor::Sensor *humidity_sensor) { humidity_sensor_ = humidity_sensor; }



 protected:

  sensor::Sensor *temperature_sensor_{nullptr};
  sensor::Sensor *humidity_sensor_{nullptr};
};

DECLARE_REMOTE_PROTOCOL(Digoo)


}  // namespace remote_base
}  // namespace esphome
