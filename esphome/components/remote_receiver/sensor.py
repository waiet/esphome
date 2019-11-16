import esphome.codegen as cg
from esphome.components import remote_base
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_HUMIDITY, CONF_ID, CONF_MODEL, CONF_PIN, CONF_TEMPERATURE, \
    ICON_THERMOMETER, UNIT_CELSIUS, ICON_WATER_PERCENT, UNIT_PERCENT

DEPENDENCIES = ['remote_receiver']

CONFIG_SCHEMA = remote_base.validate_sensor

def to_code(config):
    var = yield remote_base.build_sensor(config)
    yield cg.register_component(var, config)

    if CONF_TEMPERATURE in config:
        sens = yield sensor.new_sensor(config[CONF_TEMPERATURE])
        cg.add(var.set_temperature_sensor(sens))
    if CONF_HUMIDITY in config:
        sens = yield sensor.new_sensor(config[CONF_HUMIDITY])
        cg.add(var.set_humidity_sensor(sens))

