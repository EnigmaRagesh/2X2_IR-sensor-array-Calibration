// Auto-generated. Do not edit!

// (in-package pixart_localization.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class measured_point {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stamp = null;
      this.led_id = null;
      this.led_status = null;
      this.camera_id = null;
      this.point_id = null;
      this.x = null;
      this.y = null;
      this.z = null;
    }
    else {
      if (initObj.hasOwnProperty('stamp')) {
        this.stamp = initObj.stamp
      }
      else {
        this.stamp = [];
      }
      if (initObj.hasOwnProperty('led_id')) {
        this.led_id = initObj.led_id
      }
      else {
        this.led_id = [];
      }
      if (initObj.hasOwnProperty('led_status')) {
        this.led_status = initObj.led_status
      }
      else {
        this.led_status = [];
      }
      if (initObj.hasOwnProperty('camera_id')) {
        this.camera_id = initObj.camera_id
      }
      else {
        this.camera_id = [];
      }
      if (initObj.hasOwnProperty('point_id')) {
        this.point_id = initObj.point_id
      }
      else {
        this.point_id = [];
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = [];
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = [];
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type measured_point
    // Serialize message field [stamp]
    bufferOffset = _arraySerializer.time(obj.stamp, buffer, bufferOffset, null);
    // Serialize message field [led_id]
    bufferOffset = _arraySerializer.int16(obj.led_id, buffer, bufferOffset, null);
    // Serialize message field [led_status]
    bufferOffset = _arraySerializer.bool(obj.led_status, buffer, bufferOffset, null);
    // Serialize message field [camera_id]
    bufferOffset = _arraySerializer.int16(obj.camera_id, buffer, bufferOffset, null);
    // Serialize message field [point_id]
    bufferOffset = _arraySerializer.int16(obj.point_id, buffer, bufferOffset, null);
    // Serialize message field [x]
    bufferOffset = _arraySerializer.float64(obj.x, buffer, bufferOffset, null);
    // Serialize message field [y]
    bufferOffset = _arraySerializer.float64(obj.y, buffer, bufferOffset, null);
    // Serialize message field [z]
    bufferOffset = _arraySerializer.float64(obj.z, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type measured_point
    let len;
    let data = new measured_point(null);
    // Deserialize message field [stamp]
    data.stamp = _arrayDeserializer.time(buffer, bufferOffset, null)
    // Deserialize message field [led_id]
    data.led_id = _arrayDeserializer.int16(buffer, bufferOffset, null)
    // Deserialize message field [led_status]
    data.led_status = _arrayDeserializer.bool(buffer, bufferOffset, null)
    // Deserialize message field [camera_id]
    data.camera_id = _arrayDeserializer.int16(buffer, bufferOffset, null)
    // Deserialize message field [point_id]
    data.point_id = _arrayDeserializer.int16(buffer, bufferOffset, null)
    // Deserialize message field [x]
    data.x = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [y]
    data.y = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [z]
    data.z = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.stamp.length;
    length += 2 * object.led_id.length;
    length += object.led_status.length;
    length += 2 * object.camera_id.length;
    length += 2 * object.point_id.length;
    length += 8 * object.x.length;
    length += 8 * object.y.length;
    length += 8 * object.z.length;
    return length + 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pixart_localization/measured_point';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '524275614c80c3a624912649e8f61f71';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    time[] stamp
    int16[]  led_id
    bool[] led_status
    int16[]  camera_id
    int16[]  point_id
    float64[] x
    float64[] y
    float64[] z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new measured_point(null);
    if (msg.stamp !== undefined) {
      resolved.stamp = msg.stamp;
    }
    else {
      resolved.stamp = []
    }

    if (msg.led_id !== undefined) {
      resolved.led_id = msg.led_id;
    }
    else {
      resolved.led_id = []
    }

    if (msg.led_status !== undefined) {
      resolved.led_status = msg.led_status;
    }
    else {
      resolved.led_status = []
    }

    if (msg.camera_id !== undefined) {
      resolved.camera_id = msg.camera_id;
    }
    else {
      resolved.camera_id = []
    }

    if (msg.point_id !== undefined) {
      resolved.point_id = msg.point_id;
    }
    else {
      resolved.point_id = []
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = []
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = []
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = []
    }

    return resolved;
    }
};

module.exports = measured_point;
